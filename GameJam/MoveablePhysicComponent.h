#pragma once
#include "PhysicComponent.h"
class MoveablePhysicComponent :
	public PhysicComponent
{
public:
	MoveablePhysicComponent();
	~MoveablePhysicComponent();
	virtual int Update(GameObject* gameObeject, World* world);
};

