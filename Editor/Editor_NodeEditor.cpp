#include "Editor_NodeEditor.h"
#include "Editor_NodeTools.h"
#include "Editor_Commands.h"

static const f32 GRID_SPACING = 64.0f;

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

float locGetHeaderHeight()
{
	const f32 headerHeight = ImGui::GetTextLineHeight() + NODE_WINDOW_PADDING.y * 2.0f;
	return headerHeight;
}

MC_Vector2f locGetGlobalInputPortPosition(Editor_NodeProperties* someNodeProperties, u32 aPortIndex, const MC_Vector2f& anOffset)
{
	return MC_Vector2f(someNodeProperties->myPosition.x - NODE_SLOT_RADIUS,
		someNodeProperties->myPosition.y + locGetHeaderHeight() + ImGui::GetStyle().ItemSpacing.y + ImGui::GetItemsLineHeightWithSpacing() * (f32)aPortIndex) + anOffset;
}

MC_Vector2f locGetGlobalOutputPortPosition(Editor_NodeProperties* someNodeProperties, u32 aPortIndex, const MC_Vector2f& anOffset)
{
	return MC_Vector2f(someNodeProperties->myPosition.x + someNodeProperties->mySize.x - NODE_SLOT_RADIUS, 
		someNodeProperties->myPosition.y + locGetHeaderHeight() + ImGui::GetStyle().ItemSpacing.y + ImGui::GetItemsLineHeightWithSpacing() * (aPortIndex + someNodeProperties->myNode->myInputs.Count())) + anOffset;

}

static void locDrawBezierCurve(ImDrawList* aDrawList, MC_Vector2f aP0, MC_Vector2f aP1, ImU32 aColor)
{
	static const f32 CURVE_THICKNESS = 2.0f;
	float xdist = MC_Max(MC_Abs(aP1.x - aP0.x), 35.0f);
	aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, IM_COL32(100, 100, 100, 255), CURVE_THICKNESS + 1.5f);
	aDrawList->AddBezierCurve(aP0, aP0 + MC_Vector2f(xdist, 0), aP1 + MC_Vector2f(-xdist, 0), aP1, aColor, CURVE_THICKNESS);
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
	for (s32 slotIdx = 0; slotIdx < node->myOutputs.Count(); slotIdx++)
	{
		NG_OutputPort* port = node->myOutputs[slotIdx];
		MC_Vector2f portPos = locGetGlobalOutputPortPosition(aProp, slotIdx, anOffset);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}

	//Draw Input ports
	for (s32 slotIdx = 0; slotIdx < node->myInputs.Count(); slotIdx++)
	{
		NG_InputPort* port = node->myInputs[slotIdx];
		MC_Vector2f portPos = locGetGlobalInputPortPosition(aProp, slotIdx, anOffset);
		ImGui::SetCursorScreenPos(portPos);

		locDrawPort(aDrawList, portPos, GetColorFromPortType(port->myType));
	}
}

void Editor_NodeEditor::ShowNodeCreationContextMenu(const MC_Vector2f& aCreateLocation)
{
	for (const char* str : NG_NodesModule::ourRegisteredNodesNames)
	{
		NG_NodesModule::NodeCreationData* data = NG_NodesModule::ourRegisteredNodes.GetIfExists(str);
		if (!data)
			continue;

		if (ImGui::MenuItem(str, 0, false, true))
		{
			NG_Node* newNode = NG_NodesModule::Create(str);
			//TODO: Create node uids
			myCommands.ExecuteCommand(new Editor_CreateNodeCommand(this, newNode, NG_NodesModule::GetNodeUID(), str, aCreateLocation));
		}
	}
}

