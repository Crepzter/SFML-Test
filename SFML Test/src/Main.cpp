#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML\Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1520, 900), "Test");
	window.setFramerateLimit(144);
	sf::Event e;

	sf::CircleShape circle(100.0f);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(100.0f, 300.0f); //circle.setPosition(sf::Vector2f(100.0f, 300.0f));

	sf::RectangleShape rect(sf::Vector2f(200.0f, 200.0f));
	rect.setPosition(500.0f, 300.0f); //rect.setPosition(sf::Vector2f(500.0f, 300.0f));

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) window.close();
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}

		// Render
		window.clear();

		window.draw(circle);
		window.draw(rect);

		window.display();
	}

	return 0;
}