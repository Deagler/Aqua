#pragma once

//Windows
#include <cmath>

typedef float vec_t;
typedef float matrix3x4_t[3][4];
typedef float VMatrix[4][4];
class Vector
{
public:
	vec_t x, y, z;

	Vector(void)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vector(vec_t x, vec_t y, vec_t z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	inline float Distance(Vector &other)
	{
		return(std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2) + std::pow(other.z - this->z, 2)));
	}

	inline float Distance2D(Vector &other)
	{
		return(std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2)));
	}

	inline Vector operator =(const Vector &other)
	{
		return (Vector(other.x, other.y, other.z));
	}

	inline vec_t operator [](int index)
	{
		if (index >= 0 && index < 3)
			return (((vec_t *)(this))[index]);

		return 0;
	}

	inline bool operator ==(const Vector& other)
	{
		return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
	}

	inline bool operator !=(const Vector& other)
	{
		return ((this->x != other.x) || (this->y != other.y) || (this->z != other.z));
	}

	inline Vector & operator +=(const Vector& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
		return (*this);
	}

	inline Vector & operator -=(const Vector& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		return (*this);
	}

	inline Vector& operator *=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return (*this);
	}

	inline Vector operator +(const Vector &vec)
	{
		Vector out(this->x + vec.x, this->y + vec.y, this->z + vec.z);

		return (out);
	}

	inline Vector operator -(const Vector &vec)
	{
		Vector out(this->x - vec.x, this->y - vec.y, this->z - vec.z);

		return (out);
	}

	inline Vector operator *(float scalar)
	{
		Vector out(this->x * scalar, this->y * scalar, this->z * scalar);

		return (out);
	}

	inline float Dot(const Vector& a)
	{
		return(a.x*this->x + a.y*this->y + a.z*this->z);
	}
};

