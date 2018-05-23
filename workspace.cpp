#include "workspace.h"
#include "NG_NodeGraph.h"
#include "Editor_NodeEditor.h"
#include "exporter.h"
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

	myNodeGraph = new NG_NodeGraph();
    myNodeEditor = new Editor_NodeEditor(myNodeGraph);
}

Workspace::~Workspace()
{
    glDeleteTextures(1, &myImageTextureID);
    glDeleteProgram(myComputeProgram);
}

void Workspace::ExportImage(const char* anExtension) const
{
    ExporterFactory::ImageData exportData;
    exportData.myChannels = 4;
    exportData.myWidth = myImageSize.x;
    exportData.myHeight = myImageSize.y;
    exportData.myImageID = myImageTextureID;

    ExporterFactory::GetExporterForExtension(anExtension)("test", exportData);
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