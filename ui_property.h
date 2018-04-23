#pragma once

#include "imgui.h"

namespace ui
{
    template <typename T>
    class Property
    {
    public:
        Property(T aMin, T aMax)
            : myMin(aMin)
            , myMax(aMax) {}

        void Set(T aValue) { myValue = min(myMax, max(myMin, aValue)); }
        const T& Get() const { return myValue; }
        T myValue;
        T myMin, myMax;
    };
};