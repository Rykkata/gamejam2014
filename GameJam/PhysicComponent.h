#pragma once

class GameObject;
class World;
class PhysicComponent
{
public:
	PhysicComponent() {};
	~PhysicComponent() {};
	virtual int Update(GameObject* gameObeject, World* world) = 0;
};

