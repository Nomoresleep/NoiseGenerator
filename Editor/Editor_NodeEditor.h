#pragma once

#include "nodegraph.h"
#include "MC_GrowingArray.h"

struct NodeEditorProperties;
class Node;
class NodeGraph;

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