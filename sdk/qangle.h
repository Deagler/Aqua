#pragma once
typedef float vec_t;
class QAngle
{
public:
	vec_t x, y, z;

	QAngle(void)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	QAngle(vec_t x, vec_t y, vec_t z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	inline QAngle & operator =(const QAngle &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return *this;
	}

	inline vec_t& operator [](int index)
	{
		if (index >= 0 && index < 3)
			return (((vec_t *)(this))[index]);
	}

	inline bool operator ==(const QAngle& other)
	{
		return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
	}

	inline bool operator !=(const QAngle& other)
	{
		return ((this->x != other.x) || (this->y != other.y) || (this->z != other.z));
	}

	inline QAngle & operator +=(const QAngle& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
		return (*this);
	}

	inline QAngle & operator -=(const QAngle& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		return (*this);
	}

	inline QAngle& operator *=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return (*this);
	}

	inline QAngle operator +(const QAngle &vec)
	{
		QAngle out(this->x + vec.x, this->y + vec.y, this->z + vec.z);

		return (out);
	}

	inline QAngle operator -(const QAngle &vec)
	{
		QAngle out(this->x - vec.x, this->y - vec.y, this->z - vec.z);

		return (out);
	}

	inline QAngle operator *(float scalar)
	{
		QAngle out(this->x * scalar, this->y * scalar, this->z * scalar);

		return (out);
	}
};
