#include "ui_slider.h"

ui::FloatSlider::FloatSlider(Property<float>* aProperty, const char* aLabel)
{
    myProperty = aProperty;
    myLabel = aLabel;
}
        
void ui::FloatSlider::Render() const
{
    ImGui::SliderFloat(myLabel, &myProperty->myValue, myProperty->myMin, myProperty->myMax);
}