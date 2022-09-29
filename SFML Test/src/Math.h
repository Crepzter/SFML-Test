#pragma once

#include <cmath>
#include <type_traits>
#include <concepts>

#include <SFML/System/Vector2.hpp>

namespace sfm {
	// Length
	//template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
	//template <typename T>
	template <std::floating_point T>
	constexpr T length(sf::Vector2<T> v) {
		return std::sqrtf(v.x * v.x + v.y * v.y);
	}
	
	// Normalization
	template <std::floating_point T>
	constexpr sf::Vector2f norm(sf::Vector2<T> v) {
		return v * (1 / sfm::length(v));
	}
	
	// Dot Product
	template <std::floating_point T>
	constexpr float dot(sf::Vector2<T> v1, sf::Vector2<T> v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	// Angle
	template <std::floating_point T>
	constexpr float angle(sf::Vector2<T> v1, sf::Vector2<T> v2) {
		return std::acosf(sfm::dot(v1, v2) / (sfm::length(v1) * sfm::length(v2)));
	}
	
	// Dot Product 2
	template <std::floating_point T>
	constexpr float dot2(sf::Vector2<T> v1, sf::Vector2<T> v2) {
		return sfm::length(v1) * sfm::length(v2) * std::cosf(sfm::angle(v1, v2));
	}

	// Cross Product
}