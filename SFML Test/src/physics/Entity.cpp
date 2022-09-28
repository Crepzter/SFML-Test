#include "Entity.h"

void Entity::update(float dt) {
	//TODO Fix this
	velocity = velocity * 0.999f + (acceleration+sf::Vector2f(0,0.001f)) * dt;
	position = position + velocity * dt;

	int bound_x1 = 100, bound_x2 = 1400, bound_y1 = 100, bound_y2 = 800;

	if (position.x < bound_x1) {
		velocity.x *= -1; acceleration.x *= -1;
		position.x = bound_x1;
	}
	else if (position.x > bound_x2) {
		velocity.x *= -1; acceleration.x *= -1;
		position.x = bound_x2;
	}
	if (position.y < bound_y1) {
		velocity.y *= -1; acceleration.y *= -1;
		position.y = bound_y1;
	}
	else if (position.y > bound_y2) {
		velocity.y *= -1; acceleration.y *= -1;
		position.y = bound_y2;
	}
}

void Entity::updateMovement(float dt) {

}

void Entity::updateColor(float dt) {

}