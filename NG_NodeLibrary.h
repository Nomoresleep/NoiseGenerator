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

template <typename Type, typename ConstBuildIn>
class BuildInConstantNode : public NG_Node
{
public:
    BuildInConstantNode(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>()));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        (void)aGraphRunnerContext;
        myOutputs[0]->myData.myVariableName = ConstBuildIn::BuildIn;
    }
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

class PerlinNoise2D : public NG_Node
{
public:
	PerlinNoise2D(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
		AddInputPort(new NG_InputPort(this, NG_Port::Vec2Port));

		AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        MC_String varName = MC_Strfmt<32>("perlinNoise2D%d", myUID);
        MC_String argName;
        if (myInputs[0]->myConnectedPort)
        {
            argName = myInputs[0]->myConnectedPort->myData.myVariableName;
        }
		MC_String source;
		source.Format("float %s = PerlinNoise2D(%s);\n", varName, argName);
		aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[0]->myData.myVariableName = varName;
    };
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}