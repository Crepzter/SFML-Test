#pragma once

#include "Entity.h"

struct Circle : public Entity {
public:
	Circle(sf::Vector2f position, sf::Color color, float radius) : Entity(position, color) {
		this->radius = radius;
	}

public:
	float radius;

public:
	// Getter & Setter

	float getRadius() const { return radius; }
	void setRadius(float radius) { this->radius = radius; }
};