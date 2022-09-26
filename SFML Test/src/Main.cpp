#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML\Graphics.hpp>

#include "physics\Entity.h"
#include "physics\Circle.h"

namespace Utils {
	sf::Color clrFloatArr(float colors[3]) {
		return sf::Color(
			(int)(colors[0] * 255),
			(int)(colors[1] * 255),
			(int)(colors[2] * 255)
		);
	}

	void showEntityConfig(const char* name, Circle &circleEntity) {
		ImGui::Begin(name);
		//ImGui::Checkbox(("Draw %s",name), &circleDrawn);
		//ImGui::SliderFloat("Radius", &circleRadius, 0, 250);
		//ImGui::ColorEdit3("Color", circleColor);
		if (ImGui::Button("Reset Position")) {
			circleEntity.setPosition(sf::Vector2f(200.0f, 200.0f));
		}
		ImGui::Text("Position: %.0f %.0f", circleEntity.getPosition().x, circleEntity.getPosition().y);
		ImGui::Text("Velocity: %.3f %.3f", circleEntity.getVelocity().x, circleEntity.getVelocity().y);
		ImGui::Text("Acceleration: %.3f %.3f", circleEntity.getAcceleration().x, circleEntity.getAcceleration().y);
		ImGui::End();
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1520, 900), "Test");
	ImGui::SFML::Init(window);

	window.setFramerateLimit(144);
	sf::Event event;

	sf::Vector2f circlePos(300.0f, 300.0f);
	bool circleDrawn = true;
	float circleRadius = 100.0f;
	float circleColor[3] = { 1.0f, 1.0f, 1.0f };
	sf::CircleShape circle(circleRadius);
	circle.setPosition(circlePos);
	circle.setFillColor(Utils::clrFloatArr(circleColor));
	circle.setOrigin(circleRadius, circleRadius);

	Circle circleEntity(sf::Vector2f(200.0f, 200.0f), 25.0f);

	sf::Clock deltaClock;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) window.close();
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}

		sf::Time deltaTime = deltaClock.restart();
		ImGui::SFML::Update(window, deltaTime);
		
		/*
		ImGui::Begin("Config Circle");
		ImGui::Checkbox("draw circle", &circleDrawn);
		ImGui::SliderFloat("radius", &circleRadius, 0, 250);
		ImGui::ColorEdit3("color", circleColor);
		if (ImGui::Button("Reset")) {
			circleEntity.setPosition(sf::Vector2f(200.0f, 200.0f));
		}
		ImGui::Text("Position: %.0f %.0f", circleEntity.getPosition().x, circleEntity.getPosition().y);
		ImGui::Text("Velocity: %.3f %.3f", circleEntity.getVelocity().x, circleEntity.getVelocity().y);
		ImGui::Text("Acceleration: %.3f %.3f", circleEntity.getAcceleration().x, circleEntity.getAcceleration().y);
		ImGui::End();

		ImGui::Begin("Stats");
		ImGui::Text("FPS: %.0f", 1000.0f/deltaTime.asMilliseconds());
		ImGui::End();
		*/

		Utils::showEntityConfig("circle1", circleEntity);

		circle.setRadius(circleRadius);
		circle.setOrigin(circleRadius, circleRadius);
		circle.setFillColor(Utils::clrFloatArr(circleColor));

		circleEntity.updateMovement(deltaTime.asMilliseconds());

		circle.setPosition(circleEntity.getPosition());

		// Render
		window.clear();

		if(circleDrawn) window.draw(circle);

		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}