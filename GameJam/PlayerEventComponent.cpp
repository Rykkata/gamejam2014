#include "PlayerEventComponent.h"
#include "Xbox360.h"
#include "GameObject.h"

#define MAX 4
#define MODIFER 50

PlayerEventComponent::PlayerEventComponent()
{
}


PlayerEventComponent::~PlayerEventComponent()
{
}

int PlayerEventComponent::Update(GameObject* gameObject)
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

	if (xb360::LeftThumbUp() || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		gameObject->y_velocity = VELOCITY_UP + MODIFER * gameObject->count;
	else if (xb360::LeftThumbDown() || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		gameObject->y_velocity = VELOCITY_DOWN + MODIFER * -gameObject->count;
	else
		gameObject->y_velocity = 0;

	return 0;
}