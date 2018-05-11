#include "nodegraph.h"
#include "Editor_NodeEditor.h"

NodeGraph::NodeGraph()
	: myNodes(32)
{
}

bool NodeGraph::ContainsNodeOfName(const char* aNodeName)
{
	return myNodes.Find2<NodeComparer, const char*>(aNodeName, 0) != -1;
}

bool NodeGraph::IsCyclicFromNode(Node* aNode)
{
	MC_StackList<Node*> queue;
	queue.Add(aNode);
	while (!queue.IsEmpty())
	{
		Node* node = queue.Pop();
		for (s32 outPortIdx = 0; outPortIdx < node->myOutputs.Count(); ++outPortIdx)
		{
			OutputPort* outPort = node->myOutputs[outPortIdx];
			for (s32 inPortIdx = 0; inPortIdx < outPort->myConnectedInputs.Count(); ++inPortIdx)
			{
				InputPort* inPort = outPort->myConnectedInputs[inPortIdx];
				if (inPort->myNode == aNode)
					return true;

				queue.Add(inPort->myNode);
			}
		}
	}
	return false;
}

void NodeGraph::AddNode(Node* aNewNode, const char* aNodeName, const MC_Vector2f& aPosition)
{
	myNodes.Add(aNewNode);
	if (myEditor)
	{
		myEditor->NodeGraphAddedNode(aNewNode, myNodes.Count(), aNodeName, aPosition);
	}
}