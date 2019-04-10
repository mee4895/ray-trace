#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"

class Camera
{
	public:
		class iterator
		{
			public:
				iterator(int x, int y) : x(x), y(y), x_max(x), y_max(y), u(), v(),
						base(), u_min(), v_min(), u_step(), v_step() { }
				iterator(vec3f base, int x_max, int y_max, vec3f u_min, vec3f u_step,
						vec3f v_min, vec3f v_step) : x(0), y(0), x_max(x_max),
						y_max(y_max), u(u_min), v(v_min), base(base), u_min(u_min),
						v_min(v_min), u_step(u_step), v_step(v_step) { }

				iterator& operator++()
				{
					if (x == x_max)
					{
						if (y == y_max)
						{
							throw std::out_of_range("Can't advance iterator.");
						}
						else
						{
							x = 0;
							y += 1;

							u = u_min;
							v += v_step;
						}
					}
					else
					{
						x += 1;
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
					return (this->x == other.x) && (this->y == other.y);
				}

				bool operator!=(const iterator other) const
				{
					return (this->x != other.x) || (this->y != other.y);
				}

				vec3f operator*() const
				{
					return u + v - base;
				}

				int getX() const
				{
					return this->x;
				}

				int getY() const
				{
					return this->y;
				}

			protected:
			private:
				int x;
				int y;

				int x_max;
				int y_max;

				vec3f u;
				vec3f v;

				const vec3f base;

				const vec3f u_min;
				const vec3f v_min;

				const vec3f u_step;
				const vec3f v_step;
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
				width - 1,
				height - 1,
				u * (l + (r - l) * 0.5 / width),
				u * ((r - l) / width),
				v * (t + (b - t) * 0.5 / height),
				v * ((b - t) / height)
			);
		}

		iterator end()
		{
			return iterator(width - 1, height - 1);
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
