#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "IMoveTo.h"
#include "LerpMoveTo.h"

class MouseFollower : GameObject
{
public:
	MouseFollower( float size, float speed );

	void ChangeTarget(sf::Vector2f &target);
	void Update(double time);
	void Render(sf::RenderTarget &target);

	~MouseFollower();

private:
	sf::Vector2f target;
	sf::CircleShape sprite;
	LerpMoveTo locomotion;
	float size;
};

