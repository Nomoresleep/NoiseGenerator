#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
class ConstantNode : public NG_Node
{
public:
    ConstantNode()
	{
        AddOutputPort(new OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

class ResultNode : public NG_Node
{
public:
    ResultNode()
    {
        AddInputPort(new InputPort(this, NG_Port::FloatPort));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        if (myInputs[0]->myConnectedPort)
        {
            MC_String source;
            const NG_Node* connectedNode = myInputs[0]->myConnectedPort->myNode;
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

class PerlinNoise2D : public NG_Node
{
public:
	PerlinNoise2D()
	{
		AddInputPort(new InputPort(this, NG_Port::FloatPort));
		AddInputPort(new InputPort(this, NG_Port::FloatPort));
		AddInputPort(new InputPort(this, NG_Port::UIntPort));

		//Add Properties

		AddOutputPort(new OutputPort(this, NG_Port::FloatPort));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
    
    };
private:
	PerlinNoiseConstants myConstants;
};

static void locRegisterNodeTypes()
{
    NG_RegisterNodeType<ConstantNode<f32>>("Constants/FloatConstantNode");
    NG_RegisterNodeType<ConstantNode<s32>>("Constants/IntConstantNode");
    NG_RegisterNodeType<ConstantNode<u32>>("Constants/UIntConstantNode");
    NG_RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
    NG_RegisterNodeType<ResultNode>("ResultNode", true);
}