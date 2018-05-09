#include "nodelibrary.h"

template<>
void ConstantNode<f32>::OnTraverse(GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %f;\n", myID, 0.5f);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<u32>::OnTraverse(GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %d;\n", myID, 0);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}

template<>
void ConstantNode<s32>::OnTraverse(GraphRunnerContext* aGraphRunnerContext) const
{
    MC_String source;
    source.Format("float node_%d_0 = %d;\n", myID, 0);
    aGraphRunnerContext->myGeneratedSource.Add(source);
}