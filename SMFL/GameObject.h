#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(double time) = 0;
	virtual void Render(sf::RenderTarget &target) = 0;

protected:
	Vector2f position, velocity;
};

