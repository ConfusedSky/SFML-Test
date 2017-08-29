#include "stdafx.h"
#include "GameObject.h"
#include "VectorUtility.h"


GameObject::GameObject() : position(0,0), velocity(0,0)
{
}


GameObject::~GameObject()
{
}

void GameObject::Update(double time)
{
	position += VectorUtility::Scale( velocity, time );
}
