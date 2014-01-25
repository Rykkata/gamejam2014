#include "AIEventComponent.h"
#include "GameObject.h"

AIEventComponent::AIEventComponent()
{
}


AIEventComponent::~AIEventComponent()
{
}

int AIEventComponent::Update(GameObject* gameObject)
{
	if (GameObject::activateModifier == OFF && GameObject::ballY > gameObject->y)
		gameObject->y_velocity = VELOCITY_DOWN;
	if (GameObject::activateModifier == OFF && GameObject::ballY < gameObject->y)
		gameObject->y_velocity = VELOCITY_UP;

	if (GameObject::activateModifier == ON)
		gameObject->y_velocity = 0;

	return 0;
}