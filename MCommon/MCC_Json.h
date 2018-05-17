#pragma once

#include "MC_GrowingArray.h"
#include "MC_HashMap.h"
#include "MC_String.h"

class MC_JsonEntry
{
	typedef MC_GrowingArray<MC_JsonEntry> Array;
	typedef MC_HashMap<MC_String, MC_JsonEntry> Object;

	enum ValueType
	{
		NullType,
		BoolType,
		DoubleType,
		StringType,
		ArrayType,
		ObjectType
	};

	union ValueData
	{
		bool myBool;
		f64 myDouble;
		MC_String* myString;
		Array* myArray;
		Object* myObject;
	};

public:
	MC_JsonEntry();
	MC_JsonEntry(bool aBool);
	MC_JsonEntry(f64 aDouble);
	MC_JsonEntry(const MC_String& aString);
	MC_JsonEntry(const Array& anArray);
	MC_JsonEntry(const Object& anObject);

	bool IsNull() const;
	bool IsBool() const;
	bool IsDouble() const;
	bool IsString() const;
	bool IsArray() const;
	bool IsObject() const;

	bool GetBool() const;
	f64 GetDouble() const;
	const MC_String& GetString() const;
	const Array& GetArray() const;
	const Object& GetObject() const;

	bool& GetBool();
	f64& GetDouble();
	MC_String& GetString();
	Array& GetArray();
	Object& GetObject();

	bool GetElement(const MC_String& anIdentifier, MC_JsonEntry& anOutEntry) const;
	bool GetElement(s32 anIndex, MC_JsonEntry& anOutEntry) const;


	~MC_JsonEntry();

private:
	ValueType myValueType;
	ValueData myValueData;
};