#pragma once

#include <numbers>
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

	// Length Squared
	template <std::floating_point T>
	constexpr T lengthSqr(sf::Vector2<T> v) {
		return (v.x * v.x + v.y * v.y);
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


	// Rotate
	template <std::floating_point T>
	constexpr sf::Vector2f rotate(sf::Vector2<T> v, sf::Vector2<T> o, float ang) {
		sf::Vector2f t = v - o;

		float cos = (float)std::cos(ang * std::numbers::pi / 180);
		float sin = (float)std::sin(ang * std::numbers::pi / 180);

		sf::Vector2f r( (t.x * cos - t.y * sin), (t.x * sin + t.y * cos) );

		return o + r;
	}
	
	// Compare floating point numbers
	bool compare(float x, float y, float epsilon) {
		return std::fabs(x - y) < epsilon;
	}

	// Compare Vector2f
	template <std::floating_point T>
	bool compare(sf::Vector2<T> v1, sf::Vector2<T> v2, float epsilon) {
		//std::cout << std::fabs(v1.x - v2.x) << " & " << std::fabs(v1.y - v2.y) << " w. " << epsilon << std::endl;
		return std::fabs(v1.x - v2.x) < epsilon && std::fabs(v1.y - v2.y) < epsilon;
	}
}