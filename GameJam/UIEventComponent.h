#pragma once
#include "EventComponent.h"
class UIEventComponent :
	public EventComponent
{
public:
	UIEventComponent();
	~UIEventComponent();
	virtual int Update(GameObject* gameObeject);
};

