#include "NG_NodeModule.h"
#include "NG_NodeGraph.h"

MC_HashMap<const char*, NG_NodesModule::NodeCreationData> NG_NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NG_NodesModule::ourRegisteredNodesNames(32);

bool NG_NodeComparer::Equals(NG_Node* aNode, const char* nodeName)
{
	//TODO:Resolve this for node singletons
	return false;// strcmp(aNode->myLabel, nodeName) == 0;
}

NG_Node* NG_NodesModule::Create(NG_NodeGraph* aNodegraph, const char* aNodeName, const MC_Vector2f& aPosition)
{
	NG_NodesModule::NodeCreationData* data = ourRegisteredNodes.GetIfExists(aNodeName);
	assert(data != nullptr);
	if (data->myIsSingleton && aNodegraph->GetNodes().Find2<NG_NodeComparer, const char*>(aNodeName, 0) != -1)
	{
		return nullptr;
	}
	NG_Node* newNode = data->myCreationFunction();
    aNodegraph->AddNode(newNode, aNodeName, aPosition);
    return newNode;
}