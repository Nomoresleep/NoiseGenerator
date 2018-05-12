#include "Editor_NodeEditor.h"
#include "Editor_NodeTools.h"

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

static void locDisplayWarning(const char* aWarningMessage)
{
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(200, 170, 50, 255));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
	ImGui::BeginTooltip();
	ImGui::Text(aWarningMessage);
	ImGui::EndTooltip();
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
}

static void locDrawNode(ImDrawList* aDrawList, Editor_NodeProperties* aProp, MC_Vector2f anOffset)
{
	NG_Node* node = aProp->myNode;
	MC_Vector2f rect_min = anOffset + aProp->myPosition;
	MC_Vector2f rect_max = rect_min + aProp->mySize;
	const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
	MC_Vector2f rect_header_max = rect_min + MC_Vector2f(aProp->mySize.x, headerHeight);

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
	ImGui::Text("%s", aProp->myLabel);

	//Draw Output ports
	for (s32 slot_idx = 0; slot_idx < node->myOutputs.Count(); slot_idx++)
	{
		OutputPort* port = node->myOutputs[slot_idx];
		MC_Vector2f portPos = port->myPosition - MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}

	//Draw Input ports
	for (s32 slot_idx = 0; slot_idx < node->myInputs.Count(); slot_idx++)
	{
		InputPort* port = node->myInputs[slot_idx];
		MC_Vector2f portPos = port->myPosition - MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}
}

void Editor_NodeEditor::Display()
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

	MC_GrowingArray<InputPort*> connections(32);
	bool connection_port_mismatch = false;
	bool connection_port_match = false;

	const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;

	draw_list->ChannelsSplit(3);

	draw_list->ChannelsSetCurrent(0);
	for (s32 node_idx = myNodeRenderer.Count() - 1; node_idx >= 0; node_idx--)
	{
		Editor_NodeProperties* props = myNodeRenderer[node_idx];
		NG_Node* node = props->myNode;
		MC_Vector2f rect_min = offset + props->myPosition;
		ImGui::PushID(props->myID);

		//Draw Node properties
		const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
		ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, headerHeight + NODE_WINDOW_PADDING.y));

		for (s32 slot_idx = 0; slot_idx < node->myOutputs.Count(); slot_idx++)
		{
			OutputPort* port = node->myOutputs[slot_idx];
			port->myPosition = MC_Vector2f(rect_min.x + props->mySize.x - NODE_SLOT_RADIUS, rect_min.y + headerHeight + ImGui::GetStyle().ItemSpacing.y + ImGui::GetItemsLineHeightWithSpacing() * (slot_idx + node->myInputs.Count()));
			ImGui::SetCursorScreenPos(port->myPosition);
			ImGui::InvisibleButton("##output", NODE_PORT_SIZE);

			MC_Vector2f buttonCenter = port->myPosition + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
			port->myPosition = buttonCenter;

			if (ImGui::IsItemActive())
			{
				g_draggedOutput = port;
			}
		}

		for (s32 slot_idx = 0; slot_idx < node->myInputs.Count(); slot_idx++)
		{
			InputPort* port = node->myInputs[slot_idx];
			port->myPosition = MC_Vector2f(rect_min.x - NODE_SLOT_RADIUS, rect_min.y + headerHeight + ImGui::GetStyle().ItemSpacing.y + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx);
			ImGui::SetCursorScreenPos(port->myPosition);
			ImGui::InvisibleButton("##input", NODE_PORT_SIZE);

			MC_Vector2f buttonCenter = port->myPosition + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
			const bool hovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
			if (hovered)
			{
				if (g_draggedOutput != nullptr)
				{
					connection_port_mismatch = port->myType != g_draggedOutput->myType;
					connection_port_match = port->myType == g_draggedOutput->myType;

					if (connection_port_match)
					{
						if (port->TryConnect(g_draggedOutput))
						{
							if (ImGui::IsMouseReleased(0))
							{
								port->Connect(g_draggedOutput);
							}
						}
						else
						{
							locDisplayWarning("Error, Nodegraph must not be cyclic!");
							connection_port_mismatch = true;
							connection_port_match = false;
						}
					}
					else
					{
						locDisplayWarning("Error, Port type mismatch!");
					}
				}
				else if (ImGui::IsMouseClicked(0))
				{
					g_draggedOutput = port->myConnectedPort;
					port->Connect(nullptr);
				}
			}
			port->myPosition = buttonCenter;

			if (port->myConnectedPort != nullptr)
			{
				locDrawBezierCurve(draw_list, port->myConnectedPort->myPosition, port->myPosition, hovered ? IM_COL32(255, 255, 255, 255) : IM_COL32(100, 100, 100, 255));
			}
			/*else if(port->myProperty != nullptr)
			{
			ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, headerHeight + NODE_WINDOW_PADDING.y + ImGui::GetItemsLineHeightWithSpacing() * (f32)slot_idx));
			draw_list->ChannelsSetCurrent(2);
			ImGui::PushID(slot_idx);
			port->myProperty->Render();
			ImGui::PopID();
			draw_list->ChannelsSetCurrent(0);
			}*/
		}

		ImGui::SetCursorScreenPos(rect_min);
		ImGui::InvisibleButton("node", props->mySize);

		if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0))
			props->myPosition = props->myPosition + ImGui::GetIO().MouseDelta;

		ImGui::PopID();
	}

	draw_list->ChannelsSetCurrent(1);

	// Display nodes
	for (s32 node_idx = 0; node_idx < myNodeRenderer.Count(); node_idx++)
	{
		Editor_NodeProperties* prop = myNodeRenderer[node_idx];

		ImGui::PushID(prop->myID);
		locDrawNode(draw_list, prop, offset);
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

	if (!ImGui::IsAnyItemHovered() && ImGui::IsMouseHoveringWindow() && ImGui::IsMouseClicked(1))
	{
		ImGui::OpenPopup("context_menu");
	}

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
	if (ImGui::BeginPopup("context_menu"))
	{
		MC_Vector2f scene_pos = MC_Vector2f(ImGui::GetMousePosOnOpeningCurrentPopup()) - offset;
		for (const char* str : NG_NodesModule::ourRegisteredNodesNames)
		{
			NG_NodesModule::NodeCreationData* data = NG_NodesModule::ourRegisteredNodes.GetIfExists(str);
			if (!data)
				continue;

			bool enabled = !data->myIsSingleton || !myGraph->ContainsNodeOfName(str);
			if (ImGui::MenuItem(str, 0, false, enabled))
			{
				NG_NodesModule::Create(myGraph, str, scene_pos);
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

void Editor_NodeEditor::OnNodeAdded(NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
{
	myNodeRenderer.Add(new Editor_NodeProperties(aNode, aNodeLabel, aNodeUID, aPosition));
}

void Editor_NodeEditor::OnNodeRemoved(NG_Node* aNode)
{
	(void)aNode;
}