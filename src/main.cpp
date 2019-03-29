#include "helper.h"

const int WIDTH = 800;
const int HEIGHT = 450;

BMP output;

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

	return dis >= 0 ? RGBA(SPHERE_COL) : RGBA(255, 255, 255, 255);
}

int main()
{
	output.SetSize(WIDTH, HEIGHT);
	output.SetBitDepth(8);

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			output.SetPixel(x, y, trace(x, y));
		}
	}

	output.WriteToFile("output.bmp");
	return 0;
}
