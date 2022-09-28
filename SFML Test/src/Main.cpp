#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML\Graphics.hpp>

#include "physics\Entity.h"
#include "physics\Circle.h"
#include "Utils.h"


//int a = 10
//int* r = &a		r is the pointer to a
//int& s = a		s is reference to a
//int a = *r;		a is the dereferenced pointer to a
//void m(int& a) {} takes in a reference to a


void showEntityConfig(const char* name, Entity &entity) {
	ImGui::Begin(name);
	if (ImGui::Button("Reset Position")) {
		entity.setPosition(sf::Vector2f(800.0f, 200.0f));
	}
	if (ImGui::Button("Reset Velocity")) {
		entity.setVelocity(sf::Vector2f(0.0f, 0.0f));
	}
	if (ImGui::Button("Reset Acceleration")) {
		entity.setAcceleration(sf::Vector2f(0.0f, 0.0f));
	}
	ImGui::SliderFloat("Acceleration", &entity.acceleration.x, -0.5f, 0.5f);
	ImGui::Text("Position: %.0f %.0f", entity.getPosition().x, entity.getPosition().y);
	ImGui::Text("Velocity: %.3f %.3f", entity.getVelocity().x, entity.getVelocity().y);
	ImGui::Text("Acceleration: %.3f %.3f", entity.getAcceleration().x, entity.getAcceleration().y);
	ImGui::End();
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1520, 900), "Test");
	ImGui::SFML::Init(window);

	window.setFramerateLimit(144);
	sf::Event event;

	//Circle circleEntity(sf::Vector2f(200.0f, 200.0f), sf::Color::Blue, 25.0f);
	Circle circleEntity(sf::Vector2f(200.0f, 200.0f), sf::Color(155,240,50), 50.0f);

	sf::Clock deltaClock;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) window.close();
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}

		sf::Time deltaTime = deltaClock.restart();
		ImGui::SFML::Update(window, deltaTime);
		
		ImGui::Begin("Stats");
		ImGui::Text("FPS: %.0f", 1000.0f/deltaTime.asMilliseconds());
		ImGui::End();

		showEntityConfig("circle1", circleEntity);
		circleEntity.update(deltaTime.asMilliseconds());

		// Render

		window.clear();

		circleEntity.draw(window);

		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}