#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class IMoveTo
{
public:
	virtual ~IMoveTo(){};
	virtual void MoveTo(GameObject& object, sf::Vector2f destination, double time) = 0;
};