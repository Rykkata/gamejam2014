#include "AIEventComponent.h"
#include "GameObject.h"

#define MODIFIER 50
#define MAX 4

#define SIZE_SCALE 0.2
AIEventComponent::AIEventComponent()
{
}


AIEventComponent::~AIEventComponent()
{
}

int AIEventComponent::Update(GameObject* gameObject)
{
	if (GameObject::activateModifier == ON && GameObject::attribute == PADDLE_SPEED)
	{
		if (GameObject::message == UP && gameObject->count < MAX)
			--gameObject->count;
		else if (GameObject::message == DOWN && gameObject->count > -MAX)
			++gameObject->count;
	}
	else if (GameObject::activateModifier == ON && GameObject::attribute == PADDLE_SIZE)
	{
		if (GameObject::message == UP && gameObject->scaleCount < MAX)
			++gameObject->scaleCount;
		else if (GameObject::message == DOWN && gameObject->scaleCount > -MAX)
			--gameObject->scaleCount;
	}
	
	if (GameObject::activateModifier == OFF && GameObject::ballY > ((gameObject->y + (gameObject->y + gameObject->height)) / 2))
		gameObject->y_velocity = VELOCITY_DOWN + (MODIFIER * -gameObject->count);
	if (GameObject::activateModifier == OFF && GameObject::ballY < ((gameObject->y + (gameObject->y + gameObject->height)) / 2))
		gameObject->y_velocity = VELOCITY_UP + (MODIFIER * gameObject->count);

	if (GameObject::activateModifier == ON)
		gameObject->y_velocity = 0;

	return 0;
}