#pragma once
#include "opengl_context.h"
#include "MC_Vector.h"
#include "MC_ScopedPtr.h"
#include "MC_String.h"

class NG_NodeGraph;
class Editor_NodeEditor;

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

	MC_ScopedPtr<Editor_NodeEditor> myNodeEditor;
    MC_ScopedPtr<NG_NodeGraph> myNodeGraph;
};

extern Workspace* theWorkspace;