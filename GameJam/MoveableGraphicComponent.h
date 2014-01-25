#pragma once
#include "GraphicComponent.h"
class MoveableGraphicComponent :
	public GraphicComponent
{
public:
	MoveableGraphicComponent(char* filePath);
	~MoveableGraphicComponent();
	virtual int Update(GameObject* gameObject, World* world);
};

