#pragma once

#include "imgui-SFML.h"

namespace Utils {
	
	sf::Color arrayColor(float color[3]) {
		return sf::Color(
			(int)(color[0] * 255),
			(int)(color[1] * 255),
			(int)(color[2] * 255)
		);
	}
	/*
	float* colorArray(sf::Color color) {
		return static int r[3] = { color.r / 255.0f, color.g / 255.0f, color.b / 255.0f };
	}*/
}