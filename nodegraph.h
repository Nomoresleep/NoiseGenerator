#include <math.h> // fmodf
#include "MCommon/MC_GrowingArray.h"
#include "MCommon/MC_ScopedPtr.h"
#include "MCommon/MC_Vector.h"
#include "MCommon/MC_HashMap.h"
#include "MCommon/MC_Pair.h"
#include "imgui.h"
#include "node.h"
#include "image_subpass.h"

template <typename Type>
class ConstantNode : public Node
{
public:
    ConstantNode(int id, const char* name, const MC_Vector2f& pos)
        : Node(id, name, pos) {
        AddOutputPort(new OutputPort(GetPortType<Type>()));
    };
};

class ResultNode : public Node
{
public:
    ResultNode()
        : Node(0, "Result", MC_Vector2f(100, 100))
    {
        AddInputPort(new InputPort(FloatPort, nullptr));
    };
};

static OutputPort* g_draggedOutput = nullptr;

static void locDrawBezierCurve(ImDrawList* aDrawList, MC_Vector2f aP0, MC_Vector2f aP1, ImU32 aColor)
{
    static const f32 CURVE_THICKNESS = 2.0f;
    float xdist = MC_Min(50.0f, aP1.x - aP0.x);
    aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, IM_COL32(100, 100, 100, 255), CURVE_THICKNESS + 1.5f);
    aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, aColor, CURVE_THICKNESS);
}

static void locDrawPort(ImDrawList* aDrawList, MC_Vector2f aPortPos, ImU32 aColor)
{
	//aDrawList->AddCircleFilled(aPortPos + NODE_PORT_SIZE * 0.5f, NODE_PORT_SIZE.x * 0.5f, aColor);
	//aDrawList->AddCircle(aPortPos + NODE_PORT_SIZE * 0.5f, NODE_PORT_SIZE.x * 0.5f, IM_COL32(200, 200, 200, 255));
    aDrawList->AddRectFilled(aPortPos, aPortPos + NODE_PORT_SIZE, aColor);
    aDrawList->AddRect(aPortPos, aPortPos + NODE_PORT_SIZE, IM_COL32(200, 200, 200, 255), 0.0f, ImDrawCornerFlags_All, 1.0f);
}

static void locDrawNode(ImDrawList* aDrawList, Node* aNode, MC_Vector2f anOffset)
{
	MC_Vector2f rect_min = anOffset + aNode->myPosition;
	MC_Vector2f rect_max = rect_min + aNode->mySize;
	const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
	MC_Vector2f rect_header_max = rect_min + MC_Vector2f(aNode->mySize.x, headerHeight);

	ImU32 color = IM_COL32(60, 60, 60, 255);
	if (ImGui::IsMouseHoveringRect(rect_min, rect_max))
	{
		color = IM_COL32(80, 80, 80, 255);
	}

	//Node body with outline
	aDrawList->AddRectFilled(rect_min, rect_max, color);
	aDrawList->AddRect(rect_min, rect_max, IM_COL32(100, 100, 100, 255));
	//Node header with outline
	aDrawList->AddRectFilled(rect_min, rect_header_max, IM_COL32(80, 80, 80, 255));
	aDrawList->AddRect(rect_min, rect_header_max, IM_COL32(100, 100, 100, 255));

	ImGui::SetCursorScreenPos(rect_min + NODE_WINDOW_PADDING);
	ImGui::Text("%s", aNode->myLabel);

	//Draw Output ports
	for (i32 slot_idx = 0; slot_idx < aNode->myOutputs.Count(); slot_idx++)
	{
		OutputPort* port = aNode->myOutputs[slot_idx];
		MC_Vector2f portPos = MC_Vector2f(rect_min.x + aNode->mySize.x - NODE_SLOT_RADIUS, rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}

	//Draw Input ports
	for (i32 slot_idx = 0; slot_idx < aNode->myInputs.Count(); slot_idx++)
	{
		InputPort* port = aNode->myInputs[slot_idx];
		MC_Vector2f portPos = MC_Vector2f(rect_min.x - NODE_SLOT_RADIUS, rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}
}


class NodeGraph
{
public:
	NodeGraph()
		: myNodes(32, 32)
	{
		myResultNode = new ResultNode;
		myNodes.Add(myResultNode);
	};

	Node* myResultNode;
	MC_GrowingArray<MC_ScopedPtr<Node>> myNodes;
};

static NodeGraph* theNodeGraph;

struct NodesModule
{
	typedef Node*(*NodeCreationFunction)(const char* aNodeName, const MC_Vector2f& aPosition);

	static Node* Create(const char* aNodeName, const MC_Vector2f& aPosition)
	{
		NodesModule::NodeCreationFunction* func = ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func != nullptr);
		return (*func)(aNodeName, aPosition);
	}
	static MC_HashMap<const char*, NodeCreationFunction> ourRegisteredNodes;
	static MC_GrowingArray<const char*> ourRegisteredNodesNames;
};

MC_HashMap<const char*, NodesModule::NodeCreationFunction> NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NodesModule::ourRegisteredNodesNames(32, 32);

template <typename Type>
struct RegisterNodeType
{
	RegisterNodeType(const char* aNodeName)
	{
		NodesModule::NodeCreationFunction* func = NodesModule::ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func == nullptr);
		NodesModule::ourRegisteredNodes[aNodeName] = Create;
		assert(NodesModule::ourRegisteredNodes.GetIfExists(aNodeName));
		NodesModule::ourRegisteredNodesNames.Add(aNodeName);
	}

	//avoid ugly lamdas!
	static Node* Create(const char* nodeName, const MC_Vector2f& aPosition) { 
		Type* newNode = new Type(theNodeGraph->myNodes.Count(), nodeName, aPosition); 
		theNodeGraph->myNodes.Add(newNode);
		return newNode;
	}
};

