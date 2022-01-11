#include "Display.hpp"

Display::Display()
{
	// getting the width and height of the screen
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = desktop.width;
	height = desktop.height;

	// set the amount of boids
	amount = 30;

	// create the window
	window.create(sf::VideoMode(width, height, Desktop.bitsPerPixel), "Boids", sf::Style::None);
	// limit the Framerate at 60 FPS
	window.setFramerateLimit(60);
	// apppend the boids to the boid vector
	for (int i = 0; i < amount; i++) {
		boids.push_back(Boid());
	}
}

Display::Display(int _amount)
{
	// getting the width and height of the screen
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = floor(desktop.width/1);
	height = floor(desktop.height/1);

	// set the amount of boids
	amount = _amount;

	// create the window
	window.create(sf::VideoMode(width, height, Desktop.bitsPerPixel), "Boids", sf::Style::None);
	// limit the Framerate at 60 FPS
	window.setFramerateLimit(60);

	// apppend the boids to the boid vector with a random position
	for (int i = 0; i < amount; i++) {
		boids.push_back(std::move(Boid(rand() % width, rand() % height)));
	}
}

void Display::draw()
{
	// CLEAR
	window.clear(sf::Color::Black);

	// DRAW
	for (int i = 0; i < amount; i++) {
		// draw every boid
		window.draw(boids[i].shape);
	}

	// DISPLAY
	window.display();
}

void Display::mainloop() {
	
	while (window.isOpen()) { // run the mainloop as long as the window is open
		//update loop

		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)){
				// close the window on close event or on ESC-keypress
				window.close();
			}

		}

		// update the position and movement of each boid
		for (int i = 0; i < boids.size(); i++) {
			boids[i].update(boids); // update movement
			boids[i].move(width, height); // update position
		}

		// draw the window
		draw();

	}

}