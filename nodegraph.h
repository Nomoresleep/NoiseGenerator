// Creating a node graph editor for ImGui
// Quick demo, not production code! This is more of a demo of how to use ImGui to create custom stuff.
// Better version by @daniel_collin here https://gist.github.com/emoon/b8ff4b4ce4f1b43e79f2
// See https://github.com/ocornut/imgui/issues/306
// v0.03: fixed grid offset issue, inverted sign of 'scrolling'
// Animated gif: https://cloud.githubusercontent.com/assets/8225057/9472357/c0263c04-4b4c-11e5-9fdf-2cd4f33f6582.gif

#include <math.h> // fmodf
#include "imgui.h"

// NB: You can use math functions/operators on ImVec2 if you #define IMGUI_DEFINE_MATH_OPERATORS and #include "imgui_internal.h"
// Here we only declare simple +/- operators so others don't leak into the demo code.
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
        , myPosition(pos) {};

    const char* myLabel;
    int myID;

    ImVec2 myPosition;
    ImVec2 mySize;

    ImVector<PropertyBase*> myProperties;
    ImVector<OutputPort*> myOutputs;
	ImVector<InputPort*> myInputs;
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
        myProperties.push_back(aProperty);
        myOutputs.push_back(new OutputPort(GetPortType<Type>()));
    };
};

template <typename Type>
class ReadNode : public Node
{
public:
	ReadNode(int id, const char* name, const ImVec2& pos, Property<Type>* aProperty)
		: Node(id, name, pos)
	{
		myProperties.push_back(aProperty);
		myInputs.push_back(new InputPort(GetPortType<Type>()));
	}
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
    static ImVector<Node*> nodes;
    //static ImVector<NodeLink> links;
    static bool inited = false;
    static ImVec2 scrolling = ImVec2(0.0f, 0.0f);
    static bool show_grid = true;
    static int node_selected = -1;
    if (!inited)
    {
		Property<f32>* floatProperty1 = new Property<f32>(0.0f, 1.0f);
		nodes.push_back(new ConstantNode<f32>(0, "ConstantNode1", ImVec2(40, 250), floatProperty1));
        Property<f32>* floatProperty2 = new Property<f32>(0.0f, 1.0f);
        nodes.push_back(new ConstantNode<f32>(1, "ConstantNode2", ImVec2(40, 170), floatProperty2));
        Property<i32>* intProperty1 = new Property<i32>(0, 1337);
        nodes.push_back(new ConstantNode<i32>(2, "ConstantNode3", ImVec2(200, 170), intProperty1));
        Property<f32>* otherFloatProperty = new Property<f32>(0.0f, 1.0f);
        nodes.push_back(new ReadNode<f32>(3, "ReadNode", ImVec2(200, 250), otherFloatProperty));
        Property<i32>* intProperty2 = new Property<i32>(0, 42);
        nodes.push_back(new ReadNode<i32>(4, "ReadNode", ImVec2(200, 400), intProperty2));
        inited = true;
    }

    // Draw a list of nodes on the left side
    bool open_context_menu = false;
    int node_hovered_in_list = -1;
    int node_hovered_in_scene = -1;

    ImGui::BeginGroup();

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(1, 1));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, IM_COL32(60, 60, 70, 200));
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
    for (int node_idx = 0; node_idx < nodes.Size; node_idx++)
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
        if(node->myProperties.size())
            node->myProperties[0]->Render();
        //ImGui::ColorEdit3("##color", &node->Color.x);
        ImGui::EndGroup();

        // Save the size of what we have emitted and whether any of the widgets are being used
        bool node_widgets_active = (!old_any_active && ImGui::IsAnyItemActive());
        node->mySize = ImGui::GetItemRectSize() + NODE_WINDOW_PADDING + NODE_WINDOW_PADDING;
        ImVec2 node_rect_max = node_rect_min + node->mySize;


		for (int slot_idx = 0; slot_idx < node->myOutputs.size(); slot_idx++)
		{
			OutputPort* port = node->myOutputs[slot_idx];
			ImVec2 portPos = ImVec2(node_rect_min.x + node->mySize.x - NODE_SLOT_RADIUS, node_rect_min.y + node->mySize.y * ((float)slot_idx + 1) / ((float)node->myOutputs.size() + 1));
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

		for (int slot_idx = 0; slot_idx < node->myInputs.size(); slot_idx++)
		{
			InputPort* port = node->myInputs[slot_idx];
			ImVec2 portPos = ImVec2(node_rect_min.x - NODE_SLOT_RADIUS, node_rect_min.y + node->mySize.y * ((float)slot_idx + 1) / ((float)node->myInputs.size() + 1));
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
        ImGui::InvisibleButton("node", ImVec2(node->mySize.x, NODE_WINDOW_PADDING.y + ImGui::GetTextLineHeight()));
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
	if (ImGui::IsMouseReleased(0))
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
            if (ImGui::MenuItem("Add")) { nodes.push_back(new Node(nodes.Size, "New node", scene_pos)); }
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