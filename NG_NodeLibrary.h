#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
class ConstantNode : public NG_Node
{
public:
    ConstantNode()
	{
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

class ResultNode : public NG_Node
{
public:
    ResultNode()
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
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
		AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
		AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
		AddInputPort(new NG_InputPort(this, NG_Port::UIntPort));

		//Add Properties

		AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
    
    };
private:
	PerlinNoiseConstants myConstants;
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}