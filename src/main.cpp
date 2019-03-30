#include "helper.h"

const int WIDTH = 800;
const int HEIGHT = 450;

BMP output;

Camera camera(vec3f(-5, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 0), 1, 1.6, 0.9, WIDTH, HEIGHT);
const vec3f CAM_POS(0, -5, 0);
const vec3f CAM_DIRECTION(0, 1, 0);
const float CAM_TOP = 4.5f;
const float CAM_LEFT = -8.0f;
const float CAM_RIGHT = 8.0f;
const float CAM_BOTTOM = -4.5f;

const vec3f SPHERE_POS(0, 10, 0);
const float SPHERE_RAD = 3;
const vec3f SPHERE_COL(1, 0, 0);

RGBApixel trace(int x, int y)
{
	// RAY Gen
	float u = CAM_LEFT + (((CAM_RIGHT - CAM_LEFT) * x) / WIDTH);
	float v = CAM_TOP + (((CAM_BOTTOM - CAM_TOP) * y) / HEIGHT);
	vec3f ray(CAM_DIRECTION.x + u, CAM_DIRECTION.y, CAM_DIRECTION.z + v);

	// schnittpunkt mit kreis berechnen
	vec3f ec = CAM_POS - SPHERE_POS;
	float a = ray * ray;
	float b = (ray * 2) * ec;
	float c = (ec * ec) - (SPHERE_RAD * SPHERE_RAD);

	float dis = (b * b) - (4 * a * c);

	return dis >= 0 ? RGBA(SPHERE_COL) : RGBA(0, 0, 0, 255);
}

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

	// raytrace
	for (Camera::iterator it = camera.begin(); it != camera.end(); ++it)
	{
		data[index++] = trace(camera.getPos(), *it);
	}

	// create and store image
	output.SetSize(WIDTH, HEIGHT);
	output.SetBitDepth(8);

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			output.SetPixel(x, y, data[y * WIDTH + x]);
		}
	}

	output.WriteToFile("output.bmp");

	// end
	return 0;
}
