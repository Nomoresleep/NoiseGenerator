#include "exporter.h"
#include "stb/stb_image_write.h"
#include "MC_ScopedPtr.h"

MC_HashMap<const char*, ExporterFactory::ExporterFunction> ExporterFactory::ourExtensionToExporterMap;

void ExporterFactory::RegisterExporter(const char* anExtension, ExporterFactory::ExporterFunction anExporterFunction)
{
    assert(!ourExtensionToExporterMap.Exists(anExtension));
    ourExtensionToExporterMap[anExtension] = anExporterFunction;
}

ExporterFactory::ExporterFunction ExporterFactory::GetExporterForExtension(const char* anExtension)
{
    return ourExtensionToExporterMap[anExtension];
}

MC_GrowingArray<const char*> ExporterFactory::GetExtensionList()
{
    MC_GrowingArray<const char*> exporterExtensions;
    for (auto it = ourExtensionToExporterMap.Begin(); it != ourExtensionToExporterMap.End(); ++it)
        exporterExtensions.Add(it.Key());

    return exporterExtensions;
}

static void locExportPNG(const char* aFilepath, const ExporterFactory::ImageData& someImageData)
{
    glBindTexture(GL_TEXTURE_2D, someImageData.myImageID);
    MC_ScopedArray<char> img = new char[someImageData.myWidth * someImageData.myHeight * someImageData.myChannels];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
    stbi_write_png(MC_String(aFilepath) + ".png", someImageData.myWidth, someImageData.myHeight, someImageData.myChannels, img, 0);
}

static void locExportBMP(const char* aFilepath, const ExporterFactory::ImageData& someImageData)
{
    glBindTexture(GL_TEXTURE_2D, someImageData.myImageID);
    MC_ScopedArray<char> img = new char[someImageData.myWidth * someImageData.myHeight * someImageData.myChannels];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
    stbi_write_bmp(MC_String(aFilepath) + ".bmp", someImageData.myWidth, someImageData.myHeight, someImageData.myChannels, img);
}

static void locExportTGA(const char* aFilepath, const ExporterFactory::ImageData& someImageData)
{
    glBindTexture(GL_TEXTURE_2D, someImageData.myImageID);
    MC_ScopedArray<char> img = new char[someImageData.myWidth * someImageData.myHeight * someImageData.myChannels];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
    stbi_write_tga(MC_String(aFilepath) + ".tga", someImageData.myWidth, someImageData.myHeight, someImageData.myChannels, img);
}

static void locExportJPG(const char* aFilepath, const ExporterFactory::ImageData& someImageData)
{
    glBindTexture(GL_TEXTURE_2D, someImageData.myImageID);
    MC_ScopedArray<char> img = new char[someImageData.myWidth * someImageData.myHeight * someImageData.myChannels];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.Data());
    stbi_write_jpg(MC_String(aFilepath) + ".jpg", someImageData.myWidth, someImageData.myHeight, someImageData.myChannels, img, 100);
}

static void locExportHDR(const char* aFilepath, const ExporterFactory::ImageData& someImageData)
{
    assert(false);
    glBindTexture(GL_TEXTURE_2D, someImageData.myImageID);
    MC_ScopedArray<f32> img = new f32[someImageData.myWidth * someImageData.myHeight * someImageData.myChannels];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, img.Data());
    stbi_write_hdr(MC_String(aFilepath) + ".hdr", someImageData.myWidth, someImageData.myHeight, someImageData.myChannels, (const float*)img);
}

void RegisterCommonExporters()
{
    ExporterFactory::RegisterExporter("png", locExportPNG);
    ExporterFactory::RegisterExporter("bmp", locExportBMP);
    ExporterFactory::RegisterExporter("tga", locExportTGA);
    ExporterFactory::RegisterExporter("jpg", locExportJPG);
    ExporterFactory::RegisterExporter("hdr", locExportHDR);
}
