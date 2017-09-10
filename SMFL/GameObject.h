#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float time) = 0;
	virtual void Render(sf::RenderTarget &target) = 0;

	Vector2f GetPosition()
	{
		return position;
	};

	void SetPosition(Vector2f position)
	{
		this->position = position;
	};

	Vector2f GetVelocity()
	{
		return velocity;
	};

	void SetVelocity(Vector2f velocity)
	{
		this->velocity = velocity;
	};

private:
	Vector2f position, velocity;
};

