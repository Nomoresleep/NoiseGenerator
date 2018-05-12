#pragma once

#include "MC_HashMap.h"
#include "MC_GrowingArray.h"
#include "MC_Vector.h"
#include "MC_Base.h"

class NG_Node;
class NG_NodeGraph;

struct NG_NodeComparer
{
	static bool Equals(NG_Node* aNode, const char* nodeName);
};

struct NG_NodesModule
{
	typedef NG_Node*(*NodeCreationFunction)();
	struct NodeCreationData
	{
		NodeCreationFunction myCreationFunction;
		bool myIsSingleton;
	};

	static NG_Node* Create(NG_NodeGraph* aNodegraph, const char* aNodeName, const MC_Vector2f& aPosition);
	static MC_HashMap<const char*, NodeCreationData> ourRegisteredNodes;
	static MC_GrowingArray<const char*> ourRegisteredNodesNames;
};

template <typename Type>
struct NG_RegisterNodeType
{
	NG_RegisterNodeType(const char* aNodeName, bool isSingleton = false)
	{
		NG_NodesModule::NodeCreationData* func = NG_NodesModule::ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func == nullptr);
		NG_NodesModule::ourRegisteredNodes[aNodeName] = { Create, isSingleton };
		assert(NG_NodesModule::ourRegisteredNodes.GetIfExists(aNodeName));
		NG_NodesModule::ourRegisteredNodesNames.Add(aNodeName);
	}

private:
	//avoid ugly lamdas!
    static NG_Node* Create() {
		Type* newNode = new Type();
		return newNode;
	}
};