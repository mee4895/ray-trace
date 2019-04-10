#include <iostream>
#include "EasyBMP/EasyBMP.h"
#include "vector.h"
#include "camera.h"
#include "shape.h"

RGBApixel RGBA(const vec3f vector)
{
	RGBApixel color;

	color.Red = (int)(255.0f * vector.x) % 256;
	color.Green = (int)(255.0f * vector.y) % 256;
	color.Blue = (int)(255.0f * vector.z) % 256;
	color.Alpha = 255;

	return color;
}

RGBApixel RGBA(const vec4f vector)
{
	RGBApixel color;

	color.Red = (int)(255.0f * vector.x) % 256;
	color.Green = (int)(255.0f * vector.y) % 256;
	color.Blue = (int)(255.0f * vector.z) % 256;
	color.Alpha = (int)(255.0f * vector.d) % 256;

	return color;
}

RGBApixel RGBA(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
{
	RGBApixel color;

	color.Red = red;
	color.Green = green;
	color.Blue = blue;
	color.Alpha = alpha;

	return color;
}
