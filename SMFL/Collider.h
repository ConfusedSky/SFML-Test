#pragma once

class Collider
{
public:
	virtual ~Collider() {};
	virtual bool CollidedWith(Collider &other) = 0;
};