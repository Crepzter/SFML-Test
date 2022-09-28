#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

//#include "Utils.h"

struct Entity {
	Entity(sf::Vector2f position, sf::Color color, sf::Drawable drawable) {
		this->position = position;
		this->velocity = sf::Vector2f(0.0f, 0.0f);
		this->acceleration = sf::Vector2f(0.0f, 0.0f);
		rotation = 0.0f;
		this->color = color;
	};

public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float rotation;
	sf::Color color;

public:
	// Update

	void update(float dt);
	void updateMovement(float dt);
	void updateColor(float dt);

	// Getter & Setter

	sf::Vector2f getPosition() const { return position; }
	void setPosition(sf::Vector2f position) { this->position = position; }

	sf::Vector2f getVelocity() const { return velocity; }
	void setVelocity(sf::Vector2f velocity) { this->velocity = velocity; }

	sf::Vector2f getAcceleration() const { return acceleration; }
	void setAcceleration(sf::Vector2f acceleration) { this->acceleration = acceleration; }

	sf::Color getColor() const { return color; }
	void setColor(sf::Color color) { this->color = color; }
};