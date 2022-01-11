#include "Display.hpp"

bool vector_in_bounds(sf::Vector2i mouse, Vector2D coords, Vector2D size) {
	if (static_cast<float>(mouse.x) > coords.x && static_cast<float>(mouse.x) < coords.x+size.x &&
		static_cast<float>(mouse.y) > coords.y && static_cast<float>(mouse.y) < coords.y+size.y) {
		
		return true;
	}
	return false;
}

Display::Display() {
	// getting the width and height of the screen
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = desktop.width;
	height = desktop.height;

	// set the quantity of boids
	int quantity = 30;

	// create the window
	window.create(sf::VideoMode(width, height, desktop.bitsPerPixel), "Boids", sf::Style::None);
	// limit the Framerate at 60 FPS
	window.setFramerateLimit(60);
	// apppend the boids to the boid vector
	for (int i = 0; i < quantity; i++) {
		boids.push_back(Boid());
	}

	seperationWeight = 1.f;
	alignmentWeight = 1.f;
	cohesionWeight = 1.f;

	box_seperation.setPosition(sf::Vector2f(50.f, 50.f));
	box_seperation.setSize(sf::Vector2f(50.f, 50.f));
	box_seperation.setFillColor(sf::Color(255, 0, 0));

	box_alignment.setPosition(sf::Vector2f(110.f, 50.f));
	box_alignment.setSize(sf::Vector2f(50.f, 50.f));
	box_alignment.setFillColor(sf::Color(0, 255, 0));

	box_cohesion.setPosition(sf::Vector2f(170.f, 50.f));
	box_cohesion.setSize(sf::Vector2f(50.f, 50.f));
	box_cohesion.setFillColor(sf::Color(0, 0, 255));

}

Display::Display(int quantity) {
	// getting the width and height of the screen
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = desktop.width;
	height = desktop.height;

	// create the window
	window.create(sf::VideoMode(width, height, desktop.bitsPerPixel), "Boids", sf::Style::None);
	// limit the Framerate at 60 FPS
	window.setFramerateLimit(60);

	// apppend the boids to the boid vector with a random position
	for (int i = 0; i < quantity; i++) {
		boids.push_back(Boid(rand() % width, rand() % height));
	}

	seperationWeight = 1.f;
	alignmentWeight = 1.f;
	cohesionWeight = 1.f;

	box_seperation.setPosition(sf::Vector2f(50.f, 50.f));
	box_seperation.setSize(sf::Vector2f(50.f, 50.f));
	box_seperation.setFillColor(sf::Color(50, 50, 50));

	seperation_text.setString("Seperation");
	seperation_text.setFillColor(sf::Color(200, 200, 200));
	seperation_text.setPosition(sf::Vector2f(50.f, 50.f));
	seperation_text.setCharacterSize(30);

	box_alignment.setPosition(sf::Vector2f(110.f, 50.f));
	box_alignment.setSize(sf::Vector2f(50.f, 50.f));
	box_alignment.setFillColor(sf::Color(50, 50, 50));

	box_cohesion.setPosition(sf::Vector2f(170.f, 50.f));
	box_cohesion.setSize(sf::Vector2f(50.f, 50.f));
	box_cohesion.setFillColor(sf::Color(50, 50, 50));

}

void Display::draw() {
	// CLEAR
	window.clear(sf::Color::Black);

	// DRAW
	window.draw(box_seperation);
	window.draw(box_alignment);
	window.draw(box_cohesion);

	window.draw(seperation_text);

	for (size_t i = 0; i < boids.size(); i++) {
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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// adding boids when the left mouse button is pressed
			sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
			if (vector_in_bounds(mouseCoords, Vector2D(50.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the first box
				seperationWeight -= 0.01;
				box_seperation.setFillColor(sf::Color());
			} else if (vector_in_bounds(mouseCoords, Vector2D(110.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the second box
				alignmentWeight -= 0.01;
			} else if (vector_in_bounds(mouseCoords, Vector2D(170.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the third box
				cohesionWeight -= 0.01;
			} else {
				Boid boid(static_cast<float>(mouseCoords.x), static_cast<float>(mouseCoords.y), sf::Color(255, 255, 0));
				boids.push_back(boid);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			// adding boids when the left mouse button is pressed
			sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
			if (vector_in_bounds(mouseCoords, Vector2D(50.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the first box
				seperationWeight = std::abs(std::fmod(seperationWeight + 0.01, 3));
			}
			else if (vector_in_bounds(mouseCoords, Vector2D(110.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the second box
				alignmentWeight = std::abs(std::fmod(alignmentWeight + 0.01, 3));
			}
			else if (vector_in_bounds(mouseCoords, Vector2D(170.f, 50.f), Vector2D(50.f, 50.f))) {
				// on the third box
				cohesionWeight = std::abs(std::fmod(cohesionWeight + 0.01, 3));
			}
			else {
				Boid boid(static_cast<float>(mouseCoords.x), static_cast<float>(mouseCoords.y), sf::Color(255, 255, 0));
				boids.push_back(boid);
			}
		}

		// update the position and movement of each boid
		for (size_t i = 0; i < boids.size(); i++) {
			boids[i].update_movement(boids, seperationWeight, alignmentWeight, cohesionWeight); // update the movement
			boids[i].update_position(width, height); // update the position
		}

		// draw the window
		draw();
	}
}