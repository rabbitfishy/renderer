#pragma once

class vector
{
public:
	constexpr vector() : x{ }, y{ } { }
	constexpr vector(float x, float y) : x{ x }, y{ y } { }
	constexpr vector(const vector& v) : x{ v.x }, y{ v.y } { }

	// equality operators.
	bool operator==(const vector& v) const { return v.x == this->x && v.y == this->y; }
	bool operator!=(const vector& v) const { return v.x != this->x || v.y != this->y; }

	// copy assignment.
	constexpr vector& operator=(const vector& v)
	{
		this->x = v.x; this->y = v.y;
		return *this;
	}

	// negation-operator.
	constexpr vector operator-() const { return vector{ -this->x, -this->y }; }

	// arithmetic operators.
	vector operator+(const vector& v) const { return { this->x + v.x, this->y + v.y }; }
	vector operator-(const vector& v) const { return { this->x - v.x, this->y - v.y }; }
	vector operator*(const vector& v) const { return { this->x * v.x, this->y * v.y }; }
	vector operator/(const vector& v) const { return { this->x / v.x, this->y / v.y }; }

	float x, y;
};

class rect
{
public:
	constexpr rect() : x{ }, y{ }, w{ }, h{ } { }
	constexpr rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } { }
	int x, y, w, h;
};

class dimension
{
public:
	constexpr dimension() : w{ }, h{ } { }
	constexpr dimension(int w, int h) : w{ w }, h{ h } { }
	int w, h;
};

// NOTE: it must be float values for it to render otherwise shit won't render anything in directx.
// that is why i put it here to use vector 2d's to render so it must be float value!!!!
class vertex
{
public:
	vertex() : position{ }, coordinate{ }, colour{ } { }
	vertex(const vector& position, const vector& coordinate, const DWORD colour)
	{
		this->position		= position;
		this->coordinate	= coordinate;
		this->colour		= colour;
	}

	vector	position;
	vector	coordinate;
	DWORD	colour;
};