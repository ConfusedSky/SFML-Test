#include "stdafx.h"
#include "MouseFollower.h"
#include <math.h>
#include <iostream>

float lerp(float p1, float p2, float distance)
{
	return (1 - distance) * p1 + distance * p2;
}

sf::Vector2f lerp(sf::Vector2f p1, sf::Vector2f p2, float distance)
{
	return sf::Vector2f(lerp(p1.x, p2.x, distance), lerp(p1.y, p2.y, distance));
}

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
	sf::Vector2f distance = target - follower.getPosition();
	double magnitude = sqrt (distance.x*distance.x + distance.y*distance.y);

	if (magnitude < maxSpeed*time)
	{
		follower.setPosition(target);
		return;
	}

	double scale = maxSpeed / magnitude;
	distance.x *= scale * time;
	distance.y *= scale * time;
	follower.setPosition (follower.getPosition() + distance);
}

void MouseFollower::Render(sf::RenderTarget &target)
{
	target.draw(follower);
}

MouseFollower::~MouseFollower()
{
}
