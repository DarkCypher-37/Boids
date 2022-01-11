#ifndef __Vector2D_HPP__
#define __Vector2D_HPP__

#include <iostream>
#include <math.h> 
#include <SFML/Graphics.hpp>

// a class for a 2 dimensional Vector, using floats
class Vector2D{
	public:
		float x;
		float y;

	public:
		Vector2D();
		Vector2D(float _x, float _y);


		float distance(Vector2D& v);
		float magnitude();
		void nomalize();
		void limit(float max);

		// calculate the angle of the Vector
		float angle();

		// getters and setters for the vector
		float get_x();
		float get_y();

		void set_x(float _x);
		void set_y(float _y);
		void set(float _x, float _y);

		// unary minus
		Vector2D operator -();

		// variable assignment for floats
		void operator = (float val);
		// variable assignment for vectors
		void operator = (Vector2D v);

		// binary assingments for floats
		Vector2D operator *(float val);

		// binary assignemts for vectors
		Vector2D operator -(const Vector2D& v);
		Vector2D operator +(const Vector2D& v);

		// augmented assignments for floats
		void addNum(const float val);
		void subNum(const float val);
		void mulNum(const float val);
		void divNum(const float val);

		// augmented assignments for vectors
		void operator +=(const Vector2D& v);
		void operator -=(const Vector2D& v);
		void operator *=(const Vector2D& v);
		void operator /=(const Vector2D& v);
};

#endif