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

class NodeGraphChangeListener
{
public:
	virtual void OnNodeAdded(Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition) = 0;
	virtual void OnNodeRemoved(Node* aNode) = 0;
};

class NodeGraph
{
	typedef MC_GrowingArray<MC_ScopedPtr<Node>> NodeList;
public:
	NodeGraph();

	bool ContainsNodeOfName(const char* aNodeName);
	static bool IsCyclicFromNode(Node* aNode);

	void AddNode(Node* aNewNode, const char* aNodeName, const MC_Vector2f& aPosition);

	void RegisterListener(NodeGraphChangeListener* aListener) { myListeners.Add(aListener); }
	void UnregisterListener(NodeGraphChangeListener* aListener) { myListeners.Remove(aListener); }

	const NodeList& GetNodes() const { return myNodes; };
private:
	MC_GrowingArray<NodeGraphChangeListener*> myListeners;
	MC_GrowingArray<MC_ScopedPtr<Node>> myNodes;
};
