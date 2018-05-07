#include "node.h"
#include "nodegraph.h"

bool InputPort::Connect(OutputPort* aConnectedPort)
{
    if (myConnectedPort) myConnectedPort->myConnectedInputs.Remove(this);
    OutputPort* prevPort = myConnectedPort;
    myConnectedPort = aConnectedPort;
    if (myConnectedPort) myConnectedPort->myConnectedInputs.Add(this);

    bool result = NodeGraph::IsCyclicFromNode(myNode);
    if(result) assert(Connect(prevPort));
    return !result;
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