#include "MCC_Json.h"
#include "MF_File.h"
#include "MC_ScopedPtr.h"

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

MC_Json::MC_Json(const char* aCString)
	: myValueType(StringType){
	myValueData.myString = new MC_String(aCString);
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

MC_Json::MC_Json(Object&& anObject)
	: myValueType(ObjectType)
{
	//TODO[Nomoresleep]: why is the move constructor not called without MC_Move?
	myValueData.myObject = new Object(MC_Move(anObject));
}

MC_Json::MC_Json(const MC_Json& otherJson)
	: myValueType(otherJson.myValueType)
{
	switch (myValueType)
	{
	case StringType:
	{
		myValueData.myString = new MC_String(*(otherJson.myValueData.myString));
	}break;
	case ArrayType:
	{
		myValueData.myArray = new Array(*(otherJson.myValueData.myArray));
	}break;
	case ObjectType:
	{
		myValueData.myObject = new Object(*(otherJson.myValueData.myObject));
	}break;
	default:
	{
		memcpy(&myValueData, &otherJson.myValueData, sizeof(ValueData));
	}break;
	}
}

MC_Json::MC_Json(MC_Json&& otherJson)
	: myValueType(otherJson.myValueType)
{
	memcpy(&myValueData, &otherJson.myValueData, sizeof(ValueData));
	memset(&otherJson.myValueData, 0, sizeof(ValueData));
	otherJson.myValueType = NullType;
}

MC_Json::~MC_Json()
{
	Destruct();
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
	memset(&myValueData, 0, sizeof(ValueData));
    myValueType = NullType;
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

bool MC_Json::GetJsonElement(const MC_String& anIdentifier, MC_Json& anOutEntry) const
{
	if (myValueType != ObjectType)
		return false;

	return myValueData.myObject->GetIfExists(anIdentifier, anOutEntry);
}

bool MC_Json::GetJsonElement(s32 anIndex, MC_Json& anOutEntry) const
{
	if (myValueType != ArrayType)
		return false;

	if (anIndex < 0 || anIndex >= myValueData.myArray->Count())
		return false;

	anOutEntry = (*myValueData.myArray)[anIndex];
	return true;
}

bool MC_Json::GetElement(const MC_String& anIdentifier, MC_String& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);

	if (!result || !element.IsString())
		return false;

	anOutEntry = element.GetString();
	return true;
}

bool MC_Json::GetElement(const MC_String& anIdentifier, s32& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);

	if (!result || !element.IsDouble())
		return false;

	anOutEntry = (s32)element.GetDouble();
	return true;
}

bool MC_Json::GetElement(const MC_String& anIdentifier, u32& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);

	if (!result || !element.IsDouble())
		return false;

	anOutEntry = (u32)element.GetDouble();
	return true;
}

bool MC_Json::GetElement(const MC_String& anIdentifier, f32& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);

	if (!result || !element.IsDouble())
		return false;

	anOutEntry = (f32)element.GetDouble();
	return true;
}

bool MC_Json::GetElement(s32 anIndex, s32& anOutInteger) const
{
	MC_Json element;
	bool result = GetJsonElement(anIndex, element);

	if (!result || !element.IsDouble())
		return false;

	anOutInteger = (s32)element.GetDouble();
	return true;
}

bool MC_Json::GetElement(s32 anIndex, u32& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIndex, element);

	if (!result || !element.IsDouble())
		return false;

	anOutEntry = (u32)element.GetDouble();
	return true;
}

bool MC_Json::GetElement(s32 anIndex, f32& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIndex, element);

	if (!result || !element.IsDouble())
		return false;

	anOutEntry = (f32)element.GetDouble();
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
		str += '\"';
		str += *myValueData.myString;
		str += '\"';
    }break;
    case ArrayType:
    {
        str += '[';
        for (s32 idx = 0; idx < myValueData.myArray->Count(); ++idx)
        {
            if (idx != 0) str += ',';
			Indent(str, indentationLevel);
            (*myValueData.myArray)[idx].Serialize(str, indentationLevel + 1);
        }
        if (myValueData.myArray->Count() != 0)
        {
			Indent(str, indentationLevel - 1);
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
			Indent(str, indentationLevel);
			const MC_String& key = iterator.Key();
			str += '\"';
			str += key;
			str += '\"';
			str += ':';
            iterator.Item().Serialize(str, indentationLevel + 1);
        }
        if (myValueData.myObject->Count() != 0)
        {
			Indent(str, indentationLevel - 1);
        }
        str += '}';
    }break;
    }
}

