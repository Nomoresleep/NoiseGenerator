#include "node.h"
#include "nodegraph.h"

void InputPort::Connect(OutputPort* aConnectedPort)
{
	if (myConnectedPort) myConnectedPort->myConnectedInputs.Remove(this);
	myConnectedPort = aConnectedPort;
	if (myConnectedPort) myConnectedPort->myConnectedInputs.Add(this);
}

bool InputPort::TryConnect(OutputPort* aConnectedPort)
{
	OutputPort* prevPort = myConnectedPort;
	Connect(aConnectedPort);
	bool result = NodeGraph::IsCyclicFromNode(myNode);
	Connect(prevPort);
	return !result;
}

u32 Node::ConnectedInputCount() const
{
    u32 inputCount = 0;
    for (s32 inPortIdx = 0; inPortIdx < myInputs.Count(); ++inPortIdx)
    {
        InputPort* inPort = myInputs[inPortIdx];
        if (inPort->myConnectedPort != nullptr)
        {
            inputCount++;
        }
    }
    return inputCount;
}

void Node::AddInputPort(InputPort* anInputPort)
{
	myInputs.Add(anInputPort);
}

void Node::AddOutputPort(OutputPort* anOutputPort)
{
	myOutputs.Add(anOutputPort);
}