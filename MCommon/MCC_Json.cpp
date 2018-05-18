#include "MCC_Json.h"


MC_Json::MC_Json()
	: myValueType(NullType)
{
}

MC_Json::MC_Json(bool aBool)
	: myValueType(BoolType)
{
	myValueData.myBool = aBool;
}

MC_Json::MC_Json(f32 aFloat)
    : myValueType(DoubleType)
{
    myValueData.myDouble = (f64)aFloat;
}

MC_Json::MC_Json(s32 anInt)
    : myValueType(DoubleType)
{
    myValueData.myDouble = (f64)anInt;
}

MC_Json::MC_Json(u32 aUInt)
    : myValueType(DoubleType)
{
    myValueData.myDouble = (f64)aUInt;
}

MC_Json::MC_Json(f64 aDouble)
	: myValueType(DoubleType)
{
	myValueData.myDouble = aDouble;
}

MC_Json::MC_Json(const MC_String& aString)
	: myValueType(StringType)
{
	myValueData.myString = new MC_String(aString);
}

MC_Json::MC_Json(const Array& anArray)
	: myValueType(ArrayType)
{
	myValueData.myArray = new Array(anArray);
}

MC_Json::MC_Json(const Object& anObject)
	: myValueType(ObjectType)
{
	myValueData.myObject = new Object(anObject);
}

void MC_Json::Destruct()
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
    myValueType = NullType;
}

MC_Json::~MC_Json()
{
    Destruct();
}

bool MC_Json::IsNull() const
{
	return myValueType == NullType;
}

bool MC_Json::IsBool() const
{
	return myValueType == BoolType;
}

bool MC_Json::IsDouble() const
{
	return myValueType == DoubleType;
}

bool MC_Json::IsString() const
{
	return myValueType == StringType;
}

bool MC_Json::IsArray() const
{
	return myValueType == ArrayType;
}

bool MC_Json::IsObject() const
{
	return myValueType == ObjectType;
}

bool MC_Json::GetBool() const
{
	assert(myValueType == BoolType);
	return myValueData.myBool;
}

f64 MC_Json::GetDouble() const
{
	assert(myValueType == DoubleType);
	return myValueData.myDouble;
}

const MC_String& MC_Json::GetString() const
{
	assert(myValueType == StringType);
	return *(myValueData.myString);
}

const MC_Json::Array& MC_Json::GetArray() const
{
	assert(myValueType == ArrayType);
	return *(myValueData.myArray);
}

const MC_Json::Object& MC_Json::GetObject() const
{
	assert(myValueType == ObjectType);
	return *(myValueData.myObject);
}

bool& MC_Json::GetBool()
{
	assert(myValueType == BoolType);
	return myValueData.myBool;
}

f64& MC_Json::GetDouble()
{
	assert(myValueType == DoubleType);
	return myValueData.myDouble;
}

MC_String& MC_Json::GetString()
{
	assert(myValueType == StringType);
	return *(myValueData.myString);
}

MC_Json::Array& MC_Json::GetArray()
{
	assert(myValueType == ArrayType);
	return *(myValueData.myArray);
}

MC_Json::Object& MC_Json::GetObject()
{
	assert(myValueType == ObjectType);
	return *(myValueData.myObject);
}

bool MC_Json::GetElement(const MC_String& anIdentifier, MC_Json& anOutEntry) const
{
	if (myValueType != ObjectType)
		return false;

	return myValueData.myObject->GetIfExists(anIdentifier, anOutEntry);
}

bool MC_Json::GetElement(s32 anIndex, MC_Json& anOutEntry) const
{
	if (myValueType != ArrayType)
		return false;

	if (anIndex < 0 || anIndex >= myValueData.myArray->Count())
		return false;

	anOutEntry = (*myValueData.myArray)[anIndex];
	return true;
}


MC_String MC_Json::Serialize() const
{
    MC_String jsonString = "";
    Serialize(jsonString, 0);
    return jsonString;
}

void MC_Json::Serialize(MC_String& str, s32 indentationLevel) const
{
    switch (myValueType)
    {
    case NullType:
    {
        str += "null";
    }break;
    case BoolType:
    {
        str += myValueData.myBool ? "true" : "false";
    }break;
    case DoubleType:
    {
        str += MC_Strfmt<32>("%f", myValueData.myDouble);
    }break;
    case StringType:
    {
        str += '\"' + *myValueData.myString + '\"';
    }break;
    case ArrayType:
    {
        str += '[';
        for (s32 idx = 0; idx < myValueData.myArray->Count(); ++idx)
        {
            if (idx != 0) str += ',';
            //indent
            (*myValueData.myArray)[idx].Serialize(str, indentationLevel + 1);
        }
        if (myValueData.myArray->Count() != 0)
        {
            //indent
        }
        str += ']';
    }break;
    case ObjectType:
    {
        str += '{';
        auto iterator = myValueData.myObject->Begin();
        auto endIterator = myValueData.myObject->End();
        for (; iterator != endIterator; ++iterator)
        {
            if (iterator != myValueData.myObject->Begin())
                str += ',';
            //indent
            str += '\"' + iterator.Key() + '\"' + ':'; 
            iterator.Item().Serialize(str, indentationLevel + 1);
        }
        if (myValueData.myObject->Count() != 0)
        {
            //indent
        }
        str += '}';
    }break;
    }
}