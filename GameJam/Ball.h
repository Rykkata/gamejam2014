#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent);
	~Ball();
	virtual int Update(World* world);
};

