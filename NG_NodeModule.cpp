#include "NG_NodeModule.h"
#include "NG_NodeGraph.h"

MC_HashMap<const char*, NG_NodesModule::NodeCreationData> NG_NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NG_NodesModule::ourRegisteredNodesNames(32);
u32 NG_NodesModule::ourNodeCounter = 0;

NG_Node* NG_NodesModule::Create(const char* aNodeName)
{
	NG_NodesModule::NodeCreationData* data = ourRegisteredNodes.GetIfExists(aNodeName);
	assert(data != nullptr);
	NG_Node* newNode = data->myCreationFunction();
    return newNode;
}