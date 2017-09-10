#include "stdafx.h"
#include "MouseFollower.h"
#include <math.h>
#include <iostream>
#include "VectorUtility.h"


MouseFollower::MouseFollower(float size, IMoveTo* locomotion) : 
	sprite(size), size(size), locomotion(locomotion)
{
	sprite.setFillColor(sf::Color::Green);
}

void MouseFollower::ChangeTarget(sf::Vector2f &target)
{
	this->target.x = target.x - size;
	this->target.y = target.y - size;
}

void MouseFollower::Update(double time)
{
	locomotion->MoveTo(*this, target, time);
}

void MouseFollower::Render(sf::RenderTarget &target)
{
	sprite.setPosition(GetPosition());
	target.draw(sprite);
}

MouseFollower::~MouseFollower()
{
}
