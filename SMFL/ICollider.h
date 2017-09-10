#pragma once

class ICollider
{
public:
	virtual ~ICollider() {};
	virtual bool CollidedWith(ICollider &other) = 0;
};