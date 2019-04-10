#include "helper.h"

const int WIDTH = 800;
const int HEIGHT = 450;

BMP output;

Camera camera(vec3f(-5, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 0), 2, 1.6, 0.9, WIDTH, HEIGHT);
Sphere sphere(vec3f(10, 0, 0), 5, vec4f(1, 0, 0, 1));

RGBApixel trace(vec3f origin, vec3f direction)
{
	float t = sphere.intersect(origin, direction);
	return t < 0 ? RGBA(0, 0, 0, 255) : RGBA(sphere.getColor(origin + (direction * t)));
}

int main()
{
	// create image
	output.SetSize(WIDTH, HEIGHT);
	output.SetBitDepth(8);

	// raytrace
	for (Camera::iterator it = camera.begin(); it != camera.end(); ++it)
	{
		output.SetPixel(it.getX(), it.getY(), trace(camera.getPos(), *it));
		std::cout << it.getX() << ", " << it.getY() << std::endl;
	}

	// write file
	output.WriteToFile("output.bmp");

	// end
	return 0;
}
