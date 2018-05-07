#pragma once
#include "MC_HashMap.h"
#include "MC_GrowingArray.h"
#include "MC_Vector.h"
#include "MC_Base.h"
class Node;
class NodeGraph;

struct NodeComparer
{
	static bool Equals(Node* aNode, const char* nodeName);
};

struct NodesModule
{
	typedef Node*(*NodeCreationFunction)(s32 aNodeID, const char* aNodeName, const MC_Vector2f& aPosition);
	struct NodeCreationData
	{
		NodeCreationFunction myCreationFunction;
		bool myIsSingleton;
	};

	static Node* Create(NodeGraph* aNodegraph, const char* aNodeName, const MC_Vector2f& aPosition);
	static MC_HashMap<const char*, NodeCreationData> ourRegisteredNodes;
	static MC_GrowingArray<const char*> ourRegisteredNodesNames;
};

template <typename Type>
struct RegisterNodeType
{
	RegisterNodeType(const char* aNodeName, bool isSingleton = false)
	{
		NodesModule::NodeCreationData* func = NodesModule::ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func == nullptr);
		NodesModule::ourRegisteredNodes[aNodeName] = { Create, isSingleton };
		assert(NodesModule::ourRegisteredNodes.GetIfExists(aNodeName));
		NodesModule::ourRegisteredNodesNames.Add(aNodeName);
	}

private:
	//avoid ugly lamdas!
    static Node* Create(s32 aNodeID, const char* nodeName, const MC_Vector2f& aPosition) {
		Type* newNode = new Type(aNodeID, nodeName, aPosition);
		return newNode;
	}
};