static void locRegisterNodeTypes()
{
	RegisterNodeType<ConstantNode<f32>>("FloatConstantNode");
	RegisterNodeType<ConstantNode<i32>>("IntConstantNode");
	RegisterNodeType<ConstantNode<u32>>("UIntConstantNode");
	RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
}

static void ShowNodeGraph(NodeGraph* aNodeGraph)
{
    static MC_Vector2f scrolling = MC_Vector2f(0.0f, 0.0f);
	static bool inited = false;
	if (!inited)
	{
		locRegisterNodeTypes();
		inited = true;
	}
    // Draw a list of nodes on the left side
    bool open_context_menu = false;
    int node_hovered_in_list = -1;
    int node_hovered_in_scene = -1;

    ImGui::BeginGroup();

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, MC_Vector2f(1, 1));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, MC_Vector2f(0, 0));
    ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, IM_COL32(60, 60, 70, 255));
    ImGui::BeginChild("scrolling_region", MC_Vector2f(ImGui::GetWindowContentRegionMax()) - ImGui::GetWindowContentRegionMin(), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
    ImGui::PushItemWidth(NODE_PROPERTY_WIDTH);

	MC_Vector2f offset = MC_Vector2f(ImGui::GetCursorScreenPos()) + scrolling;
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    // Display grid
    ImU32 GRID_COLOR = IM_COL32(200, 200, 200, 40);
    float GRID_SZ = 64.0f;
	MC_Vector2f win_pos = ImGui::GetCursorScreenPos();
	MC_Vector2f canvas_sz = ImGui::GetWindowSize();
    for (float x = fmodf(scrolling.x, GRID_SZ); x < canvas_sz.x; x += GRID_SZ)
        draw_list->AddLine(MC_Vector2f(x, 0.0f) + win_pos, MC_Vector2f(x, canvas_sz.y) + win_pos, GRID_COLOR);
    for (float y = fmodf(scrolling.y, GRID_SZ); y < canvas_sz.y; y += GRID_SZ)
        draw_list->AddLine(MC_Vector2f(0.0f, y) + win_pos, MC_Vector2f(canvas_sz.x, y) + win_pos, GRID_COLOR);
	
	MC_GrowingArray<InputPort*> connections(32, 32);
    bool connection_port_mismatch = false;
    bool connection_port_match = false;

	draw_list->ChannelsSplit(2);

	draw_list->ChannelsSetCurrent(0);
	for(i32 node_idx = aNodeGraph->myNodes.Count() - 1; node_idx >= 0; node_idx--)
	{
		Node* node = aNodeGraph->myNodes[node_idx];
		MC_Vector2f rect_min = offset + node->myPosition;
		ImGui::PushID(node->myID);
		
		//Draw Node properties
		const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
		ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, headerHeight + NODE_WINDOW_PADDING.y));

		for (i32 slot_idx = 0; slot_idx < node->myOutputs.Count(); slot_idx++)
		{
			OutputPort* port = node->myOutputs[slot_idx];
			MC_Vector2f portPos = MC_Vector2f(rect_min.x + node->mySize.x - NODE_SLOT_RADIUS, rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
			ImGui::SetCursorScreenPos(portPos);
			ImGui::InvisibleButton("##output", NODE_PORT_SIZE);
			
			MC_Vector2f buttonCenter = portPos + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
			port->myPosition = buttonCenter;

			if (ImGui::IsItemActive())
			{
				g_draggedOutput = port;
			}
		}

		for (i32 slot_idx = 0; slot_idx < node->myInputs.Count(); slot_idx++)
		{
			InputPort* port = node->myInputs[slot_idx];
			MC_Vector2f portPos = MC_Vector2f(rect_min.x - NODE_SLOT_RADIUS, rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
			ImGui::SetCursorScreenPos(portPos);
			ImGui::InvisibleButton("##input", NODE_PORT_SIZE);

			MC_Vector2f buttonCenter = portPos + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
			if (ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly))
			{
				if (g_draggedOutput != nullptr)
				{
					connection_port_mismatch = port->myType != g_draggedOutput->myType;
					connection_port_match = port->myType == g_draggedOutput->myType;

					if (ImGui::IsMouseReleased(0) && connection_port_match)
						port->myConnectedPort = g_draggedOutput;
				}
				else if (ImGui::IsMouseClicked(0))
				{
					g_draggedOutput = port->myConnectedPort;
					port->myConnectedPort = nullptr;
				}
			}
			port->myPosition = buttonCenter;

			if (port->myConnectedPort != nullptr)
			{
				locDrawBezierCurve(draw_list, port->myConnectedPort->myPosition, port->myPosition, IM_COL32(100, 100, 100, 255));
			}
			else if(port->myProperty != nullptr)
			{
				ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, headerHeight + NODE_WINDOW_PADDING.y + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx));
				draw_list->ChannelsSetCurrent(1);
				port->myProperty->Render();
				draw_list->ChannelsSetCurrent(0);
			}
		}

		ImGui::SetCursorScreenPos(rect_min);
		ImGui::InvisibleButton("node", node->mySize);

		if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0))
			node->myPosition = node->myPosition + ImGui::GetIO().MouseDelta;

        ImGui::PopID();
    }

	draw_list->ChannelsSetCurrent(1);

	// Display nodes
	for (i32 node_idx = 0; node_idx < aNodeGraph->myNodes.Count(); node_idx++)
	{
		Node* node = aNodeGraph->myNodes[node_idx];

		ImGui::PushID(node->myID);
		locDrawNode(draw_list, node, offset);
		ImGui::PopID();
	}

	draw_list->ChannelsSetCurrent(0);
	if (!ImGui::IsMouseDown(0) && !ImGui::GetIO().KeyShift)
	{
		g_draggedOutput = nullptr;
	}
	if (g_draggedOutput != nullptr)
	{
        ImU32 color = connection_port_mismatch ? IM_COL32(200, 100, 100, 255) : (connection_port_match ? IM_COL32(100, 200, 100, 255) : IM_COL32(100, 100, 100, 255));
        locDrawBezierCurve(draw_list, g_draggedOutput->myPosition, ImGui::GetIO().MousePos, color);
	}
	draw_list->ChannelsMerge();

    // Scrolling
    if (ImGui::IsWindowHovered() && !ImGui::IsAnyItemActive() && ImGui::IsMouseDragging(2, 0.0f))
        scrolling = scrolling + ImGui::GetIO().MouseDelta;

	if(!ImGui::IsAnyItemHovered() && ImGui::IsMouseHoveringWindow() && ImGui::IsMouseClicked(1))
	{
		ImGui::OpenPopup("context_menu");
	}

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
	if (ImGui::BeginPopup("context_menu"))
	{
		MC_Vector2f scene_pos = MC_Vector2f(ImGui::GetMousePosOnOpeningCurrentPopup()) - offset;
		for(const char* str : NodesModule::ourRegisteredNodesNames)
		{
			if (ImGui::MenuItem(str)) 
			{ 
				NodesModule::Create(str, scene_pos); 
			}
		}
		ImGui::EndPopup();
	}
	ImGui::PopStyleVar();

    ImGui::PopItemWidth();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::EndGroup();
}
