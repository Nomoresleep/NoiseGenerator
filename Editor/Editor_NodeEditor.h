#pragma once

#include "Editor_CommandList.h"
#include "NG_NodeGraph.h"
#include "MC_GrowingArray.h"
#include "MC_ArrayMap.h"
#include "imgui/imgui.h"

static const f32 NODE_SLOT_RADIUS = 6.0f;
static const MC_Vector2f NODE_PORT_SIZE = MC_Vector2f(2.0f * NODE_SLOT_RADIUS, 2.0f * NODE_SLOT_RADIUS);
static const MC_Vector2f NODE_WINDOW_PADDING = MC_Vector2f(8.0f, 4.0f);
static const f32 NODE_PROPERTY_WIDTH = 120.0f;

struct Editor_NodeProperties;

static ImU32 GetColorFromPortType(NG_Port::Type aType)
{
	switch (aType)
	{
	case NG_Port::FloatPort:
		return IM_COL32(0, 95, 0, 255);
	case NG_Port::IntPort:
		return IM_COL32(66, 150, 250, 255);
	case NG_Port::UIntPort:
		return IM_COL32(0, 0, 0, 255);
	}
	return IM_COL32(255, 255, 255, 255);
}

struct Editor_NodeGraphSelection
{
	MC_GrowingArray<Editor_NodeProperties*> myNodes;
	MC_GrowingArray<int*> myConnections;

	void Clear() 
	{
		myNodes.RemoveAll();
		myConnections.RemoveAll();
	}
};

class Editor_NodeEditor
{
	enum ConnectionStatus
	{
		ConnectionUnknown,
		ConnectionValid,
		ConnectionMisMatch
	};

public:
	Editor_NodeEditor(NG_NodeGraph* aGraph)
		: myGraph(aGraph)
		, myDraggedOutput(nullptr, 0)
		, myScrolling(0.0f, 0.0f)
	{
		NodeLibrary::RegisterNodeTypes();
	};
	~Editor_NodeEditor()
	{
		NodeLibrary::UnregisterNodeTypes();
	}
	void Display();
	void ShowNodeCreationContextMenu(const MC_Vector2f& aCreateLocation);
    void ShowCommandDialogHelper();

	void Undo();
	void Redo();

	void CreateNode(NG_Node* aNode, const char* aNodeLabel, const MC_Vector2f& aPosition);
	void RemoveNode(NG_Node* aNode);

	const MC_GrowingArray<Editor_NodeProperties*>& GetNodeProperties() const { return myNodeProperties; }
private:

	MC_Vector2f myScrolling;

	MC_Pair<Editor_NodeProperties*, u32> myDraggedOutput;

	Editor_CommandList myCommands;

	Editor_NodeGraphSelection mySelection;
	MC_GrowingArray<Editor_NodeProperties*> myNodeProperties;
	MC_ArrayMap<NG_OutputPort*, Editor_NodeProperties*> myOutputToPropertyMap;
	MC_ArrayMap<NG_InputPort*, Editor_NodeProperties*> myInputToPropertyMap;
	NG_NodeGraph* myGraph;
};