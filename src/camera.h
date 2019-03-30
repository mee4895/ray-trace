#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"

class Camera
{
	public:
		class iterator
		{
			public:
				iterator() { }
				iterator(vec3f base, vec3f u_min, vec3f u_step, vec3f u_max, vec3f v_min,
						vec3f v_step, vec3f v_max) : u(u_min), v(v_min), base(base), u_min(u_min), u_step(u_step),
						u_max(u_max), v_min(v_min), v_step(v_step), v_max(v_max) { }

				iterator& operator++()
				{
					if (u == u_max)
					{
						if (v == v_max)
						{
							throw std::out_of_range("Can't advance iterator.");
						}
						else
						{
							u = u_min;
							v += v_step;
						}
					}
					else
					{
						u += u_step;
					}

					return *this;
				}

				iterator operator++(int)
				{
					iterator old_this = *this;
					++(*this);
					return old_this;
				}

				bool operator==(const iterator other) const
				{
					return (this->u == other.u) && (this->v == other.v);
				}

				bool operator!=(const iterator other) const
				{
					return (this->u != other.u) || (this->v != other.v);
				}

				vec3f operator*() const
				{
					return u + v - base;
				}

			protected:
			private:
				vec3f u;
				vec3f v;

				const vec3f base;

				const vec3f u_min;
				const vec3f u_step;
				const vec3f u_max;

				const vec3f v_min;
				const vec3f v_step;
				const vec3f v_max;
		};

		Camera(vec3f position, vec3f up, vec3f look_at, float d, float render_width,
				float render_height, int width, int height) :
			position(position), up(up), look_at(look_at), d(d), t(render_height * -1),
			l(render_width * -1), r(render_width), b(render_height), width(width), height(height)
		{
			this->w = this->position - this->look_at;
			this->w.normalize();

			this->u = vec3f::dot(this->up, this->w);
			this->u.normalize();

			this->v = vec3f::dot(this->w, this->u);
			this->v.normalize();
		}

		iterator begin()
		{
			return iterator(
				w * d,
				u * (l + (r - l) * 0.5 / width),
				u * ((r - l) / width),
				u * (l + (r - l) * (width - 0.5) / width),
				v * (t + (b - t) * 0.5 / height),
				v * ((b - t) / height),
				v * (t + (b - t) * (height - 0.5) / height)
			);
		}

		iterator end()
		{
			vec3f u_max = u * (l + (r - l) * (width - 0.5) / width);
			vec3f v_max = v * (t + (b - t) * (height - 0.5) / height);

			return iterator(w * d, u_max, vec3f(), u_max, v_max, vec3f(), v_max);
		}

		vec3f getPos() const
		{
			return position;
		}

	protected:
	private:
		// camera location
		vec3f position;
		vec3f up;
		vec3f look_at;

		// camera local vectors
		vec3f u;
		vec3f v;
		vec3f w;

		// picture frame
		float d;
		float t;
		float l;
		float r;
		float b;

		// pixel data
		int width;
		int height;
};

#endif // CAMERA_H
