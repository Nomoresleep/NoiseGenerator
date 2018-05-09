#pragma once

#include "nodegraph.h"
#include "MC_BinaryHeap.h"

struct NodeComparator
{
    static bool LessThan(Node* a, Node* b) { return a->ConnectedInputCount() < b->ConnectedInputCount(); }
    static bool Equals(Node* a, Node* b) { return a->ConnectedInputCount() == b->ConnectedInputCount(); }
};

class GraphRunner
{
public:
    GraphRunner(NodeGraph* aNodegraph)
        : myNodegraph(aNodegraph)
    {}

    void Run()
    {
        MC_BinaryHeap<Node*, NodeComparator> pqueue(myNodegraph->myNodes.Count());
        GraphRunnerContext runnerContext;

        for (s32 nodeIdx = 0; nodeIdx < myNodegraph->myNodes.Count(); ++nodeIdx)
        {
            Node* node = myNodegraph->myNodes[nodeIdx];
            if (node->ConnectedInputCount() == 0)
                pqueue.Push(node);
        }

        while (!pqueue.IsEmpty())
        {
            Node* node = pqueue.Pop();
            node->OnTraverse(&runnerContext);
            for (s32 outPortIdx = 0; outPortIdx < node->myOutputs.Count(); ++outPortIdx)
            {
                OutputPort* outPort = node->myOutputs[outPortIdx];
                for (s32 inPortIdx = 0; inPortIdx < outPort->myConnectedInputs.Count(); ++inPortIdx)
                {
                    InputPort* inPort = outPort->myConnectedInputs[inPortIdx];
                    pqueue.Push(inPort->myNode);
                }
            }
        }
    }
private:
    NodeGraph* myNodegraph;
};