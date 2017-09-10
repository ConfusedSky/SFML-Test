#pragma once

#include "IMoveTo.h"
#include "VectorUtility.h"

class LerpMoveTo : public IMoveTo
{
public:
	LerpMoveTo(float speed);
	virtual ~LerpMoveTo() {};
	virtual void MoveTo(GameObject& object, sf::Vector2f destination, float time);
private:
	float speed;
};