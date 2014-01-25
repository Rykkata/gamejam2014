#pragma once
#include "EventComponent.h"
class AIEventComponent :
	public EventComponent
{
public:
	AIEventComponent();
	~AIEventComponent();
	virtual int Update(GameObject* gameObeject);
};

