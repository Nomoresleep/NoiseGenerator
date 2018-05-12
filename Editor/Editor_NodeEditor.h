#pragma once

#include "nodegraph.h"
#include "MC_GrowingArray.h"
#include "imgui/imgui.h"

struct NodeEditorProperties;
class Node;
class NodeGraph;

static ImU32 GetColorFromPortType(PortType aType)
{
	switch (aType)
	{
	case FloatPort:
		return IM_COL32(0, 95, 0, 255);
	case IntPort:
		return IM_COL32(66, 150, 250, 255);
	case UIntPort:
		return IM_COL32(0, 0, 0, 255);
	}
	return IM_COL32(255, 255, 255, 255);
}

class NodeEditor
{
public:
	NodeEditor(NodeGraph* aGraph)
		: myGraph(aGraph) {};
	void Display();

	void NodeGraphAddedNode(Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition);
private:

	MC_GrowingArray<NodeEditorProperties*> myNodeRenderer;

	NodeGraph* myGraph;
};