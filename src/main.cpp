#include "helper.h"

const int WIDTH = 800;
const int HEIGHT = 450;

BMP output;

Camera camera(vec3f(-5, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 0), 2, 1.6, 0.9, WIDTH, HEIGHT);
Sphere sphere(vec3f(10, 0, 0), 5, vec4f(1, 0, 0, 1));

vec3f light_dir(-1, -1, -1);

RGBApixel trace(vec3f origin, vec3f direction)
{
	float t = sphere.intersect(origin, direction);

	if (t <= 0)
	{
		return RGBA(0, 0, 0, 1);
	}

	vec3f hit = origin + (direction * t);
	vec3f norm = sphere.getNormal(hit);
	light_dir.normalize();

	vec3f r = (norm * 2 * (norm * light_dir)) - light_dir;

	float diffuse = 0.3 + (0.6 * (norm * light_dir)) + (0.1 * pow((r * (direction * -1)), 5));

	diffuse = diffuse > 1 ? 1 : (diffuse < 0 ? 0 : diffuse);

	return RGBA(sphere.getColor(hit) * diffuse);
}

int main()
{
	// create image
	output.SetSize(WIDTH, HEIGHT);
	//output.SetBitDepth(8);

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
