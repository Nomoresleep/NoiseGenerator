#pragma once

#include "MCommon/mf_file.h"

#define MAX_PATH_LENGTH 260
struct FileDialog
{
    FileDialog()
        : myCurrentDir("")
    {
        myCurrentDir.SetLength(MAX_PATH_LENGTH);
        MF_File::GetDir(myCurrentDir, &myCurrentDirData);
    }
    void Show();

    MC_String myCurrentDir;
    MF_GetDirData myCurrentDirData;
};