// Massgate
// Copyright (C) 2017 Ubisoft Entertainment
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header files
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "mf_file.h"

#include "MC_IniFile.h"


//////////////////////////////////////////////////////////////////////////////////
// MC_IniFile::MC_IniFile()
//
// Parameters:
//  aFilename		Name of .INI file
//
// Explanation:
//  Constructor for the MC_IniFile class. This constructor loads in the specified
//  file and prepares for the processing of the file.
//  
//////////////////////////////////////////////////////////////////////////////////

MC_IniFile::MC_IniFile(
	const char* aFilename)
	: myFileBuffer(NULL)
	, mySize(0)
{
	// load .INI file
	MF_File file(aFilename);
	mySize = file.GetSize();
	if (mySize)
	{
		myFileBuffer = (u8*)MC_TempAlloc(mySize);
		assert(myFileBuffer);
		file.Read(myFileBuffer, mySize);
		file.Close();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// MC_IniFile::~MC_IniFile()
//
// Explanation:
//  Destructor for the MC_IniFile class. This frees any allocated resources in 
//  preparation for deletion.
//  
//////////////////////////////////////////////////////////////////////////////////

MC_IniFile::~MC_IniFile()
{
	if (myFileBuffer)
	{
		MC_TempFree(myFileBuffer);
	}
}

//////////////////////////////////////////////////////////////////////////////////
// MC_IniFile::GetFloat()
//
// Parameters:
//  aKey		Key name
//
// Explanation:
//  This utility function returns a data item associated with key
//  and converts the ASCIIZ string to a floating point value.
//
// Returns:
//  Floating point line data item.
//
//////////////////////////////////////////////////////////////////////////////////

f32 MC_IniFile::GetFloat(const char* aKey, f32 aFallbackValue) const
{
	MC_String* value = myValues.Find(aKey);
	if (!value)
	{
		return aFallbackValue;
	}

	const char* string = value->GetBuffer();
	
	// get sign of string (most atof's don't like signs!)
	if (string)
	{
		float32 result = 1.0f;
		if (*string=='-')
		{
			result = -1.0f;
			string++;
		}
		result *= (float32)atof(string);
		return (result);
	}
	return aFallbackValue;
}

s32 MC_IniFile::GetInt(const char* aKey, s32 aFallbackValue) const
{
	MC_String* value = myValues.Find(aKey);
	if (!value)
	{
		return aFallbackValue;
	}

	const char* string = value->GetBuffer();

	// get sign of string (most atof's don't like signs!)
	if (string)
	{
		int32 result = 1;
		if (*string=='-')
		{
			result = -1;
			string++;
		}
		result *= (int32)atoi(string);
		return (result);
	}
	return aFallbackValue;
}

u32 MC_IniFile::GetUInt(const char* aKey, u32 aFallbackValue) const
{
	MC_String* value = myValues.Find(aKey);
	if (!value)
	{
		return aFallbackValue;
	}

	const char* string = value->GetBuffer();

	// get sign of string (most atof's don't like signs!)
	if (string)
	{
		int32 result = 1;
		if (*string == '-')
		{
			result = -1;
			string++;
		}
		result *= (int32)strtoul(string, NULL, 0);
		return (result);
	}
	return aFallbackValue;
}

bool MC_IniFile::GetBool(const char* aKey, bool aFallbackValue) const
{
	MC_String* value = myValues.Find(aKey);
	if (!value)
	{
		return aFallbackValue;
	}

	if (*value == "1"
		|| *value == "on"
		|| *value == "yes"
		|| *value == "true")
	{
		return true;
	}
	return aFallbackValue;
}

const char* MC_IniFile::GetString(const char* aKey, const char* aFallbackValue) const
{
	MC_String* value = myValues.Find(aKey);
	if (!value)
	{
		return aFallbackValue;
	}

	return value->GetBuffer();
}

//////////////////////////////////////////////////////////////////////////////////
// MC_IniFile::HasKey()
//
// Parameters:
//  aKey		Key name
//
// Explanation:
//  This utility function checks if INIFILE object contains data
//  associated with key.
//
// Returns:
//  True if key exists.
//
//////////////////////////////////////////////////////////////////////////////////

bool
MC_IniFile::HasKey(
	const char*		aKey)
{
	return myValues.Find(aKey) != 0;
}

//////////////////////////////////////////////////////////////////////////////////
// MC_IniFile::Process()

// Explanation:
//  The .INI file referenced by the INIFILE object is processed.
//  
// Returns:
//  True if INIFILE object processed without errors.
//
//////////////////////////////////////////////////////////////////////////////////


bool MC_IniFile::SetFloat(const char* aKey, f32 aValue)
{
	bool collision = myValues.Find(aKey) != 0;
	myValues.Insert(aKey, MC_Strfmt<32>("%f", aValue).myBuffer);
	return !collision;
}

bool MC_IniFile::SetInt(const char* aKey, s32 aValue)
{
	bool collision = myValues.Find(aKey) != 0;
	myValues.Insert(aKey, MC_Strfmt<32>("%d", aValue).myBuffer);
	return !collision;
}

bool MC_IniFile::SetUInt(const char* aKey, u32 aValue)
{
	bool collision = myValues.Find(aKey) != 0;
	myValues.Insert(aKey, MC_Strfmt<32>("%d", aValue).myBuffer);
	return !collision;
}

bool MC_IniFile::SetBool(const char* aKey, bool aValue)
{
	bool collision = myValues.Find(aKey) != 0;
	myValues.Insert(aKey, aValue ? "true" : "false");
	return !collision;
}

bool MC_IniFile::SetString(const char* aKey, const char* aValue)
{
	bool collision = myValues.Find(aKey) != 0;
	myValues.Insert(aKey, aValue);
	return !collision;
}

bool
MC_IniFile::Process()
{
	const char *begin = (char*)myFileBuffer;
	const char *end = begin + mySize;

	MC_String currentSection;
	for (const char* lineStart = begin; lineStart != end;)
	{
		lineStart = PrivSkipWhitespace(lineStart, end);
		if (lineStart == end)
		{
			break;
		}

		// Comment
		if (*lineStart == ';'
			|| *lineStart == '#')
		{
			lineStart = PrivLineEnd(lineStart, end);
			continue;
		}

		// Unexpected character
		if (*lineStart == '='
			|| *lineStart == ']')
		{
			return false;
		}

		// Start of section
		if (*lineStart == '[')
		{
			++lineStart;
			bool sectionClosed = false;
			const char* sectionEnd = PrivSectionNameEnd(lineStart, end, sectionClosed);
			if (!sectionClosed)
			{
				return false;
			}

			currentSection = MC_String(lineStart, sectionEnd - lineStart).TrimLeft().TrimRight() + '.';
			lineStart = PrivLineEnd(lineStart, end);
			continue;
		}

		// Value
		const char* equals = PrivValueDelimeter(lineStart, end);
		const char* lineEnd = PrivLineEnd(equals, end);
		if (equals == end || equals + 1 == end)
		{
			break;
		}

		MC_String key = currentSection + MC_String(lineStart, equals - lineStart).TrimLeft().TrimRight();
		MC_String value = MC_String(equals + 1, lineEnd - equals).TrimLeft().TrimRight();
		myValues.Insert(key, value);
		lineStart = (lineEnd == end) ? lineEnd : lineEnd + 1;
	}

	return true;
}

const char*
MC_IniFile::PrivSkipWhitespace(
	const char* aBegin,
	const char* aEnd)
{
	while (aBegin < aEnd
		&& (*aBegin == ' '
			|| *aBegin == '\t'
			|| *aBegin == '\r'
			|| *aBegin == '\n'))
	{
		aBegin++;
	}
	return (aBegin);
}

const char*
MC_IniFile::PrivLineEnd(
	const char* aBegin,
	const char* aEnd)
{
	while (aBegin < aEnd && *aBegin != '\n')
	{
		aBegin++;
	}
	return (aBegin);
}

const char*
MC_IniFile::PrivValueDelimeter(
	const char*		aBegin,
	const char*		aEnd)
{
	while (aBegin < aEnd && *aBegin != '=')
	{
		aBegin++;
	}
	return (aBegin);
}

const char*
MC_IniFile::PrivSectionNameEnd(
	const char*		aBegin,
	const char*		aEnd,
	bool&			aOutSectionClosed)
{
	while (aBegin < aEnd && *aBegin != '\n' && *aBegin != ']')
	{
		aBegin++;
	}
	aOutSectionClosed = (aBegin != aEnd) && *aBegin == ']';
	return (aBegin);
}

/* end of file */
