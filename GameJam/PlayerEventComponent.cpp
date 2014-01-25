#include "PlayerEventComponent.h"
#include "Xbox360.h"
#include "GameObject.h"

#define VELOCITY_UP -300
#define VELOCITY_DOWN 300

PlayerEventComponent::PlayerEventComponent()
{
}


PlayerEventComponent::~PlayerEventComponent()
{
}

int PlayerEventComponent::Update(GameObject* gameObject)
{
	if (xb360::LeftThumbUp())
		gameObject->y_velocity = VELOCITY_UP;
	else if (xb360::LeftThumbDown())
		gameObject->y_velocity = VELOCITY_DOWN;
	else
		gameObject->y_velocity = 0;

	return 0;
}