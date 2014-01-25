#pragma once

#include <SFML/Graphics.hpp>

#define VELOCITY_UP -200
#define VELOCITY_DOWN 200


class GameObject;

class EventComponent 
{
public:
	EventComponent() {};
	~EventComponent() {};
	virtual int Update(GameObject* gameObeject) = 0;
private:
};

