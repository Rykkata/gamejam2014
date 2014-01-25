#pragma once
#include "GameObject.h"
class UI :
	public GameObject
{
public:
	UI(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent);
	~UI();
	virtual int Update(World* world);
};

