#include "NG_NodeLibrary.h"

template <>
const char* GetVariableTypeFromType<f32>() { return "float"; }

template <>
const char* GetVariableTypeFromType<s32>() { return "int"; }

template <>
const char* GetVariableTypeFromType<u32>() { return "uint"; }

template <>
const char* GetVariableTypeFromType<MC_Vector2f>() { return "vec2"; }

//TODO: Fix node ids
template<>
void ConstantNode<f32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String varName = MC_Strfmt<64>("constant%d", myUID);
	MC_String source = MC_Strfmt<128>("float %s = %f;\n", varName, myOutputs[OutIdx]->myData.myValue.myFloat);
	aGraphRunnerContext->myGeneratedSource.Add(source);
    myOutputs[OutIdx]->myData.myVariableName = varName;
}

template<>
void ConstantNode<u32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String varName = MC_Strfmt<64>("constant%d", myUID);
	MC_String source = MC_Strfmt<128>("uint %s = %d;\n", varName, myOutputs[OutIdx]->myData.myValue.myUInt);
	aGraphRunnerContext->myGeneratedSource.Add(source);
    myOutputs[OutIdx]->myData.myVariableName = varName;
}

template<>
void ConstantNode<s32>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String varName = MC_Strfmt<64>("constant%d", myUID);
    MC_String source = MC_Strfmt<128>("int %s = %d;\n", varName, myOutputs[OutIdx]->myData.myValue.myInt);
    aGraphRunnerContext->myGeneratedSource.Add(source);
    myOutputs[OutIdx]->myData.myVariableName = varName;
}

template<>
void ConstantNode<MC_Vector2f>::OnTraverse(NG_GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String varName = MC_Strfmt<64>("constant%d", myUID);
    const MC_Vector2f& v2 = myOutputs[OutIdx]->myData.myValue.myVec2;
    MC_String source = MC_Strfmt<128>("vec2 %s = vec2(%f, %f);\n", varName, v2.x, v2.y);
    aGraphRunnerContext->myGeneratedSource.Add(source);
    myOutputs[OutIdx]->myData.myVariableName = varName;
}

struct UVConstExpr
{
    static constexpr char* BuildIn = "UV";
};

struct AddOp
{
    static constexpr char* Operator = "+";
    static constexpr char* Name = "add";
};

struct SubOp
{
    static constexpr char* Operator = "-";
    static constexpr char* Name = "subtract";
};

struct MultOp
{
    static constexpr char* Operator = "*";
    static constexpr char* Name = "mult";
};

struct DivOp
{
    static constexpr char* Operator = "/";
    static constexpr char* Name = "div";
};

void NodeLibrary::RegisterNodeTypes()
{
	NG_RegisterNodeType<ConstantNode<f32>>("Constants/FloatConstantNode");
	NG_RegisterNodeType<ConstantNode<s32>>("Constants/IntConstantNode");
    NG_RegisterNodeType<ConstantNode<u32>>("Constants/UIntConstantNode");
    NG_RegisterNodeType<ConstantNode<MC_Vector2f>>("Constants/Vec2ConstantNode");
    NG_RegisterNodeType<BuildInConstantNode<MC_Vector2f, UVConstExpr>>("Constants/UV");
    NG_RegisterNodeType<OperationNodeTwoWay<MC_Vector2f, AddOp>>("Math/V2/Add");
    NG_RegisterNodeType<OperationNodeTwoWay<MC_Vector2f, SubOp>>("Math/V2/Sub");
    NG_RegisterNodeType<OperationNodeTwoWay<MC_Vector2f, MultOp>>("Math/V2/Mult");
    NG_RegisterNodeType<OperationNodeTwoWay<MC_Vector2f, DivOp>>("Math/V2/Div");
    NG_RegisterNodeType<OperationNodeTwoWay<f32, AddOp>>("Math/float/Add");
    NG_RegisterNodeType<OperationNodeTwoWay<f32, SubOp>>("Math/float/Sub");
    NG_RegisterNodeType<OperationNodeTwoWay<f32, MultOp>>("Math/float/Mult");
    NG_RegisterNodeType<OperationNodeTwoWay<f32, DivOp>>("Math/float/Div");
    NG_RegisterNodeType<Split1To2Node>("Split1To2");
    NG_RegisterNodeType<Combine2To1Node>("Combine2To1");
	NG_RegisterNodeType<PerlinNoise2D>("PerlinNoise2D");
	NG_RegisterNodeType<ResultNode>("ResultNode");
}

void NodeLibrary::UnregisterNodeTypes()
{
	NG_UnregisterNodeType("Constants/FloatConstantNode");
	NG_UnregisterNodeType("Constants/IntConstantNode");
	NG_UnregisterNodeType("Constants/UIntConstantNode");
    NG_UnregisterNodeType("Constants/Vec2ConstantNode");
    NG_UnregisterNodeType("Constants/UV");
    NG_UnregisterNodeType("Math/Add");
    NG_UnregisterNodeType("Math/Sub");
    NG_UnregisterNodeType("Math/Mult");
    NG_UnregisterNodeType("Math/Div");
    NG_UnregisterNodeType("Split2To1");
    NG_UnregisterNodeType("Combine2To1");
	NG_UnregisterNodeType("PerlinNoise2D");
	NG_UnregisterNodeType("ResultNode");
}