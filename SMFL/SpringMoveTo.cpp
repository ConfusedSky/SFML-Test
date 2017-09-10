#include "stdafx.h"
#include "SpringMoveTo.h"


SpringMoveTo::SpringMoveTo(float constant, float damping) : constant(constant), damping(damping)
{
}

void SpringMoveTo::MoveTo(GameObject & object, sf::Vector2f destination, double time)
{
	sf::Vector2f springForce = constant * (destination - object.GetPosition());
	sf::Vector2f dampingForce = -damping * object.GetVelocity();

	sf::Vector2f totalAcceleration = (springForce + dampingForce) * (float)time;
	object.SetVelocity(object.GetVelocity() + totalAcceleration);
	object.SetPosition(object.GetPosition() + object.GetVelocity()*(float)time);
}
