#include "PlayerEventComponent.h"
#include "Xbox360.h"
#include "GameObject.h"


PlayerEventComponent::PlayerEventComponent()
{
}


PlayerEventComponent::~PlayerEventComponent()
{
}

int PlayerEventComponent::Update(GameObject* gameObject)
{
	if (xb360::LeftThumbUp() || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		gameObject->y_velocity = VELOCITY_UP;
	else if (xb360::LeftThumbDown() || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		gameObject->y_velocity = VELOCITY_DOWN;
	else
		gameObject->y_velocity = 0;

	return 0;
}