#pragma once
#include <SFML/System.hpp>

static class VectorUtility
{
public:
	static sf::Vector2f Scale(sf::Vector2f vector, float value);
	static float lerp(float p1, float p2, float distance);
	static sf::Vector2f lerp(sf::Vector2f p1, sf::Vector2f p2, float distance);
};

