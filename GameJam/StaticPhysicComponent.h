#pragma once
#include "PhysicComponent.h"
class StaticPhysicComponent :
	public PhysicComponent
{
public:
	StaticPhysicComponent();
	~StaticPhysicComponent();
	virtual int Update(GameObject* gameObeject, World* world);
};

