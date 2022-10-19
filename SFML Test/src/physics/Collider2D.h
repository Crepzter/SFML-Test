#pragma once

#include "Circle.h"
#include "../Math.h"

#include <cmath>

namespace detect {
	// Point in Line
	bool point_line(sf::Vector2f& point, sf::Vector2f& start, sf::Vector2f& end)
	{
		float dx = end.x - start.x;
		float dy = end.y - start.y;

		if (dx == 0.0f) {
			return point.x == start.x;
		}

		// mx + b
		float m = dy / dx;
		float b = end.y - m * end.x;

		// Insert Point into: mx + b
		return point.y = m * point.x + b;
	}

	// Point in Circle
	bool point_circle(sf::Vector2f& point, Circle& circle)
	{
		float r = circle.getRadius();
		
		// Connection Point and Circlecenter
		sf::Vector2f c = circle.getPosition();
		sf::Vector2f pc = c - point;

		float d = sfm::lengthSqr(pc);

		return r*r >= d;
	}

	// Point in AABB
	bool point_aabb(sf::Vector2f& point, sf::Vector2f& min, sf::Vector2f& max)
	{
		return point.x >= min.x && point.x <= max.x && point.y >= min.y && point.y <= max.y;
	}

	// Point in OBB
	bool point_obb(sf::Vector2f& point, sf::Vector2f& min, sf::Vector2f& max, float rotation)
	{
		sf::Vector2f center = 0.5f * (min + max);
		sf::Vector2f rpoint = sfm::rotate(point, center, 360 - rotation);
		return point_aabb(rpoint, min, max);
	}

	// Line in Circle
	bool line_circle(sf::Vector2f& start, sf::Vector2f& end, Circle& circle)
	{
		return false;
	}

	//Line in AABB

	// Line in OBB

	// Circle in Circle
	bool circle_circle(Circle& c1, Circle& c2)
	{
		sf::Vector2f cc = c1.getPosition() - c2.getPosition();
		float disSqr = (c1.getRadius() + c2.getRadius()) * (c1.getRadius() + c2.getRadius()) - sfm::lengthSqr(cc);

		return disSqr > 0;
	}

	// Circle in AABB

	// Circle in OBB
}

namespace respond {
	void circle_circle(Circle& c1, Circle& c2)
	{
		sf::Vector2f cc = c1.getPosition() - c2.getPosition();
		float dis = c1.getRadius() + c2.getRadius() - sfm::length(cc);

		float a = c1.getRadius() / (c1.getRadius() + c2.getRadius());
		sf::Vector2f normal = sfm::norm(cc);
		
		c1.setPosition(c1.getPosition() + a * normal * dis);
		c2.setPosition(c2.getPosition() - (1.0f - a) * normal * dis);

		sf::Vector2f relVel = c1.getVelocity() - c2.getVelocity();
		float sepVel = sfm::dot(relVel, normal);

		float newSepVel = -1 * sepVel;
		float sepVelDiff = newSepVel - sepVel;
		float impulse = sepVelDiff / (1/c1.getMass() + 1/c2.getMass());
		sf::Vector2f impulseVec = normal * impulse;

		c1.setVelocity(c1.getVelocity() + impulseVec / c1.getMass());
		c2.setVelocity(c2.getVelocity() + -1.0f * impulseVec / c2.getMass());
	}
}