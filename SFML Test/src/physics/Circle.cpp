#include "Circle.h"

#include <SFML\Graphics.hpp>

#include "../Math.h"

void Circle::updateCollision() {
	int bound_x1 = 0, bound_x2 = 1520, bound_y1 = 0, bound_y2 = 900;

	if (position.x-radius < bound_x1) {
		velocity.x *= -1; acceleration.x *= -1;
		position.x = bound_x1+radius;
	}
	else if (position.x+radius > bound_x2) {
		velocity.x *= -1; acceleration.x *= -1;
		position.x = bound_x2-radius;
	}
	if (position.y-radius < bound_y1) {
		velocity.y *= -1; acceleration.y *= -1;
		position.y = bound_y1+radius;
	}
	else if (position.y+radius > bound_y2) {
		velocity.y *= -1; acceleration.y *= -1;
		position.y = bound_y2-radius;
	}
}

void Circle::updateShape(float dt) {
	shape.setPosition(position);
	shape.setRadius(radius);
}

void Circle::draw(sf::RenderWindow& window) {
	window.draw(shape);
}