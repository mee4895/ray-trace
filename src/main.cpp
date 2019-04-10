#include "helper.h"

const int WIDTH = 800;
const int HEIGHT = 450;

BMP output;

Camera camera(vec3f(-5, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 0), 2, 1.6, 0.9, WIDTH, HEIGHT);
const vec3f CAM_POS(0, -5, 0);
const vec3f CAM_DIRECTION(0, 1, 0);
const float CAM_TOP = 4.5f;
const float CAM_LEFT = -8.0f;
const float CAM_RIGHT = 8.0f;
const float CAM_BOTTOM = -4.5f;

const vec3f SPHERE_POS(10, 0, 0);
const float SPHERE_RAD = 5;
const vec3f SPHERE_COL(1, 0, 0);

RGBApixel trace(vec3f origin, vec3f direction)
{
	vec3f ec = origin - SPHERE_POS;
	float a = direction * direction;
	float b = (direction * 2) * ec;
	float c = (ec * ec) - (SPHERE_RAD * SPHERE_RAD);

	float dis = (b * b) - (4 * a * c);

	return dis >= 0 ? RGBA(SPHERE_COL) : RGBA(0, 0, 0, 255);
}

int main()
{
	// setup
	RGBApixel* data = new RGBApixel[WIDTH * HEIGHT];
	int index = 0;

	// create image
	output.SetSize(WIDTH, HEIGHT);
	output.SetBitDepth(8);

	// raytrace
	for (Camera::iterator it = camera.begin(); it != camera.end(); ++it)
	{
		output.SetPixel(it.getX(), it.getY(), trace(camera.getPos(), *it));
		std::cout << it.getX() << ' ' << it.getY() << std::endl;
	}

	// write file
	output.WriteToFile("output.bmp");

	// end
	return 0;
}
