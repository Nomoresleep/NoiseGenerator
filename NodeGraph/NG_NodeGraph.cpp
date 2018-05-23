#include "NG_NodeGraph.h"

NG_NodeGraph::NG_NodeGraph()
	: myNodes(32)
{
}

bool NG_NodeGraph::IsCyclicFromNode(NG_Node* aNode)
{
	MC_StackList<NG_Node*> queue;
	queue.Add(aNode);
	while (!queue.IsEmpty())
	{
		NG_Node* node = queue.Pop();
		for (s32 outPortIdx = 0; outPortIdx < node->myOutputs.Count(); ++outPortIdx)
		{
			NG_OutputPort* outPort = node->myOutputs[outPortIdx];
			for (s32 inPortIdx = 0; inPortIdx < outPort->myConnectedInputs.Count(); ++inPortIdx)
			{
				NG_InputPort* inPort = outPort->myConnectedInputs[inPortIdx];
				if (inPort->myNode == aNode)
					return true;

				queue.Add(inPort->myNode);
			}
		}
	}
	return false;
}

void NG_NodeGraph::AddNode(NG_Node* aNewNode)
{
	myNodes.Add(aNewNode);
}

void NG_NodeGraph::RemoveNode(NG_Node* aNode)
{
	myNodes.Remove(aNode);
}