void MC_Json::Indent(MC_String& str, s32 indentationLevel)
{
	str += '\n';
	for(s32 i = 0; i < indentationLevel; ++i)
		str += '\t';
}

MC_Json MC_Json::FromFile(const char* aFilename)
{
	MF_File file(aFilename);
	u32 size = file.GetSize();
	if (!size)
		return MC_Json();

	MC_ScopedArray<char> fileBuffer = (char*)MC_TempAlloc(size);
	assert(fileBuffer);
	file.Read(fileBuffer, size);
	file.Close();

	ParsingContext ctxt;
	ctxt.myPtr = fileBuffer;
	return Parse(ctxt);
}

MC_Json MC_Json::Parse(ParsingContext& aCtxt)
{
	SkipWhitespace(aCtxt.myPtr);
	switch (*aCtxt.myPtr++) {
	case 't':
	{
		if (strncmp((const char*)aCtxt.myPtr, "rue", 3) == 0)
			return true;
	}break;
	case 'f':
	{
		if (strncmp((const char*)aCtxt.myPtr, "alse", 4) == 0)
			return false;
	}break;
	case 'n':
	{
		assert(strncmp((const char*)aCtxt.myPtr, "ull", 3) == 0);
		aCtxt.myPtr += 4;
	}break;
	case '\"':
	{
		return ParseString(aCtxt);
	}break;
	case '[':
	{
		return ParseArray(aCtxt);
	}break;
	case '{':
	{
		return ParseObject(aCtxt);
	}break;
	default:
		char* start = aCtxt.myPtr - 1;
		if (('0' <= *start && *start <= '9') || *start == '-') {
			char* end = nullptr;
			f64 f = strtod(start, &end);
			aCtxt.myPtr = end;
			return MC_Json(f);
		}
		else
		{
			assert(false);
		}
		break;
	}
	return MC_Json();
}

MC_Json MC_Json::ParseString(ParsingContext& aCtxt)
{
	SkipWhitespace(aCtxt.myPtr);
	char* start = aCtxt.myPtr;
	while (*(aCtxt.myPtr++) != '\"');
	return MC_Json(MC_String(start, aCtxt.myPtr - start - 1));
}

MC_Json MC_Json::ParseArray(ParsingContext& aCtxt)
{
	MC_Json::Array array;
	while (true)
	{
		SkipWhitespace(aCtxt.myPtr);
		if (*aCtxt.myPtr == ']')
			break;

		MC_Json value = Parse(aCtxt);
		//Skip ,
		SkipWhitespace(++aCtxt.myPtr);

		array.Add(value);
	}
	aCtxt.myPtr++;
	return array;
}

MC_Json MC_Json::ParseObject(ParsingContext& aCtxt)
{
	MC_Json::Object object;
	while (true)
	{
		SkipWhitespace(aCtxt.myPtr);
		if (*aCtxt.myPtr == ',')
			aCtxt.myPtr++;
		else if (*aCtxt.myPtr == '}')
			break;
		SkipWhitespace(aCtxt.myPtr);

		if(*aCtxt.myPtr == '\"')
			aCtxt.myPtr++;
		MC_Json key = ParseString(aCtxt);
		assert(key.IsString());

		//Skip " and :
		SkipWhitespace(aCtxt.myPtr);
		SkipWhitespace(++aCtxt.myPtr);

		MC_Json value = Parse(aCtxt);
		object[key.GetString()] = value;
	}
	aCtxt.myPtr++;
	return object;
}

void MC_Json::SkipWhitespace(char*& aString)
{
	while (*aString == ' ' || *aString == '\t' || *aString == '\n' || *aString == '\r')
		aString++;
}