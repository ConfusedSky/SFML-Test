#pragma once
#include "IMoveTo.h"
#include "VectorUtility.h"

class SpringMoveTo : public IMoveTo
{
public:
	SpringMoveTo(float constant, float damping);
	virtual ~SpringMoveTo() {};
	virtual void MoveTo(GameObject& object, sf::Vector2f destination, double time);
private:
	float constant;
	float damping;
};