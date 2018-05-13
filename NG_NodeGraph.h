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

class NG_NodeGraph
{
public:
	NG_NodeGraph();

	static bool IsCyclicFromNode(NG_Node* aNode);

	void AddNode(NG_Node* aNewNode);
	void RemoveNode(NG_Node* aNode);

	const MC_GrowingArray<NG_Node*>& GetNodes() const { return myNodes; };
private:
	MC_GrowingArray<NG_Node*> myNodes;
};
