#pragma once
#include "EventComponent.h"

class PlayerEventComponent :
	public EventComponent
{
public:
	PlayerEventComponent();
	~PlayerEventComponent();
	virtual int Update(GameObject* gameObeject);
};

