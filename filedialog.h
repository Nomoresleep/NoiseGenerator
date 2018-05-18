#pragma once

#include "MCommon/mf_file.h"

#define MAX_PATH_LENGTH 260
struct FileDialog
{
    FileDialog(void(*fileSaveCallback)(void* someUserData, const char* aFilePath), void* someUserData)
        : myCurrentDir("")
        , myFileSaveCallback(fileSaveCallback)
        , myUserData(someUserData)
    {
        myCurrentDir.SetLength(MAX_PATH_LENGTH);
        MF_File::GetDir(myCurrentDir, &myCurrentDirData);
    }
    void Show();

    MC_String myCurrentDir;
    MF_GetDirData myCurrentDirData;
    void(*myFileSaveCallback) (void* someUserData, const char* aFilePath);
    void* myUserData;
};