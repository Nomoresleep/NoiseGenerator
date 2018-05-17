#include "MCC_Json.h"


MC_JsonEntry::MC_JsonEntry()
	: myValueType(NullType)
{
}

MC_JsonEntry::MC_JsonEntry(bool aBool)
	: myValueType(BoolType)
{
	myValueData.myBool = aBool;
}

MC_JsonEntry::MC_JsonEntry(f64 aDouble)
	: myValueType(DoubleType)
{
	myValueData.myDouble = aDouble;
}

MC_JsonEntry::MC_JsonEntry(const MC_String& aString)
	: myValueType(StringType)
{
	myValueData.myString = new MC_String(aString);
}

MC_JsonEntry::MC_JsonEntry(const Array& anArray)
	: myValueType(ArrayType)
{
	myValueData.myArray = new Array(anArray);
}

MC_JsonEntry::MC_JsonEntry(const Object& anObject)
	: myValueType(ObjectType)
{
	myValueData.myObject = new Object(anObject);
}

MC_JsonEntry::~MC_JsonEntry()
{
	switch (myValueType)
	{
	case StringType:
	{
		delete myValueData.myString;
	}break;
	case ArrayType:
	{
		myValueData.myArray->RemoveAll();
		delete myValueData.myArray;
	}break;
	case ObjectType:
	{
		myValueData.myObject->RemoveAll();
		delete myValueData.myObject;
	}break;
	}
}

bool MC_JsonEntry::IsNull() const
{
	return myValueType == NullType;
}

bool MC_JsonEntry::IsBool() const
{
	return myValueType == BoolType;
}

bool MC_JsonEntry::IsDouble() const
{
	return myValueType == DoubleType;
}

bool MC_JsonEntry::IsString() const
{
	return myValueType == StringType;
}

bool MC_JsonEntry::IsArray() const
{
	return myValueType == ArrayType;
}

bool MC_JsonEntry::IsObject() const
{
	return myValueType == ObjectType;
}

bool MC_JsonEntry::GetBool() const
{
	assert(myValueType == BoolType);
	return myValueData.myBool;
}

f64 MC_JsonEntry::GetDouble() const
{
	assert(myValueType == DoubleType);
	return myValueData.myDouble;
}

const MC_String& MC_JsonEntry::GetString() const
{
	assert(myValueType == StringType);
	return *(myValueData.myString);
}

const MC_JsonEntry::Array& MC_JsonEntry::GetArray() const
{
	assert(myValueType == ArrayType);
	return *(myValueData.myArray);
}

const MC_JsonEntry::Object& MC_JsonEntry::GetObject() const
{
	assert(myValueType == ObjectType);
	return *(myValueData.myObject);
}

bool& MC_JsonEntry::GetBool()
{
	assert(myValueType == BoolType);
	return myValueData.myBool;
}

f64& MC_JsonEntry::GetDouble()
{
	assert(myValueType == DoubleType);
	return myValueData.myDouble;
}

MC_String& MC_JsonEntry::GetString()
{
	assert(myValueType == StringType);
	return *(myValueData.myString);
}

MC_JsonEntry::Array& MC_JsonEntry::GetArray()
{
	assert(myValueType == ArrayType);
	return *(myValueData.myArray);
}

MC_JsonEntry::Object& MC_JsonEntry::GetObject()
{
	assert(myValueType == ObjectType);
	return *(myValueData.myObject);
}

bool MC_JsonEntry::GetElement(const MC_String& anIdentifier, MC_JsonEntry& anOutEntry) const
{
	if (myValueType != ObjectType)
		return false;

	return myValueData.myObject->GetIfExists(anIdentifier, anOutEntry);
}

bool MC_JsonEntry::GetElement(s32 anIndex, MC_JsonEntry& anOutEntry) const
{
	if (myValueType != ArrayType)
		return false;

	if (anIndex < 0 || anIndex >= myValueData.myArray->Count())
		return false;

	anOutEntry = (*myValueData.myArray)[anIndex];
	return true;
}