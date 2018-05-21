#pragma once

#include "MC_GrowingArray.h"
#include "MC_HashMap.h"
#include "MC_String.h"
#include "MC_Vector.h"

//TODO[Nomoresleep] this could all be more efficient if MC_ Datastructures had a move constructor

class MC_Json
{
public:
    typedef MC_GrowingArray<MC_Json> Array;
    typedef MC_HashMap<MC_String, MC_Json> Object;

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

	MC_Json();
	MC_Json(bool aBool);
    MC_Json(f32 aFloat);
    MC_Json(s32 anInt);
    MC_Json(u32 aUInt);
	MC_Json(f64 aDouble);
	MC_Json(const char* aCString);
	MC_Json(const MC_String& aString);
	MC_Json(const Array& anArray);
	MC_Json(const Object& anObject);
	MC_Json(Object&& anObject);

	MC_Json(const MC_Json& otherJson);
	MC_Json(MC_Json&& otherJson);

	~MC_Json();

    template <typename Type>
    MC_Json(const MC_Vector2<Type>& aVector)
    {
        SerializeArray((Type*)&aVector, 2);
    }

    template <typename Type>
    MC_Json(const MC_Vector3<Type>& aVector)
    {
        SerializeArray((Type*)&aVector, 3);
    }

    template <typename Type>
    MC_Json(const MC_Vector4<Type>& aVector)
    {
        SerializeArray((Type*)&aVector, 4);
    }

    MC_Json& operator=(const MC_Json& otherJson)
    {
        if (this != &otherJson)
        {
            Destruct();
            myValueType = otherJson.myValueType;
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
        return *this;
    }

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

	bool GetJsonElement(const MC_String& anIdentifier, MC_Json& anOutEntry) const;
	bool GetJsonElement(s32 anIndex, MC_Json& anOutEntry) const;

	template <typename Type>
	bool GetElement(const MC_String& anIdentifier, MC_Vector2<Type>& anOutEntry) const;
	template <typename Type>
	bool GetElement(const MC_String& anIdentifier, MC_Vector3<Type>& anOutEntry) const;
	template <typename Type>
	bool GetElement(const MC_String& anIdentifier, MC_Vector4<Type>& anOutEntry) const;
	bool GetElement(const MC_String& anIdentifier, MC_String& anOutEntry) const;
	bool GetElement(const MC_String& anIdentifier, s32& anOutEntry) const;
	bool GetElement(const MC_String& anIdentifier, u32& anOutEntry) const;
	bool GetElement(const MC_String& anIdentifier, f32& anOutEntry) const;
	bool GetElement(s32 anIndex, s32& anOutEntry) const;
	bool GetElement(s32 anIndex, u32& anOutEntry) const;
	bool GetElement(s32 anIndex, f32& anOutEntry) const;

	static MC_Json FromFile(const char* aFilename);

	MC_String Serialize() const;
private:


    void Serialize(MC_String& str, s32 indentationLevel) const;
	static void Indent(MC_String& str, s32 indentationLevel);

    void Destruct();

    template <typename Type>
    void SerializeArray(Type* anArray, u32 aCount)
    {
        myValueType = ArrayType;
        myValueData.myArray = new Array();
        for (u32 idx = 0; idx < aCount; ++idx)
        {
            myValueData.myArray->Add(MC_Json(anArray[idx]));
        }
    }

	struct ParsingContext
	{
		char* myPtr;
	};

	static MC_Json Parse(ParsingContext& aCtxt);
	static MC_Json ParseString(ParsingContext& aCtxt);
	static MC_Json ParseArray(ParsingContext& aCtxt);
	static MC_Json ParseObject(ParsingContext& aCtxt);

	static void SkipWhitespace(char*& aString);

	ValueType myValueType;
	ValueData myValueData;
};


template <typename Type>
bool MC_Json::GetElement(const MC_String& anIdentifier, MC_Vector2<Type>& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);
	if (!result || !element.IsArray())
		return false;

	Type x = 0, y = 0;
	result = element.GetElement(0, x);
	result &= element.GetElement(1, y);
	if (!result)
		return false;

	Type dummy = 0;
	result = element.GetElement(2, dummy);
	if (result)
		return false;

	anOutEntry = MC_Vector2<Type>(x, y);
	return true;
}

template <typename Type>
bool MC_Json::GetElement(const MC_String& anIdentifier, MC_Vector3<Type>& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);
	if (!result || !element.IsArray())
		return false;

	Type x = 0, y = 0, z = 0;
	result = element.GetElement(0, x);
	result &= element.GetElement(1, y);
	result &= element.GetElement(2, z);
	if (!result)
		return false;

	Type dummy = 0;
	result = element.GetElement(3, dummy);
	if (result)
		return false;

	anOutEntry = MC_Vector3<Type>(x, y, z);
	return true;
}

template <typename Type>
bool MC_Json::GetElement(const MC_String& anIdentifier, MC_Vector4<Type>& anOutEntry) const
{
	MC_Json element;
	bool result = GetJsonElement(anIdentifier, element);
	if (!result || !element.IsArray())
		return false;

	Type x = 0, y = 0, z = 0, w = 0;
	result = element.GetElement(0, x);
	result &= element.GetElement(1, y);
	result &= element.GetElement(2, z);
	result &= element.GetElement(3, w);
	if (!result)
		return false;

	Type dummy = 0;
	result = element.GetElement(4, dummy);
	if (result)
		return false;

	anOutEntry = MC_Vector4<Type>(x, y, z, w);
	return true;
}