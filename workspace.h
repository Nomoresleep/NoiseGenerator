#pragma once
#include "glzl_core.hpp"
#include "types.h"
#include "MCommon/MC_Vector.h"
#include "MCommon/MC_ScopedPtr.h"

class NodeGraph;

static const char* locComputeShaderString =
"layout(local_size_x = 8, local_size_y = 8) in;\n"
"layout(rgba32f, binding = 0) uniform image2D img_output;\n"
"void main(){\n"
"ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);\n"
"float x = (pixel_coords.x / 1024.0) * 16.0;\n"
"float y = (pixel_coords.y / 1024.0) * 16.0;\n"
"float perlin = PerlinNoise2D(x,y);\n"
"vec4 pixel_value = vec4(perlin, perlin, perlin, 1.0);\n"
"imageStore(img_output, pixel_coords, pixel_value);\n"
"}";

#define DEPENDENCY_FILE(text) text

static const char* locPerlinNoise2DSource = DEPENDENCY_FILE("shaders/noise/perlin2d.glsl");

class Workspace
{
public:
    Workspace(i32 anImageWidth, i32 anImageHeight);

    void Export() const;
    GLuint myComputeProgram;
    GLuint myImageTextureID;
    MC_Vector3i myImageSize;

    NodeGraph* myNodegraph;
};

extern Workspace* theWorkspace;