#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

struct Entity {
	Entity(sf::Vector2f position) {
		this->position = position;
		this->velocity = sf::Vector2f(0.0f, 0.0f);
		this->acceleration = sf::Vector2f(0.001f, 0.001f);
	};

private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float rotation = 0.0f;

public:
	sf::Vector2f getPosition() {
		return position;
	}
	void setPosition(sf::Vector2f position) {
		this->position = position;
	}
	sf::Vector2f getVelocity() {
		return velocity;
	}
	void setVelocity(sf::Vector2f velocity) {
		this->velocity = velocity;
	}
	sf::Vector2f getAcceleration() {
		return acceleration;
	}
	void setAcceleration(sf::Vector2f acceleration) {
		this->acceleration = acceleration;
	}

	void updateMovement(float dt) {
		//TODO Fix this
		if(velocity.x < 4.0f && velocity.y < 4.0f && velocity.x > -4.0f && velocity.y > -4.0f) velocity = velocity + acceleration * dt;
		position = position + velocity * dt;

		int bound_x1 = 100, bound_x2 = 900, bound_y1 = 100, bound_y2 = 800;

		if (position.x < bound_x1) {
			velocity.x *= -1; acceleration.x *= -1; 
			position.x = bound_x1;
		}
		else if (position.x > 900) {
			velocity.x *= -1; acceleration.x *= -1;
			position.x = 900;
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
};