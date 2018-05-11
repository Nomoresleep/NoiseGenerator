#pragma once 

#include "node.h"
#include "nodemodule.h"

template <typename Type>
class ConstantNode : public Node
{
public:
    ConstantNode()
	{
        AddOutputPort(new OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

class ResultNode : public Node
{
public:
    ResultNode()
    {
        AddInputPort(new InputPort(this, FloatPort));
    };

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) const override 
    {
        if (myInputs[0]->myConnectedPort)
        {
            MC_String source;
            const Node* connectedNode = myInputs[0]->myConnectedPort->myNode;
			//TODO: fix node ids
            s32 nodeID = 0;
            s32 outputIndex = connectedNode->myOutputs.Find(myInputs[0]->myConnectedPort);
            source.Format("result = node_%d_%d;\n", nodeID, outputIndex);
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
    };
};

struct PerlinNoiseConstants
{
	f32 myFrequency;
	f32 myAmplitude;
	u32 mySeed;
};

class PerlinNoise2D : public Node
{
public:
	PerlinNoise2D()
	{
		AddInputPort(new InputPort(this, PortType::FloatPort));
		AddInputPort(new InputPort(this, PortType::FloatPort));
		AddInputPort(new InputPort(this, PortType::UIntPort));

		//Add Properties

		AddOutputPort(new OutputPort(this, PortType::FloatPort));
	}

    void OnTraverse(GraphRunnerContext* aGraphRunnerContext) const override 
    {
    
    };
private:
	PerlinNoiseConstants myConstants;
};

static void locRegisterNodeTypes()
{
    RegisterNodeType<ConstantNode<f32>>("Constants/FloatConstantNode");
    RegisterNodeType<ConstantNode<s32>>("Constants/IntConstantNode");
    RegisterNodeType<ConstantNode<u32>>("Constants/UIntConstantNode");
    RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
    RegisterNodeType<ResultNode>("ResultNode", true);
}