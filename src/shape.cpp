#include "shape.h"

vec3f Shape::getPosition() const
{
	return this->pos;
}

vec4f Sphere::getColor(const vec3f pos) const
{
	return this->color;
}

vec3f Sphere::getNormal(const vec3f pos) const
{
	vec3f ret = pos - this->getPosition();
	ret.normalize();
	return ret;
}

float Sphere::intersect(const vec3f ori, const vec3f dir) const
{
	const vec3f diff = ori - this->getPosition();
	const float a = dir * dir;
	const float b = (dir * 2) * diff;
	const float c = (diff * diff) - (this->size * this->size);
	const float disk = (b * b) - (4 * a * c);

	if (disk < 0)
	{
		return -1;
	}
	else if (disk == 0)
	{
		return (-1 * b) / (2 * a);
	}
	else
	{
		const float t1 = ((-1 * b) + sqrt(disk)) / (2 * a);
		const float t2 = ((-1 * b) - sqrt(disk)) / (2 * a);

		return t1 < t2 ? t1 : t2;
	}
}
