#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent);
	~Player();
	virtual int Update(World* world);
private:
};

