#pragma once

#include "nodegraph.h"
#include "MC_BinaryHeap.h"

struct NodeComparator
{
    static bool LessThan(Node* a, Node* b) { return a->ConnectedInputCount() < b->ConnectedInputCount(); }
    static bool Equals(Node* a, Node* b) { return a->ConnectedInputCount() == b->ConnectedInputCount(); }
};

class GraphRunner
{
public:
    GraphRunner(NodeGraph* aNodegraph)
        : myNodegraph(aNodegraph)
    {}

    void Run()
    {
        MC_BinaryHeap<Node*, NodeComparator> pqueue(myNodegraph->GetNodes().Count());
        GraphRunnerContext runnerContext;
        
		static const char* locComputeShaderString1 =
			"layout(local_size_x = 8, local_size_y = 8) in;\n"
			"layout(rgba32f, binding = 0) uniform image2D img_output;\n"
			"void main(){\n"
			"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
			"float x = (pixel_coords.x / 1024.0) * 16.0;\n"
			"float y = (pixel_coords.y / 1024.0) * 16.0;\n"
			"float result = 0.0;\n";
        static const char* locComputeShaderString2 = 
            //"float perlin = PerlinNoise2D(x,y);\n"
            "vec4 pixel_value = vec4(result, result, result, 1.0);\n"
            "imageStore(img_output, pixel_coords, pixel_value);\n"
            "}";

        runnerContext.myGeneratedSource.Add(locComputeShaderString1);

        for (s32 nodeIdx = 0; nodeIdx < myNodegraph->GetNodes().Count(); ++nodeIdx)
        {
            Node* node = myNodegraph->GetNodes()[nodeIdx];
            if (node->ConnectedInputCount() == 0)
                pqueue.Push(node);
        }

        while (!pqueue.IsEmpty())
        {
            const Node* node = pqueue.Pop();
            node->OnTraverse(&runnerContext);
            for (s32 outPortIdx = 0; outPortIdx < node->myOutputs.Count(); ++outPortIdx)
            {
                const OutputPort* outPort = node->myOutputs[outPortIdx];
                for (s32 inPortIdx = 0; inPortIdx < outPort->myConnectedInputs.Count(); ++inPortIdx)
                {
                    const InputPort* inPort = outPort->myConnectedInputs[inPortIdx];
                    pqueue.Push(inPort->myNode);
                }
            }
        }

        runnerContext.myGeneratedSource.Add(locComputeShaderString2);

        MC_String source;
        for (s32 i = 0; i < runnerContext.myGeneratedSource.Count(); ++i)
            source += runnerContext.myGeneratedSource[i];

        theWorkspace->SetProgramSource(source);
    }
private:
    NodeGraph* myNodegraph;
};