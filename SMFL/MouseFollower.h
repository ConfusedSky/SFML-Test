#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "IMoveTo.h"

class MouseFollower : GameObject
{
public:
	MouseFollower( float size, IMoveTo* locomotion );

	void ChangeTarget(sf::Vector2f &target);
	void Update(float time);
	void Render(sf::RenderTarget &target);

	~MouseFollower();

private:
	sf::Vector2f target;
	sf::CircleShape sprite;
	IMoveTo* locomotion;
	float size;
};

