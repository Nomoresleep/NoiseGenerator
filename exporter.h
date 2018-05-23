#pragma once

#include "MC_HashMap.h"
#include "MC_GrowingArray.h"
#include "glzl_core.hpp"

struct ExporterFactory
{
    struct ImageData
    {
        GLuint myImageID;
        s32 myWidth;
        s32 myHeight;
        u8 myChannels;
    };
    typedef void(*ExporterFunction)(const char* aFilepath, const ImageData& someImageData);

    static void RegisterExporter(const char* anExtension, ExporterFactory::ExporterFunction anExporterFunction);

    static ExporterFunction GetExporterForExtension(const char* anExtension);

    static MC_GrowingArray<const char*> GetExtensionList();
private:
    static MC_HashMap<const char*, ExporterFunction> ourExtensionToExporterMap;
};

void RegisterCommonExporters();