#include "stdafx.h"
#include "LerpMoveTo.h"

LerpMoveTo::LerpMoveTo(float speed) : speed(speed)
{
}

void LerpMoveTo::MoveTo(GameObject& object, sf::Vector2f destination, double time)
{
	object.SetPosition(VectorUtility::Lerp(object.GetPosition(), destination, time*speed));
}
