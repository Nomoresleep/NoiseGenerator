#include <math.h> // fmodf
#include "MCommon/MC_GrowingArray.h"
#include "MCommon/MC_ScopedPtr.h"
#include "imgui.h"

static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }

static const float NODE_SLOT_RADIUS = 6.0f;
static const ImVec2 NODE_PORT_SIZE = ImVec2(2.0f * NODE_SLOT_RADIUS, 2.0f * NODE_SLOT_RADIUS);
static const ImVec2 NODE_WINDOW_PADDING = NODE_PORT_SIZE;// (8.0f, 8.0f);

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
	ImVec2 myPosition;
};

struct InputPort
{
    InputPort(PortType aPortType)
        : myType(aPortType)
        , myConnectedPort(nullptr)
    {}

	OutputPort* myConnectedPort;
    const PortType myType;
	ImVec2 myPosition;
};

class PropertyBase
{
public:
    virtual void Render() = 0;
};

class Node
{
public:
    Node(int id, const char* name, const ImVec2& pos)
        : myID(id)
        , myLabel(name)
        , myPosition(pos)
        , myProperties(8, 8)
        , myOutputs(8, 8)
        , myInputs(8, 8){};

    const char* myLabel;
    int myID;

    ImVec2 myPosition;
    ImVec2 mySize;

    MC_GrowingArray<MC_ScopedPtr<PropertyBase>> myProperties;
    MC_GrowingArray<MC_ScopedPtr<OutputPort>> myOutputs;
    MC_GrowingArray<MC_ScopedPtr<InputPort>> myInputs;
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

    void Set(T aValue) { myValue = min(myMax, max(myMin, aValue)); }
    const T& Get() const { return myValue; }
    T myValue;
    T myMin, myMax;
};

template <typename T>
void locRenderSlider(Property<T>* aProperty);

template <>
void locRenderSlider<f32>(Property<f32>* aProperty)
{
    ImGui::SliderFloat("##awinqwfpi", &aProperty->myValue, aProperty->myMin, aProperty->myMax);
}

template <>
void locRenderSlider<i32>(Property<i32>* aProperty)
{
    ImGui::SliderInt("##knawlfn", &aProperty->myValue, aProperty->myMin, aProperty->myMax);
}

template <typename T>
void Property<T>::Render() { locRenderSlider(this); }

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
    ConstantNode(int id, const char* name, const ImVec2& pos, Property<Type>* aProperty)
        : Node(id, name, pos) {
        myProperties.Add(aProperty);
        myOutputs.Add(new OutputPort(GetPortType<Type>()));
    };
};

class PerlinNoise2DNode : public Node
{
public:
	PerlinNoise2DNode(int anID, const char* aName, const ImVec2& aPosition)
		: Node(anID, aName, aPosition)
	{
		myInputs.Add(new InputPort(FloatPort));
		myInputs.Add(new InputPort(FloatPort));
		myInputs.Add(new InputPort(FloatPort));
		myOutputs.Add(new OutputPort(FloatPort));
	};

};

class ResultNode : public Node
{
public:
    ResultNode()
        : Node(0, "Result", ImVec2(100, 100))
    {
        myInputs.Add(new InputPort(FloatPort));
    };
};

static OutputPort* g_draggedOutput = nullptr;

static void locDrawBezierCurve(ImDrawList* aDrawList, ImVec2 aP0, ImVec2 aP1, ImU32 aColor, float aThickness)
{
	//NOTE:[Nomoresleep] performance impact?
	aDrawList->ChannelsSetCurrent(0);
    float xdist = min(50.0f, aP1.x - aP0.x);
    aDrawList->AddBezierCurve(aP0, aP0 + ImVec2(xdist, 0), aP1 + ImVec2(-xdist, 0), aP1, aColor, aThickness);
	aDrawList->ChannelsSetCurrent(1);
}

static void locDrawPort(ImDrawList* aDrawList, ImVec2 aPortPos, ImU32 aColor)
{
    aDrawList->AddRectFilled(aPortPos, aPortPos + NODE_PORT_SIZE, aColor);
    aDrawList->AddRect(aPortPos, aPortPos + NODE_PORT_SIZE, IM_COL32(200, 200, 200, 255), 0.0f, ImDrawCornerFlags_All, 1.0f);
}

