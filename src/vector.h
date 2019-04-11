#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <cmath>

class vec2l
{
	public:
		long x;
		long y;

		vec2l()
		{
			this->x = 0l;
			this->y = 0l;
		}

		vec2l(long x, long y)
		{
			this->x = x;
			this->y = y;
		}

		long operator[] (int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

	protected:
	private:
};

class vec3l
{
	public:
		long x;
		long y;
		long z;

		vec3l()
		{
			this->x = 0l;
			this->y = 0l;
			this->z = 0l;
		}

		vec3l(long x, long y, long z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		long operator[] (int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

	protected:
	private:
};

class vec4l
{
	public:
		long x;
		long y;
		long z;
		long d;

		vec4l()
		{
			this->x = 0l;
			this->y = 0l;
			this->z = 0l;
			this->d = 0l;
		}

		vec4l(long x, long y, long z, long d)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->d = d;
		}

		long operator[] (int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				case 3:
					return d;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

	protected:
	private:
};

class vec2f
{
	public:
		float x;
		float y;

		vec2f()
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}

		vec2f(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		float operator[] (int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

	protected:
	private:
};

class vec3f
{
	public:
		float x;
		float y;
		float z;

		vec3f()
		{
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		vec3f(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		const float operator[] (const int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

		vec3f operator* (const float other) const
		{
			return vec3f(this->x * other, this->y * other, this->z * other);
		}

		float operator* (const vec3f other) const
		{
			return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
		}

		vec3f operator+ (const vec3f other) const
		{
			return vec3f(this->x + other.x, this->y + other.y, this->z + other.z);
		}

		void operator+= (const vec3f other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		vec3f operator- (const vec3f other) const
		{
			return vec3f(this->x - other.x, this->y - other.y, this->z - other.z);
		}

		void operator-= (const vec3f other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		bool operator== (const vec3f other) const
		{
			return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
		}

		bool operator!= (const vec3f other) const
		{
			return (this->x != other.x) || (this->y != other.y) || (this->z != other.z);
		}

		float length()
		{
			return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
		}

		void normalize()
		{
			float l = this->length();
			this->x /= l;
			this->y /= l;
			this->z /= l;
		}

		static vec3f dot(const vec3f a, const vec3f b)
		{
			return vec3f(
				(a.y * b.z) - (a.z * b.y),
				(a.z * b.x) - (a.x * b.z),
				(a.x * b.y) - (a.y * b.x)
			);
		}

	protected:
	private:
};

class vec4f
{
	public:
		float x;
		float y;
		float z;
		float d;

		vec4f()
		{
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
			this->d = 0.0f;
		}

		vec4f(float x, float y, float z, float d)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->d = d;
		}

		float operator[] (int index)
		{
			switch (index)
			{
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				case 3:
					return d;
				default:
					throw std::out_of_range("Index out of range.");
			}
		}

		vec4f operator* (const float other) const
		{
			return vec4f(this->x * other, this->y * other, this->z * other, this->d * other);
		}

		float operator* (const vec4f other) const
		{
			return (this->x * other.x) + (this->y * other.y) + (this->z * other.z) + (this->d * other.d);
		}

	protected:
	private:
};

#endif // VECTOR_H
