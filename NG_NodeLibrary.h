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
            source.Format("result = %s;\n", myInputs[0]->myConnectedPort->myData.myVariableName);
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
        MC_String varName = MC_Strfmt<32>("perlinNoise2D%d", myUID);
		MC_String source;
		source.Format("float %s = PerlinNoise2D(x, y);\n", varName);
		aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[0]->myData.myVariableName = varName;
    };
private:
	PerlinNoiseConstants myConstants;
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}