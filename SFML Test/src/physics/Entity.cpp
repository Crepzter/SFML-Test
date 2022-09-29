#include "Entity.h"

#include <SFML\Graphics.hpp>

void Entity::update(float dt) {
	updateMovement(dt);
	updateCollision();
	updateShape(dt);
}

void Entity::updateMovement(float dt) {
	//TODO Fix this
	velocity = velocity * 0.999f + (acceleration + sf::Vector2f(0, 0.001f)) * dt;
	position = position + velocity * dt;
}
/*
void Entity::updateShape(float dt) {
	//shape->setPosition(position);
}
*/
/*
void Entity::draw(sf::RenderWindow* window) {
	window->draw(shape);
}
*/