#pragma once
#include "GraphicComponent.h"
class UIGraphicComponent :
	public GraphicComponent
{
public:
	UIGraphicComponent();
	~UIGraphicComponent();
	virtual int Update(GameObject* gameObject, World* world);
};

