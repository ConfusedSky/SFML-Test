#include "stdafx.h"
#include "MouseFollower.h"
#include <math.h>
#include <iostream>
#include "VectorUtility.h"



MouseFollower::MouseFollower( float size, float speed ) : 
	follower(size), speed(speed), size(size), target(leadTarget)
{
	follower.setFillColor(sf::Color::Green);
}

void MouseFollower::ChangeTarget(sf::Vector2f &target)
{
	sf::Vector2f distance = target - position;
	double magnitude = sqrt(distance.x*distance.x + distance.y*distance.y);

	this->actualTarget.x = target.x - size;
	this->actualTarget.y = target.y - size;

	this->leadTarget = this->actualTarget + distance;

	this->target = leadTarget;
}

void MouseFollower::Update(double time)
{
	sf::Vector2f distance = target - position;
	double magnitude = sqrt (distance.x*distance.x + distance.y*distance.y);
	double scaledSpeed = speed;
/*
	if (magnitude < speed*time)
	{
		position = target;
		return;
	}

	velocity = VectorUtility::Scale(distance, speed/magnitude);
	position = position + VectorUtility::Scale(velocity, time);
*/

	if ( magnitude < 40 )
	{
		target = actualTarget;
		scaledSpeed = speed / 2;
	}

	position = VectorUtility::Lerp(position, target, speed*time);
}

void MouseFollower::Render(sf::RenderTarget &target)
{
	follower.setPosition(position);
	target.draw(follower);
}

MouseFollower::~MouseFollower()
{
}
