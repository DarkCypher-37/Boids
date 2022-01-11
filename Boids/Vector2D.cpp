#include "Vector2D.hpp"


Vector2D::Vector2D()
{
	x = 1;
	y = 1;
}

Vector2D::Vector2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

float Vector2D::distance(Vector2D& v)
{
	return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

float Vector2D::magnitude()
{
	return sqrt(x * x + y * y);
}

void Vector2D::nomalize()
{
	float m = magnitude();

	if (m > 0) {
		x /= m;
		y /= m;
	}
}

void Vector2D::limit(float max)
{
	float size = magnitude();
	if (size > max) {
		this->x = x / size;
		this->y = y / size;
	}
}

float Vector2D::angle()
{
	return atan(y / x) * 180 / 3.141592635f;
}

float Vector2D::get_x()
{
	return x;
}

float Vector2D::get_y()
{
	return y;
}

void Vector2D::set_x(float _x)
{
	this->x = _x;
}

void Vector2D::set_y(float _y)
{
	this->y = _y;
}

void Vector2D::set(float _x, float _y)
{
	x = _x;
	y = _y;
}




void Vector2D::addNum(const float val)
{
	x += val;
	y += val;
}

void Vector2D::subNum(const float val)
{
	x -= val;
	y -= val;
}

void Vector2D::mulNum(const float val)
{
	x *= val;
	y *= val;
}

void Vector2D::divNum(const float val)
{
	x /= val;
	y /= val;
}

void Vector2D::operator=(Vector2D v)
{
	this->x = v.x;
	this->y = v.y;
}

void Vector2D::operator=(float input)
{
	this->x = input;
	this->y = input;
}

void Vector2D::operator+=(const Vector2D& v)
{
	x += v.x;
	y += v.y;
}


Vector2D Vector2D::operator-()
{
	return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(float f)
{
	return Vector2D(x*f, y*f);
}

Vector2D Vector2D::operator-(const Vector2D& v)
{
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D Vector2D::operator+(const Vector2D& v)
{
	return Vector2D(this->x + v.x, this->y + v.y);
}

void Vector2D::operator-=(const Vector2D& v)
{
	x -= v.x;
	y -= v.y;
}

void Vector2D::operator*=(const Vector2D& v)
{
	x *= v.x;
	y *= v.y;
}

void Vector2D::operator/=(const Vector2D& v)
{
	x /= v.x;
	y /= v.y;
}