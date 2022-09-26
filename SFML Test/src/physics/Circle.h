#pragma once

#include "Entity.h"

class Circle : public Entity {
public:
	Circle(sf::Vector2f position, float radius) : Entity(position) {
		this->radius = radius;
	}

private:
	float radius;

public:

};