#pragma once 

#include "NG_Node.h"
#include "NG_NodeModule.h"

template <typename Type>
const char* GetVariableTypeFromType();

template <typename Type>
class ConstantNode : public NG_Node
{
private:
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    ConstantNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), false));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override;

	Type myConstant;
};

template <typename Type, typename ConstBuildIn>
class BuildInConstantNode : public NG_Node
{
private:
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    BuildInConstantNode(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        (void)aGraphRunnerContext;
        myOutputs[OutIdx]->myData.myVariableName = ConstBuildIn::BuildIn;
    }
};

template <typename Type, typename ConstOp>
class OperationNodeTwoWay : public NG_Node
{
private:
    enum InPortIdx
    {
        In0Idx = 0,
        In1Idx = 1,
    };
    enum OutPortIdx
    {
        OutIdx = 0
    };
public:
    OperationNodeTwoWay(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, GetPortType<Type>()));
        AddInputPort(new NG_InputPort(this, GetPortType<Type>()));

        AddOutputPort(new NG_OutputPort(this, GetPortType<Type>(), true));
    }

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
        MC_String varName = MC_Strfmt<64>("%s%d", ConstOp::Name, myUID);
		MC_String param0 = GetInputParameterString<Type>(In0Idx);
		MC_String param1 = GetInputParameterString<Type>(In1Idx);
        MC_String source;
        source.Format("%s %s = %s %s %s;\n", GetVariableTypeFromType<Type>(), varName, param0, ConstOp::Operator, param1);
        aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[OutIdx]->myData.myVariableName = varName;
    }
};

class ResultNode : public NG_Node
{
private:
    enum InPortIdx
    {
        RedInIdx = 0,
        GreenInIdx = 1,
        BlueInIdx = 2,
    };
public:
    ResultNode(u32 aNodeUID)
		: NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        MC_String source;
		MC_String param0 = GetInputParameterString<f32>((u32)RedInIdx);
		MC_String param1 = GetInputParameterString<f32>(GreenInIdx);
		MC_String param2 = GetInputParameterString<f32>(BlueInIdx);

		source.Format("result = vec3(%s, %s, %s);\n", param0, param1, param2);
		aGraphRunnerContext->myGeneratedSource.Add(source);
    };
};

class Split1To2Node : public NG_Node
{
private:
    enum InPortIdx
    {
        InIdx = 0,
    };

    enum OutPortIdx
    {
        Out0Idx = 0,
        Out1Idx = 1
    };
public:
    Split1To2Node(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::Vec2Port));

        AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
        AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
		MC_String varName = MC_String(myInputs[InIdx]->myConnectedPort ? MC_Strfmt<32>("%s.r", myInputs[InIdx]->myConnectedPort->myData.myVariableName) : MC_Strfmt<32>("%f", myInputs[InIdx]->myData.myValue.myVec2.x));
		myOutputs[Out0Idx]->myData.myVariableName = varName;
		varName = MC_String(myInputs[InIdx]->myConnectedPort ? MC_Strfmt<32>("%s.g", myInputs[InIdx]->myConnectedPort->myData.myVariableName) : MC_Strfmt<32>("%f", myInputs[InIdx]->myData.myValue.myVec2.y));
		myOutputs[Out1Idx]->myData.myVariableName = varName;
    };
};

class Combine2To1Node : public NG_Node
{
private:
    enum InPortIdx
    {
        In0Idx = 0,
        In1Idx = 0,
    };

    enum OutPortIdx
    {
        Out0Idx = 0,
    };
public:
    Combine2To1Node(u32 aNodeUID)
        : NG_Node(aNodeUID)
    {
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));
        AddInputPort(new NG_InputPort(this, NG_Port::FloatPort));

        AddOutputPort(new NG_OutputPort(this, NG_Port::Vec2Port, true));
    };

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override
    {
        if (myInputs[In0Idx]->myConnectedPort && myInputs[In1Idx]->myConnectedPort)
        {
            MC_String varName = MC_Strfmt<64>("combine%d", myUID);
            MC_String source;
            source.Format("vec2 %s = vec2(%f, %f);\n", varName, myInputs[In0Idx]->myConnectedPort->myData.myValue.myFloat, myInputs[In1Idx]->myConnectedPort->myData.myValue.myFloat);
            myOutputs[Out0Idx]->myData.myVariableName = varName;
            aGraphRunnerContext->myGeneratedSource.Add(source);
        }
    };
};

class PerlinNoise2D : public NG_Node
{
private:
    enum InPortIdx
    {
        UVInIdx = 0
    };
    enum OutPortIdx
    {
        PerlinOutIdx = 0
    };
public:
	PerlinNoise2D(u32 aNodeUID)
		: NG_Node(aNodeUID)
	{
		AddInputPort(new NG_InputPort(this, NG_Port::Vec2Port));

		AddOutputPort(new NG_OutputPort(this, NG_Port::FloatPort, true));
	}

    void OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const override 
    {
        MC_String varName = MC_Strfmt<32>("perlinNoise2D%d", myUID);
        MC_String argName;
        if (myInputs[UVInIdx]->myConnectedPort)
        {
            argName = myInputs[UVInIdx]->myConnectedPort->myData.myVariableName;
        }
		MC_String source;
		source.Format("float %s = PerlinNoise2D(%s);\n", varName, argName);
		aGraphRunnerContext->myGeneratedSource.Add(source);
        myOutputs[PerlinOutIdx]->myData.myVariableName = varName;
    };
};

namespace NodeLibrary
{
	void RegisterNodeTypes();
	void UnregisterNodeTypes();
}