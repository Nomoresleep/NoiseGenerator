// Custom Heap Datastructure addition to Massives Massgate MCommon library
#pragma once 
#ifndef MC_BINARYHEAP_HEADER
#define MC_BINARYHEAP_HEADER

#include "MC_GrowingArray.h"

template <class Type, class COMPARER>
class MC_BinaryHeap
{
public:
    MC_BinaryHeap(u32 aReserveSize)
        : myData(aReserveSize)
    {

    }

    void Push(const Type& anElement)
    {
        s32 i = myData.Count();
        myData.Add(anElement);
        while (i > 0 && !COMPARER::LessThan(myData[Parent(i)], myData[i]))
        {
            MC_Swap(myData[Parent(i)], myData[i]);
            i = Parent(i);
        }
    }

    void PushUnique(const Type& anElement)
    {
        s32 i = myData.Count();
        myData.AddUnique(anElement);
        if (i != myData.Count())
        {
            while (i > 0 && !COMPARER::LessThan(myData[Parent(i)], myData[i]))
            {
                MC_Swap(myData[Parent(i)], myData[i]);
                i = Parent(i);
            }
        }
    }

    Type Pop()
    {
        Type result = myData.GetFirst();
        MC_Swap(myData[0], myData[myData.Count() - 1]);
        myData.RemoveLast();
        Heapify(0);
        return result;
    }

    bool IsEmpty() const { return myData.Count() == 0; }
protected:

    static s32 Parent(s32 aChildIndex) { return aChildIndex / 2; }
    static s32 Left(s32 aParentIndex) { return aParentIndex * 2; }
    static s32 Right(s32 aParentIndex) { return aParentIndex * 2 + 1; }

    void Heapify(s32 anUnheapedIndex)
    {
        s32 i = anUnheapedIndex;
        do {
            s32 min = i;
            if (Left(i) < myData.Count() && COMPARER::LessThan(myData[Left(i)], myData[min]))
                min = Left(i);
            if (Right(i) < myData.Count() && COMPARER::LessThan(myData[Right(i)], myData[min]))
                min = Right(i);
            if (min == i)
                break;
            MC_Swap(myData[i], myData[min]);
            i = min;
        } while (true);
    }

    MC_GrowingArray<Type> myData;
};

#endif