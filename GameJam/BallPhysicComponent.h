#pragma once
#include "PhysicComponent.h"
class BallPhysicComponent :
	public PhysicComponent
{
public:
	BallPhysicComponent();
	~BallPhysicComponent();
	virtual int Update(GameObject* gameObeject, World* world);
};

