#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>
class MouseFollower
{
public:
	MouseFollower( float size, float speed );

	void ChangeTarget(sf::Vector2f &target);
	void Update(double time);
	void Render(sf::RenderTarget &target);

	~MouseFollower();

private:
	sf::Vector2f target;
	sf::CircleShape follower;
	float maxSpeed;
	float size;
};

