#include "NG_NodeModule.h"
#include "NG_NodeGraph.h"

MC_HashMap<const char*, NG_NodeModule::NodeCreationData> NG_NodeModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NG_NodeModule::ourRegisteredNodesNames(32);
u32 NG_NodeModule::ourNodeCounter = 0;

NG_Node* NG_NodeModule::Create(const char* aNodeName)
{
	NG_NodeModule::NodeCreationData* data = ourRegisteredNodes.GetIfExists(aNodeName);
	assert(data != nullptr);
	NG_Node* newNode = data->myCreationFunction();
    return newNode;
}