void Editor_NodeEditor::Display()
{
	const ImU32 GRID_COLOR = IM_COL32(200, 200, 200, 40);

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, MC_Vector2f(1, 1));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, MC_Vector2f(0, 0));
	ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, IM_COL32(60, 60, 70, 255));
	ImGui::BeginChild("scrolling_region", MC_Vector2f(ImGui::GetWindowContentRegionMax()) - ImGui::GetWindowContentRegionMin(), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);

	ImDrawList* drawList = ImGui::GetWindowDrawList();
	// Display grid
	const MC_Vector2f windowPos = ImGui::GetCursorScreenPos();
	const MC_Vector2f canvasSize = ImGui::GetWindowSize();
	for (float x = fmodf(myScrolling.x, GRID_SPACING); x < canvasSize.x; x += GRID_SPACING)
		drawList->AddLine(MC_Vector2f(x, 0.0f) + windowPos, MC_Vector2f(x, canvasSize.y) + windowPos, GRID_COLOR);
	for (float y = fmodf(myScrolling.y, GRID_SPACING); y < canvasSize.y; y += GRID_SPACING)
		drawList->AddLine(MC_Vector2f(0.0f, y) + windowPos, MC_Vector2f(canvasSize.x, y) + windowPos, GRID_COLOR);

	const MC_Vector2f offset = windowPos + myScrolling;
	ConnectionStatus connectionError = ConnectionUnknown;

	struct ConnectionCurve
	{
		Editor_NodeProperties* outProps;
		NG_OutputPort* outPort;
		Editor_NodeProperties* inProps;
		NG_InputPort* inPort;
		ImU32 col;
	};
	MC_GrowingArray<ConnectionCurve> connections;

	drawList->ChannelsSplit(2);

	drawList->ChannelsSetCurrent(1);
	//Node behaviour
	for (s32 node_idx = myNodeProperties.Count() - 1; node_idx >= 0; node_idx--)
	{
		Editor_NodeProperties* props = myNodeProperties[node_idx];
		NG_Node* node = props->myNode;
		MC_Vector2f rect_min = offset + props->myPosition;
		ImGui::PushID(props->myID);

		//Draw Node properties
		ImGui::SetCursorScreenPos(rect_min + MC_Vector2f(NODE_WINDOW_PADDING.x, locGetHeaderHeight() + NODE_WINDOW_PADDING.y));

		for (s32 slotIdx = 0; slotIdx < node->myOutputs.Count(); slotIdx++)
		{
			NG_OutputPort* port = node->myOutputs[slotIdx];
			MC_Vector2f portPosition = locGetGlobalOutputPortPosition(props, slotIdx, offset);

			ImGui::SetCursorScreenPos(portPosition);
			ImGui::InvisibleButton("##output", NODE_PORT_SIZE);

			if (ImGui::IsItemActive())
			{
				myDraggedOutput = MC_MakePair<Editor_NodeProperties*, u32>(props, slotIdx);
			}
		}

		for (s32 slotIdx = 0; slotIdx < node->myInputs.Count(); slotIdx++)
		{
			NG_InputPort* port = node->myInputs[slotIdx];
			MC_Vector2f portPosition = locGetGlobalInputPortPosition(props, slotIdx, offset);
			ImGui::SetCursorScreenPos(portPosition);
			ImGui::InvisibleButton("##input", NODE_PORT_SIZE);

			const bool hovered = ImGui::IsItemHovered(ImGuiHoveredFlags_RectOnly);
			if (hovered)
			{
				if (myDraggedOutput.myFirst != nullptr)
				{
					NG_OutputPort* draggedPort = myDraggedOutput.myFirst->myNode->myOutputs[myDraggedOutput.mySecond];
					bool connectionMismatch = port->myType != draggedPort->myType;

					if (!connectionMismatch)
					{
						if (port->TryConnect(draggedPort))
						{
							if (ImGui::IsMouseReleased(0))
							{
                                myCommands.ExecuteCommand(new Editor_NodeConnectCommand(draggedPort, port));
							}
							connectionError = ConnectionValid;
						}
						else
						{
							locDisplayWarning("Error, Nodegraph must not be cyclic!");
							connectionError = ConnectionMisMatch;
						}
					}
					else
					{
						locDisplayWarning("Error, Port type mismatch!");
						connectionError = ConnectionMisMatch;
					}
				}
				else if (ImGui::IsMouseClicked(0))
				{
					myDraggedOutput = MC_MakePair<Editor_NodeProperties*, u32>(myOutputToPropertyMap.At(port->myConnectedPort), port->myConnectedPort->myNode->myOutputs.Find(port->myConnectedPort));
                    myCommands.ExecuteCommand(new Editor_NodeDisconnectCommand(port->myConnectedPort, port));
				}
			}

			if (port->myConnectedPort != nullptr)
			{
				Editor_NodeProperties* prop0 = myOutputToPropertyMap.At(port->myConnectedPort);
				Editor_NodeProperties* prop1 = myInputToPropertyMap.At(port);
				connections.Add({ prop0, port->myConnectedPort, prop1, port, hovered ? IM_COL32(255, 255, 255, 255) : IM_COL32(100, 100, 100, 255) });
			}
		}

		ImGui::SetCursorScreenPos(rect_min);
		if (ImGui::InvisibleButton("node", props->mySize))
		{
			mySelection.Clear();
			mySelection.myNodes.Add(props);
		}

		if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0))
			props->myPosition = props->myPosition + ImGui::GetIO().MouseDelta;

		ImGui::PopID();
	}

	// Display nodes
	for (s32 node_idx = 0; node_idx < myNodeProperties.Count(); node_idx++)
	{
		Editor_NodeProperties* prop = myNodeProperties[node_idx];

		ImGui::PushID(prop->myID);
		locDrawNode(drawList, prop, offset);
		ImGui::PopID();
	}

	drawList->ChannelsSetCurrent(0);
	for (const ConnectionCurve& curve : connections)
	{
		MC_Vector2f p0 = locGetGlobalOutputPortPosition(curve.outProps, curve.outProps->myNode->myOutputs.Find(curve.outPort), offset) + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
		MC_Vector2f p1 = locGetGlobalInputPortPosition(curve.inProps, curve.inProps->myNode->myInputs.Find(curve.inPort), offset) + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
		locDrawBezierCurve(drawList, p0, p1, curve.col);
	}

	if (!ImGui::IsMouseDown(0) && !ImGui::GetIO().KeyShift)
	{
		myDraggedOutput = MC_MakePair<Editor_NodeProperties*, u32>(nullptr, 0);
	}
	if (myDraggedOutput.myFirst != nullptr)
	{
		MC_Vector2f p0 = locGetGlobalOutputPortPosition(myDraggedOutput.myFirst, myDraggedOutput.mySecond, offset) + MC_Vector2f(NODE_SLOT_RADIUS, NODE_SLOT_RADIUS);
		ImU32 color = (connectionError == ConnectionMisMatch) ? IM_COL32(200, 100, 100, 255) : ((connectionError == ConnectionValid) ? IM_COL32(100, 200, 100, 255) : IM_COL32(100, 100, 100, 255));
		locDrawBezierCurve(drawList, p0, ImGui::GetIO().MousePos, color);
	}
	drawList->ChannelsMerge();

	//TODO: Custom Key bindings
	if (ImGui::IsKeyPressed(46))
	{
		if (mySelection.myNodes.Count())
		{
			for (s32 nodeIdx = 0; nodeIdx < mySelection.myNodes.Count(); ++nodeIdx)
			{
				Editor_NodeProperties* props = mySelection.myNodes[nodeIdx];
				myCommands.ExecuteCommand(new Editor_RemoveNodeCommand(this, props->myNode, NG_NodesModule::GetNodeUID(), props->myLabel, props->myPosition));
			}
		}
		else if (mySelection.myConnections.Count())
		{

		}
		mySelection.Clear();
	}

	if (ImGui::GetIO().KeyCtrl)
	{
		if (ImGui::IsKeyPressed('Z'))
		{
			myCommands.Undo();
		}
		else if (ImGui::IsKeyPressed('Y'))
		{
			myCommands.Redo();
		}
	}

	static const char* contextMenuLabel = "context_menu";
	if (ImGui::IsWindowHovered() && !ImGui::IsAnyItemActive())
	{
		if (ImGui::IsMouseDragging(2, 0.0f))
		{
			myScrolling = myScrolling + ImGui::GetIO().MouseDelta;
		}
		if (ImGui::IsMouseClicked(1))
		{
			ImGui::OpenPopup(contextMenuLabel);
		}
	}

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
	if (ImGui::BeginPopup(contextMenuLabel))
	{
		ShowNodeCreationContextMenu(MC_Vector2f(ImGui::GetMousePosOnOpeningCurrentPopup()) - offset);
		ImGui::EndPopup();
	}
	ImGui::PopStyleVar();

	ImGui::EndChild();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
}

void Editor_NodeEditor::CreateNode(NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition)
{
	myNodeProperties.Add(new Editor_NodeProperties(aNode, aNodeLabel, aNodeUID, aPosition));

	for (NG_InputPort* port : aNode->myInputs)
	{
		myInputToPropertyMap.Insert(port, myNodeProperties.GetLast());
	}

	for (NG_OutputPort* port : aNode->myOutputs)
	{
		myOutputToPropertyMap.Insert(port, myNodeProperties.GetLast());
	}

	myGraph->AddNode(aNode);
}

void Editor_NodeEditor::RemoveNode(NG_Node* aNode)
{
	myGraph->RemoveNode(aNode);

	for (s32 propIdx = 0; propIdx < myNodeProperties.Count(); ++propIdx)
	{
		Editor_NodeProperties* props = myNodeProperties[propIdx];
		if (props->myNode == aNode)
		{
			myNodeProperties.RemoveAtIndex(propIdx);

			for (NG_InputPort* port : aNode->myInputs)
			{
				myInputToPropertyMap.Remove(port);
			}

			for (NG_OutputPort* port : aNode->myOutputs)
			{
				myOutputToPropertyMap.Remove(port);
			}

			delete props;
			return;
		}
	}
}