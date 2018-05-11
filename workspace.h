#pragma once
#include "glzl_core.hpp"
#include "MC_Vector.h"
#include "MC_ScopedPtr.h"
#include "MC_String.h"

class NodeGraph;
class NodeEditor;

#define DEPENDENCY_FILE(text) text

static const char* locPerlinNoise2DSource = DEPENDENCY_FILE("shaders/noise/perlin2d.glsl");

enum ExportExtension
{
    ExportPNG = 0,
    ExportBMP,
    ExportTGA,
    ExportJPG,
    ExportHDR,
    ExportExtensionCount
};
class Workspace
{
public:
    Workspace(s32 anImageWidth, s32 anImageHeight);
    ~Workspace();

    void Export(ExportExtension anExtension) const;
    void SetProgramSource(const MC_String& aSourceCode);

    GLuint myComputeProgram;
    MC_String mySourceCode;

    GLuint myImageTextureID;
    MC_Vector3i myImageSize;

	MC_ScopedPtr<NodeEditor> myNodeEditor;
    MC_ScopedPtr<NodeGraph> myNodeGraph;
};

extern Workspace* theWorkspace;