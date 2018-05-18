#pragma once

#include "MC_GrowingArray.h"
#include "MC_HashMap.h"
#include "MC_String.h"
#include "MC_Vector.h"

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
	MC_Json(const MC_String& aString);
	MC_Json(const Array& anArray);
	MC_Json(const Object& anObject);

    MC_Json(Object&& anObject)
        : myValueType(ObjectType)
    {
        //TODO[Nomoresleep]: why is the move constructor not called without MC_Move?
        myValueData.myObject = new Object(MC_Move(anObject));
    }

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

    MC_Json(const MC_Json& otherJson)
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

    MC_Json(MC_Json&& otherJson)
        : myValueType(otherJson.myValueType)
    {
        memcpy(&myValueData, &otherJson.myValueData, sizeof(ValueData));
        memset(&otherJson.myValueData, 0, sizeof(ValueData));
        otherJson.myValueType = NullType;
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

	bool GetElement(const MC_String& anIdentifier, MC_Json& anOutEntry) const;
	bool GetElement(s32 anIndex, MC_Json& anOutEntry) const;

	~MC_Json();

    MC_String Serialize() const;

private:
    void Serialize(MC_String& str, s32 indentationLevel) const;

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

	ValueType myValueType;
	ValueData myValueData;
};