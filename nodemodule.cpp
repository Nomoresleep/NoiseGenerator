#include "nodemodule.h"
#include "nodegraph.h"

MC_HashMap<const char*, NodesModule::NodeCreationData> NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NodesModule::ourRegisteredNodesNames(32);

bool NodeComparer::Equals(Node* aNode, const char* nodeName)
{
	//TODO:Resolve this for node singletons
	return false;// strcmp(aNode->myLabel, nodeName) == 0;
}

Node* NodesModule::Create(NodeGraph* aNodegraph, const char* aNodeName, const MC_Vector2f& aPosition)
{
	NodesModule::NodeCreationData* data = ourRegisteredNodes.GetIfExists(aNodeName);
	assert(data != nullptr);
	if (data->myIsSingleton && aNodegraph->GetNodes().Find2<NodeComparer, const char*>(aNodeName, 0) != -1)
	{
		return nullptr;
	}
	Node* newNode = data->myCreationFunction();
    aNodegraph->AddNode(newNode, aNodeName, aPosition);
    return newNode;
}