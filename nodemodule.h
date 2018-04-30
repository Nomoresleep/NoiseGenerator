#pragma once
#include "MCommon/MC_HashMap.h"
#include "MCommon/MC_GrowingArray.h"
#include "MCommon/MC_Vector.h"
class Node;

struct NodesModule
{
	typedef Node*(*NodeCreationFunction)(const char* aNodeName, const MC_Vector2f& aPosition);

	static Node* Create(const char* aNodeName, const MC_Vector2f& aPosition)
	{
		NodesModule::NodeCreationFunction* func = ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func != nullptr);
		return (*func)(aNodeName, aPosition);
	}
	static MC_HashMap<const char*, NodeCreationFunction> ourRegisteredNodes;
	static MC_GrowingArray<const char*> ourRegisteredNodesNames;
};

MC_HashMap<const char*, NodesModule::NodeCreationFunction> NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NodesModule::ourRegisteredNodesNames(32, 32);

template <typename Type>
struct RegisterNodeType
{
	RegisterNodeType(const char* aNodeName)
	{
		NodesModule::NodeCreationFunction* func = NodesModule::ourRegisteredNodes.GetIfExists(aNodeName);
		assert(func == nullptr);
		NodesModule::ourRegisteredNodes[aNodeName] = Create;
		assert(NodesModule::ourRegisteredNodes.GetIfExists(aNodeName));
		NodesModule::ourRegisteredNodesNames.Add(aNodeName);
	}

	//avoid ugly lamdas!
	static Node* Create(const char* nodeName, const MC_Vector2f& aPosition) {
		Type* newNode = new Type(theNodeGraph->myNodes.Count(), nodeName, aPosition);
		theNodeGraph->myNodes.Add(newNode);
		return newNode;
	}
};