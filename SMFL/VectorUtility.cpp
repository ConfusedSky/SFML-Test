#include "stdafx.h"
#include "VectorUtility.h"

sf::Vector2f VectorUtility::Scale(sf::Vector2f vector, float value)
{
	return sf::Vector2f(vector.x*value, vector.y*value);
}
