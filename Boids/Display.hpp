#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <SFML/Graphics.hpp>
#include <vector>

#include "Boid.hpp"
#include "Vector2D.hpp"

// declare Boid to avoid inlcude loops
class Boid;

class Display {
	private:
		int width;
		int height;
		int quantity;

		// window to render on the screen
		sf::RenderWindow window;

	public:
		// vector containing all the boids
		std::vector<Boid> boids;

		// constructor
		Display();
		Display(int quantity);

		void mainloop();
		void draw();
};
#endif