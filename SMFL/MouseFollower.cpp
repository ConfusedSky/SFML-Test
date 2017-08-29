#include "stdafx.h"
#include "MouseFollower.h"
#include <math.h>
#include <iostream>
#include "VectorUtility.h"



MouseFollower::MouseFollower( float size, float speed ) : follower(size), maxSpeed(speed), size(size)
{
	follower.setFillColor(sf::Color::Green);
}

void MouseFollower::ChangeTarget(sf::Vector2f &target)
{
	this->target.x = target.x - size;
	this->target.y = target.y - size;
}

void MouseFollower::Update(double time)
{
	sf::Vector2f distance = target - position;
	double magnitude = sqrt (distance.x*distance.x + distance.y*distance.y);

	if (magnitude < maxSpeed*time)
	{
		position = target;
		return;
	}

	double scale = maxSpeed / magnitude;
	position = position + VectorUtility::Scale(distance, scale*time);
}

void MouseFollower::Render(sf::RenderTarget &target)
{
	follower.setPosition(position);
	target.draw(follower);
}

MouseFollower::~MouseFollower()
{
}
