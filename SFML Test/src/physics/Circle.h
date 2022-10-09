#pragma once

#include "Entity.h"

struct Circle : public Entity {
public:
	Circle(sf::Vector2f position, float mass, sf::Color color, float radius) : Entity(position, mass, color) {
		this->radius = radius;
		//shape = std::make_unique<sf::CircleShape>(radius);
		shape.setRadius(radius);
		shape.setPosition(position);
		shape.setFillColor(color);
		shape.setOrigin(radius, radius);
	}

public:
	float radius;
	sf::CircleShape shape;

public:
	void draw(sf::RenderWindow& window);
	void updateShape(float dt);
	void updateCollision();

	// Getter & Setter

	float getRadius() const { return radius; }
	void setRadius(float radius) { this->radius = radius; }
};