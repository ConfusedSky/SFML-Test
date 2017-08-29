#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(double time);
	virtual void Render(sf::RenderTarget &target) = 0;

private:
	Vector2f position, velocity;
};

