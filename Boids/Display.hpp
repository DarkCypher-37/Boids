#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector> 


#include "Boid.hpp"

class Boid;


class Display
{
private:
	int width;
	int height;

public:
	int amount;

	sf::RenderWindow window;
	sf::VideoMode Desktop = sf::VideoMode::getDesktopMode();
	std::vector<Boid> boids;
public:
	Display();
	Display(int amount);

	void main_loop();
	void draw();
};

#endif