#include "NG_Node.h"
#include "NG_NodeGraph.h"

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
	bool result = NG_NodeGraph::IsCyclicFromNode(myNode);
	Connect(prevPort);
	return !result;
}

u32 NG_Node::ConnectedInputCount() const
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

void NG_Node::AddInputPort(InputPort* anInputPort)
{
	myInputs.Add(anInputPort);
}

void NG_Node::AddOutputPort(OutputPort* anOutputPort)
{
	myOutputs.Add(anOutputPort);
}