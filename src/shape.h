#ifndef SHAPE_H
#define SHAPE_H

#include <stdexcept>
#include <cmath>
#include "vector.h"

class Shape
{
	public:
		Shape(vec3f pos) : pos(pos) { }

		vec3f getPosition() const;

		virtual vec4f getColor(const vec3f pos) const = 0;
		virtual vec3f getNormal(const vec3f pos) const = 0;
		virtual float intersect(const vec3f ori, const vec3f dir) const = 0;

	protected:
	private:
		vec3f pos;
};

class Sphere : Shape
{
	public:
		Sphere(vec3f pos, float size, vec4f color) : Shape(pos), size(size), color(color) { }

		vec4f getColor(const vec3f pos) const;
		vec3f getNormal(const vec3f pos) const;
		float intersect(const vec3f ori, const vec3f dir) const;
	protected:
	private:
		float size;
		vec4f color;
};

#endif // SHAPE_H