static void ShowExampleAppCustomNodeGraph(bool* opened)
{
    static MC_GrowingArray<MC_ScopedPtr<Node>> nodes(32, 32);
    //static ImVector<NodeLink> links;
    static bool inited = false;
    static ImVec2 scrolling = ImVec2(0.0f, 0.0f);
    static bool show_grid = true;
    static int node_selected = -1;
    if (!inited)
    {
        nodes.Add(new ResultNode());
		Property<f32>* floatProperty1 = new Property<f32>(0.0f, 1.0f);
		nodes.Add(new ConstantNode<f32>(1, "GetUV.x", ImVec2(100, 170), floatProperty1));
        Property<f32>* floatProperty2 = new Property<f32>(0.0f, 1.0f);
        nodes.Add(new ConstantNode<f32>(2, "GetUV.y", ImVec2(100, 270), floatProperty2));
        Property<f32>* floatProperty3 = new Property<f32>(0.0f, 20.0f);
        nodes.Add(new ConstantNode<f32>(3, "Frequency", ImVec2(100, 370), floatProperty3));
		nodes.Add(new PerlinNoise2DNode(4, "Perlin Noise 2D", ImVec2(300, 270)));
        inited = true;
    }

    // Draw a list of nodes on the left side
    bool open_context_menu = false;
    int node_hovered_in_list = -1;
    int node_hovered_in_scene = -1;

    ImGui::BeginGroup();

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(1, 1));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, IM_COL32(60, 60, 70, 255));
    ImGui::BeginChild("scrolling_region", ImGui::GetWindowContentRegionMax() - ImGui::GetWindowContentRegionMin(), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
    ImGui::PushItemWidth(120.0f);

    ImVec2 offset = ImGui::GetCursorScreenPos() + scrolling;
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    // Display grid
    ImU32 GRID_COLOR = IM_COL32(200, 200, 200, 40);
    float GRID_SZ = 64.0f;
    ImVec2 win_pos = ImGui::GetCursorScreenPos();
    ImVec2 canvas_sz = ImGui::GetWindowSize();
    for (float x = fmodf(scrolling.x, GRID_SZ); x < canvas_sz.x; x += GRID_SZ)
        draw_list->AddLine(ImVec2(x, 0.0f) + win_pos, ImVec2(x, canvas_sz.y) + win_pos, GRID_COLOR);
    for (float y = fmodf(scrolling.y, GRID_SZ); y < canvas_sz.y; y += GRID_SZ)
        draw_list->AddLine(ImVec2(0.0f, y) + win_pos, ImVec2(canvas_sz.x, y) + win_pos, GRID_COLOR);

    // Display links
    draw_list->ChannelsSplit(2);
    draw_list->ChannelsSetCurrent(0); // Background
    //for (int link_idx = 0; link_idx < links.Size; link_idx++)
    //{
    //    NodeLink* link = &links[link_idx];
    //    Node* node_inp = &nodes[link->InputIdx];
    //    Node* node_out = &nodes[link->OutputIdx];
    //    ImVec2 p1 = offset + node_inp->GetOutputSlotPos(link->InputSlot);
    //    ImVec2 p2 = offset + node_out->GetInputSlotPos(link->OutputSlot);
    //    draw_list->AddBezierCurve(p1, p1 + ImVec2(+50, 0), p2 + ImVec2(-50, 0), p2, IM_COL32(200, 200, 100, 255), 3.0f);
    //}

    bool connection_port_mismatch = false;
    bool connection_port_match = false;
    // Display nodes
    for (int node_idx = 0; node_idx < nodes.Count(); node_idx++)
    {
        Node* node = nodes[node_idx];
        ImGui::PushID(node->myID);
        ImVec2 node_rect_min = offset + node->myPosition;

        // Display node contents first
        draw_list->ChannelsSetCurrent(1); // Foreground
        bool old_any_active = ImGui::IsAnyItemActive();
        ImGui::SetCursorScreenPos(node_rect_min + NODE_WINDOW_PADDING);
        ImGui::BeginGroup(); // Lock horizontal position
        ImGui::Text("%s", node->myLabel);
        if(node->myProperties.Count())
            node->myProperties[0]->Render();
        //ImGui::ColorEdit3("##color", &node->Color.x);

		ImGui::EndGroup();

		// Save the size of what we have emitted and whether any of the widgets are being used
		bool node_widgets_active = (!old_any_active && ImGui::IsAnyItemActive());
		node->mySize = ImGui::GetItemRectSize() + NODE_WINDOW_PADDING + NODE_WINDOW_PADDING + ImVec2(0, ImGui::GetItemsLineHeightWithSpacing() * max(node->myInputs.Count(), node->myOutputs.Count()));
		ImVec2 node_rect_max = node_rect_min + node->mySize;
		
		for (int slot_idx = 0; slot_idx < node->myOutputs.Count(); slot_idx++)
		{
			OutputPort* port = node->myOutputs[slot_idx];
			ImVec2 portPos = ImVec2(node_rect_min.x + node->mySize.x - NODE_SLOT_RADIUS, node_rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
			ImGui::SetCursorScreenPos(portPos);
			{
				locDrawPort(draw_list, portPos, GetColorFromPortType(port->myType));
				ImGui::InvisibleButton("##output", NODE_PORT_SIZE);
			}
			ImVec2 buttonCenter = portPos + ImVec2(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
			port->myPosition = buttonCenter;

			if (ImGui::IsItemActive())
			{
				g_draggedOutput = port;
			}
		}

		for (int slot_idx = 0; slot_idx < node->myInputs.Count(); slot_idx++)
		{
			InputPort* port = node->myInputs[slot_idx];
			ImVec2 portPos = ImVec2(node_rect_min.x - NODE_SLOT_RADIUS, node_rect_min.y + NODE_WINDOW_PADDING.y * 2.0f + ImGui::GetTextLineHeight() + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
			ImGui::SetCursorScreenPos(portPos);
			{
				locDrawPort(draw_list, portPos, GetColorFromPortType(port->myType));
				ImGui::InvisibleButton("##input", NODE_PORT_SIZE);
			}
			ImVec2 buttonCenter = portPos + ImVec2(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
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
				locDrawBezierCurve(draw_list, port->myConnectedPort->myPosition, port->myPosition, IM_COL32(100, 100, 100, 255), 3.0f);
			}
		}

        // Display node box
        draw_list->ChannelsSetCurrent(0); // Background
        ImGui::SetCursorScreenPos(node_rect_min);
        ImGui::InvisibleButton("node", node->mySize);
        if (ImGui::IsItemHovered())
        {
            node_hovered_in_scene = node->myID;
            open_context_menu |= ImGui::IsMouseClicked(1);
        }
        bool node_moving_active = ImGui::IsItemActive();
        if (node_widgets_active || node_moving_active)
            node_selected = node->myID;
        if (node_moving_active && ImGui::IsMouseDragging(0))
            node->myPosition = node->myPosition + ImGui::GetIO().MouseDelta;

        ImU32 node_bg_color = (node_hovered_in_list == node->myID || node_hovered_in_scene == node->myID || (node_hovered_in_list == -1 && node_selected == node->myID)) ? IM_COL32(75, 75, 75, 255) : IM_COL32(60, 60, 60, 255);
        draw_list->AddRectFilled(node_rect_min, node_rect_max, node_bg_color);
        draw_list->AddRect(node_rect_min, node_rect_max, IM_COL32(100, 100, 100, 255));

        ImGui::PopID();
    }
	if (!ImGui::IsMouseDown(0) && !ImGui::GetIO().KeyShift)
	{
		g_draggedOutput = nullptr;
	}
	if (g_draggedOutput != nullptr)
	{
        ImU32 color = connection_port_mismatch ? IM_COL32(200, 100, 100, 255) : (connection_port_match ? IM_COL32(100, 200, 100, 255) : IM_COL32(100, 100, 100, 255));
        locDrawBezierCurve(draw_list, g_draggedOutput->myPosition, ImGui::GetIO().MousePos, color, 3.0f);
	}
    draw_list->ChannelsMerge();

    // Open context menu
    if (!ImGui::IsAnyItemHovered() && ImGui::IsMouseHoveringWindow() && ImGui::IsMouseClicked(1))
    {
        node_selected = node_hovered_in_list = node_hovered_in_scene = -1;
        open_context_menu = true;
    }
    if (open_context_menu)
    {
        ImGui::OpenPopup("context_menu");
        if (node_hovered_in_list != -1)
            node_selected = node_hovered_in_list;
        if (node_hovered_in_scene != -1)
            node_selected = node_hovered_in_scene;
    }

    // Draw context menu
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
    if (ImGui::BeginPopup("context_menu"))
    {
        Node* node = node_selected != -1 ? nodes[node_selected] : NULL;
        ImVec2 scene_pos = ImGui::GetMousePosOnOpeningCurrentPopup() - offset;
        if (node)
        {
            ImGui::Text("Node '%s'", node->myLabel);
            ImGui::Separator();
            if (ImGui::MenuItem("Rename..", NULL, false, false)) {}
            if (ImGui::MenuItem("Delete", NULL, false, false)) {}
            if (ImGui::MenuItem("Copy", NULL, false, false)) {}
        }
        else
        {
            if (ImGui::MenuItem("Add")) { nodes.Add(new Node(nodes.Count(), "New node", scene_pos)); }
            if (ImGui::MenuItem("Paste", NULL, false, false)) {}
        }
        ImGui::EndPopup();
    }
    ImGui::PopStyleVar();

    // Scrolling
    if (ImGui::IsWindowHovered() && !ImGui::IsAnyItemActive() && ImGui::IsMouseDragging(2, 0.0f))
        scrolling = scrolling + ImGui::GetIO().MouseDelta;

    ImGui::PopItemWidth();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::EndGroup();
}