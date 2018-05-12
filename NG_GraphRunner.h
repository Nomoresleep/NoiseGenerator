#pragma once

#include "NG_NodeGraph.h"
#include "MC_BinaryHeap.h"

class NG_GraphRunner
{
public:
	NG_GraphRunner(NG_NodeGraph* aNodegraph);

	void Run();

	NG_NodeGraph* myNodegraph;

	MC_String mySource;
};