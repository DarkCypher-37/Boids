#ifndef __BOID_HPP__
#define __BOID_HPP__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>



#include "Vector2D.hpp"

class Vector2D;



class Boid
{
private:
	sf::Vector2f transform_Vec2D(Vector2D& v);
public:
	float max_speed;
	Vector2D acceleration;
	Vector2D speed;
	Vector2D pos;
	sf::CircleShape shape;


public:
	Boid();
	Boid(float _x, float _y);

	void update(std::vector<Boid>& boids);
	void move(int width, int height);



};

#endif