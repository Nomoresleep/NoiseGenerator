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
	CalculateSize();
}

void Node::AddOutputPort(OutputPort* anOutputPort)
{
	myOutputs.Add(anOutputPort);
	CalculateSize();
}

void Node::CalculateSize()
{
	MC_Vector2f textSize = ImGui::CalcTextSize(myLabel);
	mySize = MC_Vector2f(MC_Max(textSize.x, NODE_PROPERTY_WIDTH) + 2.0f * NODE_WINDOW_PADDING.x, textSize.y + 2.0f * NODE_WINDOW_PADDING.y);
	mySize.y += MC_Max(myInputs.Count(), myOutputs.Count()) * ImGui::GetItemsLineHeightWithSpacing() + ImGui::GetStyle().ItemSpacing.y;
}