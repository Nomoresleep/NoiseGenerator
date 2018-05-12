#pragma once 

#include <math.h> // fmodf
#include "MC_GrowingArray.h"
#include "MC_StackList.h"
#include "MC_ScopedPtr.h"
#include "MC_Vector.h"
#include "MC_HashMap.h"
#include "MC_Pair.h"
#include "NG_Node.h"
#include "NG_NodeModule.h"
#include "NG_NodeLibrary.h"

class NG_NodeGraphChangeListener
{
public:
	virtual void OnNodeAdded(NG_Node* aNode, u32 aNodeUID, const char* aNodeLabel, const MC_Vector2f& aPosition) = 0;
	virtual void OnNodeRemoved(NG_Node* aNode) = 0;
};

class NG_NodeGraph
{
public:
	NG_NodeGraph();

	bool ContainsNodeOfName(const char* aNodeName);
	static bool IsCyclicFromNode(NG_Node* aNode);

	void AddNode(NG_Node* aNewNode, const char* aNodeName, const MC_Vector2f& aPosition);
	void RemoveNode(NG_Node* aNode);

	void RegisterListener(NG_NodeGraphChangeListener* aListener) { myListeners.Add(aListener); }
	void UnregisterListener(NG_NodeGraphChangeListener* aListener) { myListeners.Remove(aListener); }

	const MC_GrowingArray<NG_Node*>& GetNodes() const { return myNodes; };
private:
	MC_GrowingArray<NG_NodeGraphChangeListener*> myListeners;
	MC_GrowingArray<NG_Node*> myNodes;
};
