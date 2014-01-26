#include "UIEventComponent.h"
#include "Xbox360.h"
#include "GameObject.h"
UIEventComponent::UIEventComponent() : EventComponent()
{
}


UIEventComponent::~UIEventComponent()
{
}

int UIEventComponent::Update(GameObject* object)
{
	// PADDLE_SIZE, PADDLE_SPEED, BALL_SPEED, BALL_SIZE
	if (GameObject::message == RIGHT || xb360::DPadRight())
	{
		if (GameObject::attribute == PADDLE_SIZE)
			GameObject::attribute = PADDLE_SPEED;
		else if (GameObject::attribute == PADDLE_SPEED)
			GameObject::attribute = BALL_SIZE;
		else if (GameObject::attribute == BALL_SIZE)
			GameObject::attribute = BALL_SPEED;
		else
			GameObject::attribute = PADDLE_SIZE;
	}
	else if(GameObject::message == LEFT || xb360::DPadLeft())
	{
		if (GameObject::attribute == PADDLE_SIZE)
			GameObject::attribute = BALL_SPEED;
		else if (GameObject::attribute == PADDLE_SPEED)
			GameObject::attribute = PADDLE_SIZE;
		else if (GameObject::attribute == BALL_SIZE)
			GameObject::attribute = PADDLE_SPEED;
		else
			GameObject::attribute = BALL_SIZE;
	}
	else if (GameObject::message == UP || xb360::DPadUp())
	{

	}
	else if (GameObject::message == DOWN || xb360::DPadDown())
	{

	}

	return 0;
}
