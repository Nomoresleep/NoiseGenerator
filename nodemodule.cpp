#include "nodemodule.h"
#include "nodegraph.h"

NodeGraph* theNodeGraph = nullptr;

MC_HashMap<const char*, NodesModule::NodeCreationData> NodesModule::ourRegisteredNodes;
MC_GrowingArray<const char*> NodesModule::ourRegisteredNodesNames(32, 32);

bool NodeComparer::Equals(Node* aNode, const char* nodeName)
{
	return strcmp(aNode->myLabel, nodeName) == 0;
}

Node* NodesModule::Create(const char* aNodeName, const MC_Vector2f& aPosition)
{
	NodesModule::NodeCreationData* data = ourRegisteredNodes.GetIfExists(aNodeName);
	assert(data != nullptr);
	if (data->myIsSingleton && theNodeGraph->myNodes.Find2<NodeComparer, const char*>(aNodeName, 0) != -1)
	{
		return nullptr;
	}
	return data->myCreationFunction(aNodeName, aPosition);
}