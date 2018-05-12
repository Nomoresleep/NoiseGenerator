#pragma once 

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_StackList.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_HashMap.h"
#include "MC_Pair.h"
#include "node.h"
#include "nodemodule.h"
#include "nodelibrary.h"

static OutputPort* g_draggedOutput = nullptr;

class NodeEditor;

class NodeGraph
{
	typedef MC_GrowingArray<MC_ScopedPtr<Node>> NodeList;
public:
	NodeGraph();

	bool ContainsNodeOfName(const char* aNodeName);
	static bool IsCyclicFromNode(Node* aNode);

	void AddNode(Node* aNewNode, const char* aNodeName, const MC_Vector2f& aPosition);
	void SetEditor(NodeEditor* anEditor) { myEditor = anEditor; }

	const NodeList& GetNodes() const { return myNodes; };
private:
	NodeEditor* myEditor;
	MC_GrowingArray<MC_ScopedPtr<Node>> myNodes;
};
