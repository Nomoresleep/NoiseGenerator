#pragma once

#include "MC_HashMap.h"
#include "MC_GrowingArray.h"
#include "MC_Vector.h"
#include "MC_Base.h"

class NG_Node;
class NG_NodeGraph;

struct NG_NodesModule
{
	typedef NG_Node*(*NodeCreationFunction)();
	struct NodeCreationData
	{
		NodeCreationFunction myCreationFunction;
	};

	static NG_Node* Create(const char* aNodeName);
	static MC_HashMap<const char*, NodeCreationData> ourRegisteredNodes;
	static MC_GrowingArray<const char*> ourRegisteredNodesNames;
	static u32 ourNodeCounter;

	//TODO: This is ugly! :D
	static u32 GetNodeUID() { return ++ourNodeCounter; }
};

template <typename Type>
struct NG_RegisterNodeType
{
	NG_RegisterNodeType(const char* aNodeName)
	{
		NG_NodesModule::NodeCreationData* func = NG_NodesModule::ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func == nullptr);
		NG_NodesModule::ourRegisteredNodes[aNodeName] = { Create };
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

struct NG_UnregisterNodeType
{
	NG_UnregisterNodeType(const char* aNodeName)
	{
		NG_NodesModule::ourRegisteredNodes.RemoveByKey(aNodeName);
		NG_NodesModule::ourRegisteredNodesNames.Remove(aNodeName);
	}
};