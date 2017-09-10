#pragma once

#include "IMoveTo.h"
#include "VectorUtility.h"

class LerpMoveTo : IMoveTo
{
public:
	LerpMoveTo(float speed);
	virtual ~LerpMoveTo() {};
	virtual void MoveTo(GameObject& object, sf::Vector2f destination, double time);
private:
	float speed;
};