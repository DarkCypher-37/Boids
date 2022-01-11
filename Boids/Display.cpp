#include "Display.hpp"

Display::Display()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = desktop.width;
	height = desktop.height;

	amount = 2;
	window.create(sf::VideoMode(width, height, Desktop.bitsPerPixel), "Boids", sf::Style::None);
	window.setFramerateLimit(60);
	for (int i = 0; i < amount; i++) {
		boids.push_back(Boid(rand() % width, rand() % height));
	}
}

Display::Display(int _amount)
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	width = floor(desktop.width/1);
	height = floor(desktop.height/1);

	amount = _amount;
	window.create(sf::VideoMode(width, height, Desktop.bitsPerPixel), "Boids", sf::Style::None);
	window.setFramerateLimit(60);
	for (int i = 0; i < amount; i++) {
		boids.push_back(std::move(Boid(rand() % width, rand() % height)));
	}
}

void Display::draw()
{
	window.clear(sf::Color::Black);
	//Drawing
	//draw loop
	for (int i = 0; i < amount; i++) {
		window.draw(boids[i].shape);
	}
	window.display();
}



void Display::main_loop()
{

	while (window.isOpen()) {
		//update loop

		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}

		}
		for (int i = 0; i < boids.size(); i++) {
			boids[i].update(boids);
			boids[i].move(width, height);
		}
		draw();

	}

}