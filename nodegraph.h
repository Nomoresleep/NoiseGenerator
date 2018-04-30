#include <math.h> // fmodf
#include "MCommon/MC_GrowingArray.h"
#include "MCommon/MC_ScopedPtr.h"
#include "MCommon/MC_Vector.h"
#include "MCommon/MC_Pair.h"
#include "imgui.h"

static const f32 NODE_SLOT_RADIUS = 6.0f;
static const MC_Vector2f NODE_PORT_SIZE = MC_Vector2f(2.0f * NODE_SLOT_RADIUS, 2.0f * NODE_SLOT_RADIUS);
static const MC_Vector2f NODE_WINDOW_PADDING = MC_Vector2f(8.0f, 4.0f);
static const f32 NODE_PROPERTY_WIDTH = 120.0f;

enum PortType
{
    FloatPort,
    IntPort,
};

union PortData
{
    float myFloatData;
    int myIntPortData;
};

struct OutputPort
{
    OutputPort(PortType aPortType)
        : myType(aPortType)
    {};

    PortData myData;
    const PortType myType;
	MC_Vector2f myPosition;
};

struct InputPort
{
    InputPort(PortType aPortType)
        : myType(aPortType)
        , myConnectedPort(nullptr)
    {}

	OutputPort* myConnectedPort;
    const PortType myType;
	MC_Vector2f myPosition;
};

class PropertyBase
{
public:
    virtual void Render() = 0;
};

class Node
{
public:
    Node(int id, const char* name, const MC_Vector2f& pos)
        : myID(id)
        , myLabel(name)
        , myPosition(pos)
        , myProperties(8, 8)
        , myOutputs(8, 8)
        , myInputs(8, 8){};

    const char* myLabel;
    int myID;

    MC_Vector2f myPosition;
    MC_Vector2f mySize;

	MC_GrowingArray<MC_ScopedPtr<PropertyBase>> myProperties;
	MC_GrowingArray<MC_ScopedPtr<OutputPort>> myOutputs;
	MC_GrowingArray<MC_ScopedPtr<InputPort>> myInputs;
protected:
	void AddInputPort(InputPort* anInputPort)
	{
		myInputs.Add(anInputPort);
		CalculateSize();
	}
	void AddOutputPort(OutputPort* anOutputPort)
	{
		myOutputs.Add(anOutputPort);
		CalculateSize();
	}
	void CalculateSize()
	{
		MC_Vector2f textSize = ImGui::CalcTextSize(myLabel);
		mySize = MC_Vector2f(MC_Max(textSize.x, NODE_PROPERTY_WIDTH) + 2.0f * NODE_WINDOW_PADDING.x, textSize.y + 2.0f * NODE_WINDOW_PADDING.y);
		mySize.y += MC_Max(myProperties.Count(), myInputs.Count(), myOutputs.Count()) * ImGui::GetItemsLineHeightWithSpacing() + ImGui::GetStyle().ItemSpacing.y;
	}
};


template <typename T>
class Property : public PropertyBase
{
public:
    Property(T aMin, T aMax)
        : myMin(aMin)
        , myMax(aMax)
        , myValue(aMin){}

    void Render() override;

    void Set(T aValue) { myValue = MC_Min(myMax, MC_Max(myMin, aValue)); }
    const T& Get() const { return myValue; }
    T myValue;
    T myMin, myMax;
};

template <typename T>
void locRenderDrag(Property<T>* aProperty);

template <>
void locRenderDrag<f32>(Property<f32>* aProperty)
{
    ImGui::DragFloat("##awinqwfpi", &aProperty->myValue, 0.001f, aProperty->myMin, aProperty->myMax);
}

template <>
void locRenderDrag<i32>(Property<i32>* aProperty)
{
    ImGui::DragInt("##knawlfn", &aProperty->myValue, 1.0f, aProperty->myMin, aProperty->myMax);
}

template <typename T>
void Property<T>::Render() { locRenderDrag(this); }

template <typename Type>
PortType GetPortType();

template<>
PortType GetPortType<f32>() { return FloatPort; }

template<>
PortType GetPortType<i32>() { return IntPort; }

ImU32 GetColorFromPortType(PortType aType)
{
    switch (aType)
    {
    case FloatPort:
        return IM_COL32(0, 95, 0, 255);
    case IntPort:
        return IM_COL32(66, 150, 250, 255);
    }
    return IM_COL32(255, 255, 255, 255);
}

template <typename Type>
class ConstantNode : public Node
{
public:
    ConstantNode(int id, const char* name, const MC_Vector2f& pos, Property<Type>* aProperty)
        : Node(id, name, pos) {
        myProperties.Add(aProperty);
        AddOutputPort(new OutputPort(GetPortType<Type>()));
    };
};

class PerlinNoise2DNode : public Node
{
public:
	PerlinNoise2DNode(int anID, const char* aName, const MC_Vector2f& aPosition)
		: Node(anID, aName, aPosition)
	{
		AddInputPort(new InputPort(FloatPort));
		AddInputPort(new InputPort(FloatPort));
		AddInputPort(new InputPort(FloatPort));
		AddOutputPort(new OutputPort(FloatPort));
	};

};

class ResultNode : public Node
{
public:
    ResultNode()
        : Node(0, "Result", MC_Vector2f(100, 100))
    {
        AddInputPort(new InputPort(FloatPort));
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

static void ShowExampleAppCustomNodeGraph(bool* opened)
{
    static MC_GrowingArray<MC_ScopedPtr<Node>> nodes(32, 32);
    static bool inited = false;
    static MC_Vector2f scrolling = MC_Vector2f(0.0f, 0.0f);
    if (!inited)
    {
        nodes.Add(new ResultNode());
		nodes.Add(new ConstantNode<f32>(1, "GetUV.x", MC_Vector2f(100, 170), new Property<f32>(0.0f, 1.0f)));
        nodes.Add(new ConstantNode<f32>(2, "GetUV.y", MC_Vector2f(100, 270), new Property<f32>(0.0f, 1.0f)));
        nodes.Add(new ConstantNode<f32>(3, "Frequency", MC_Vector2f(100, 370), new Property<f32>(0.0f, 20.0f)));
		nodes.Add(new PerlinNoise2DNode(4, "Perlin Noise 2D", MC_Vector2f(300, 270)));
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
	draw_list->ChannelsSetCurrent(1);

    // Display nodes
	for (i32 node_idx = 0; node_idx < nodes.Count(); node_idx++)
	{
		Node* node = nodes[node_idx];

		ImGui::PushID(node->myID);
		locDrawNode(draw_list, node, offset);
		ImGui::PopID();
	}

	draw_list->ChannelsSetCurrent(0);
	for(i32 node_idx = nodes.Count() - 1; node_idx >= 0; node_idx--)
	{
		Node* node = nodes[node_idx];
		MC_Vector2f rect_min = offset + node->myPosition;
		ImGui::PushID(node->myID);
		
		//Draw Node properties
		const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
		ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, headerHeight + NODE_WINDOW_PADDING.y));
		draw_list->ChannelsSetCurrent(1);
		for (i32 i = 0; i < node->myProperties.Count(); ++i)
			node->myProperties[i]->Render();
		draw_list->ChannelsSetCurrent(0);

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
		}

		ImGui::SetCursorScreenPos(rect_min);
		ImGui::InvisibleButton("node", node->mySize);

		if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0))
			node->myPosition = node->myPosition + ImGui::GetIO().MouseDelta;

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

    ImGui::PopItemWidth();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::EndGroup();
}