#pragma once

#include <SFML/Graphics.hpp>

class GameObject;

class EventComponent 
{
public:
	EventComponent() {};
	~EventComponent() {};
	virtual int Update(GameObject* gameObeject) = 0;
private:
};

