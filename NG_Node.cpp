#include "NG_Node.h"
#include "NG_NodeGraph.h"

void NG_InputPort::Connect(NG_OutputPort* aConnectedPort)
{
	if (myConnectedPort) myConnectedPort->myConnectedInputs.Remove(this);
	myConnectedPort = aConnectedPort;
	if (myConnectedPort) myConnectedPort->myConnectedInputs.Add(this);
}

bool NG_InputPort::TryConnect(NG_OutputPort* aConnectedPort)
{
	NG_OutputPort* prevPort = myConnectedPort;
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
        NG_InputPort* inPort = myInputs[inPortIdx];
        if (inPort->myConnectedPort != nullptr)
        {
            inputCount++;
        }
    }
    return inputCount;
}

void NG_Node::AddInputPort(NG_InputPort* anInputPort)
{
	myInputs.Add(anInputPort);
}

void NG_Node::AddOutputPort(NG_OutputPort* anOutputPort)
{
	myOutputs.Add(anOutputPort);
}