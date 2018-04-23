#pragma once

#include "imgui.h"
#include "ui_property.h"

namespace ui
{
    template <typename T>
    class Slider
    {
    public:
        virtual void Render() const = 0;

        Property<T>* myProperty;
        const char* myLabel;
    };

    class FloatSlider : public Slider<float>
    {
    public:
        FloatSlider(Property<float>* aProperty, const char* aLabel);
        void Render() const override;
    };
};