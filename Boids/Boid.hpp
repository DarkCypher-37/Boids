#ifndef __BOID_HPP__
#define __BOID_HPP__

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Vector2D.hpp"

class Vector2D;

class Boid
{
private:

public:
	Vector2D velocity;
	Vector2D position;
	sf::CircleShape shape;

public:
	Boid();
	Boid(float _x, float _y);

	void update(std::vector<Boid>& boids);
	void move(int width, int height);
};

#endif