#include "workspace.h"
#include "nodegraph.h"
#include "Editor_NodeEditor.h"
#include "mf_file.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

Workspace* theWorkspace = nullptr;

Workspace::Workspace(s32 anImageWidth, s32 anImageHeight)
    : myImageSize(anImageWidth, anImageHeight, 0)
{
    glGenTextures(1, &myImageTextureID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, myImageTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, myImageSize.x, myImageSize.y, 0, GL_RGBA, GL_FLOAT, 0);
    glBindImageTexture(0, myImageTextureID, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);

	myNodeGraph = new NodeGraph();
    myNodeEditor = new Editor_NodeEditor(myNodeGraph);
	myNodeGraph->RegisterListener(myNodeEditor);
}

Workspace::~Workspace()
{
    glDeleteTextures(1, &myImageTextureID);
    glDeleteProgram(myComputeProgram);
}

void Workspace::Export(ExportExtension anExtension) const
{
    glBindTexture(GL_TEXTURE_2D, theWorkspace->myImageTextureID);
    if (anExtension != ExportHDR)
    {
        MC_ScopedArray<char> img = new char[theWorkspace->myImageSize.x * theWorkspace->myImageSize.y * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
        switch (anExtension)
        {
        case ExportPNG:
            stbi_write_png("test.png", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data(), 0);
            break;
        case ExportBMP:
            stbi_write_bmp("test.bmp", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data());
            break;
        case ExportTGA:
            stbi_write_tga("test.tga", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data());
            break;
        case ExportJPG:
            stbi_write_jpg("test.jpg", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data(), 100);
            break;
        }
    }
    else
    {
        assert(false);
        MC_ScopedArray<f32> img = new f32[theWorkspace->myImageSize.x * theWorkspace->myImageSize.y * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, img.Data());
        stbi_write_hdr("test.hdr", theWorkspace->myImageSize.x, theWorkspace->myImageSize.y, 4, img.Data());
    }
}

void Workspace::SetProgramSource(const MC_String& aSourceCode)
{
    if (mySourceCode == aSourceCode)
        return;

    mySourceCode = aSourceCode;

    if (myComputeProgram)
        glDeleteProgram(myComputeProgram);

    MF_File perlinNoiseFile(locPerlinNoise2DSource);
    MC_ScopedArray<char> perlinSource = new char[perlinNoiseFile.GetSize() + 1];
    perlinNoiseFile.Read(perlinSource.Data(), perlinNoiseFile.GetSize());
    perlinSource[perlinNoiseFile.GetSize()] = '\0';

    const char* strs[] = { perlinSource.Data(), mySourceCode.GetBuffer() };

    GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(computeShader, 2, strs, 0);
    glCompileShader(computeShader);
    GLint logLength = 0;
    glGetShaderiv(computeShader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 1)
    {
        MC_ScopedPtr<char> log = new char[logLength];
        GLsizei length;
        glGetShaderInfoLog(computeShader, logLength, &length, log);
        OutputDebugStringA(log);
        return;
    }
    myComputeProgram = glCreateProgram();
    glAttachShader(myComputeProgram, computeShader);
    glLinkProgram(myComputeProgram);
    glDetachShader(myComputeProgram, computeShader);
    glDeleteShader(computeShader);

    {
        glUseProgram(myComputeProgram);
        glDispatchCompute((GLuint)myImageSize.x / 8, (GLuint)myImageSize.y / 8, 1);
        glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
    }
}