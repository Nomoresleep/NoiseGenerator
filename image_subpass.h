#pragma once 

#include "types.h"
#include "node.h"

class ImageSubPass
{
public:
private:

};

struct PerlinNoiseConstants
{
	f32 myFrequency;
	f32 myAmplitude;
	u32 mySeed;
};

class PerlinNoise2D : public ImageSubPass, public Node
{
public:
	PerlinNoise2D(int anID, const char* aName, const MC_Vector2f& aPosition)
		: Node(anID, aName, aPosition)
	{
		AddInputPort(new InputPort(PortType::FloatPort, new Property<f32>(&myConstants.myFrequency, 0.0f, 20.0f)));
		AddInputPort(new InputPort(PortType::FloatPort, new Property<f32>(&myConstants.myAmplitude, -2.0f, 2.0f)));
		AddInputPort(new InputPort(PortType::UIntPort, new Property<u32>(&myConstants.mySeed, 0, U32_MAX)));

		//Add Properties

		AddOutputPort(new OutputPort(PortType::FloatPort));
	}
private:
	PerlinNoiseConstants myConstants;
};