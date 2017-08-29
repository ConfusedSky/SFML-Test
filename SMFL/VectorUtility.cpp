#include "stdafx.h"
#include "VectorUtility.h"

sf::Vector2f VectorUtility::Scale(sf::Vector2f vector, float value)
{
	return sf::Vector2f(vector.x*value, vector.y*value);
}

float VectorUtility::lerp(float p1, float p2, float distance)
{
	return (1 - distance) * p1 + distance * p2;
}

sf::Vector2f VectorUtility::lerp(sf::Vector2f p1, sf::Vector2f p2, float distance)
{
	return sf::Vector2f(lerp(p1.x, p2.x, distance), lerp(p1.y, p2.y, distance));
}
