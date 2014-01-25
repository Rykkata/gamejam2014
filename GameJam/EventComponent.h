#pragma once

#include <SFML/Graphics.hpp>

#define VELOCITY_UP -300
#define VELOCITY_DOWN 300


class GameObject;

class EventComponent 
{
public:
	EventComponent() {};
	~EventComponent() {};
	virtual int Update(GameObject* gameObeject) = 0;
private:
};

