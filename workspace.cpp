#include "workspace.h"
#include "nodegraph.h"
#include "MCommon/mf_file.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

Workspace* theWorkspace = nullptr;

Workspace::Workspace(i32 anImageWidth, i32 anImageHeight)
    : myImageSize(anImageWidth, anImageHeight, 0)
{
    MF_File perlinNoiseFile(locPerlinNoise2DSource);
    MC_ScopedArray<char> perlinSource = new char[perlinNoiseFile.GetSize() + 1];
    perlinNoiseFile.Read(perlinSource.Data(), perlinNoiseFile.GetSize());
    perlinSource[perlinNoiseFile.GetSize()] = '\0';

    glGenTextures(1, &myImageTextureID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, myImageTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, myImageSize.x, myImageSize.y, 0, GL_RGBA, GL_FLOAT, 0);
    glBindImageTexture(0, myImageTextureID, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

    const char* strs[] = { perlinSource.Data(), locComputeShaderString };

    GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(computeShader, 2, strs, 0);
    glCompileShader(computeShader);
    GLint logLength = 0;
    glGetShaderiv(computeShader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 1)
    {
        char* log = new char[logLength];
        GLsizei length;
        glGetShaderInfoLog(computeShader, logLength, &length, log);
        OutputDebugStringA(log);
        delete[] log;
        return;
    }
    myComputeProgram = glCreateProgram();
    glAttachShader(myComputeProgram, computeShader);
    glLinkProgram(myComputeProgram);
    glDetachShader(myComputeProgram, computeShader);
    glDeleteShader(computeShader);

    myNodegraph = new NodeGraph();
}

void Workspace::Export() const
{
    glBindTexture(GL_TEXTURE_2D, theWorkspace->myImageTextureID);
    MC_ScopedArray<char> img = new char[theWorkspace->myImageSize.x * theWorkspace->myImageSize.y * 4 * sizeof(u8)];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
    stbi_write_png("test.png", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data(), 0);
}