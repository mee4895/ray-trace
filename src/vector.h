#ifndef VECTOR_H
#define VECTOR_H

#include <exception>

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

		vec3f operator* (const float factor) const
		{
			return vec3f(this->x * factor, this->y * factor, this->z * factor);
		}

		float operator* (const vec3f vector) const
		{
			return (this->x * vector.x) + (this->y * vector.y) + (this->z * vector.z);
		}

		vec3f operator+ (const vec3f vector) const
		{
			return vec3f(this->x + vector.x, this->y + vector.y, this->z + vector.z);
		}

		vec3f operator- (const vec3f vector) const
		{
			return vec3f(this->x - vector.x, this->y - vector.y, this->z - vector.z);
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

	protected:
	private:
};

#endif // VECTOR_H
