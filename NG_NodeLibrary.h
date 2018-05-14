#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
class ConstantNode : public NG_Node
{
public:
    ConstantNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

class ResultNode : public NG_Node
{
public:
    ResultNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        if (myInputs[0]->myConnectedPort)
        {
            MC_String source;
            const NG_Node* connectedNode = myInputs[0]->myConnectedPort->myNode;
            s32 outputIndex = connectedNode->myOutputs.Find(myInputs[0]->myConnectedPort);
            source.Format("result = node_%d_%d;\n", connectedNode->myUID, outputIndex);
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
	PerlinNoise2D(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
		AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
		AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
		AddInputPort(new NG_InputPort(this, NG_Port::UIntPort));

		AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
		MC_String source;
		source.Format("float node_%d_0 = PerlinNoise2D(x, y);\n", myUID);
		aGraphRunnerContext->myGeneratedSource.Add(source);
    };
private:
	PerlinNoiseConstants myConstants;
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}