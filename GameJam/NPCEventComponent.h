#pragma once
#include "EventComponent.h"
class NPCEventComponent :
	public EventComponent
{
public:
	NPCEventComponent();
	~NPCEventComponent();
	virtual int Update(GameObject* gameObeject);
};

