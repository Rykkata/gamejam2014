#include "BallPhysicComponent.h"
#include "GameObject.h"
#include "World.h"

BallPhysicComponent::BallPhysicComponent()
{
}


BallPhysicComponent::~BallPhysicComponent()
{
}

int BallPhysicComponent::Update(GameObject* gameObject, World* world)
{
	float newX = gameObject->x + gameObject->x_velocity * world->deltaTime.asSeconds();
	float newY = gameObject->y + gameObject->y_velocity * world->deltaTime.asSeconds();

	if (world->CanMoveTo(newX, newY, gameObject->width, gameObject->height))
	{
		gameObject->x = newX;
		gameObject->y = newY;

		gameObject->boundingBox.left = gameObject->x;
		gameObject->boundingBox.top = gameObject->y;
	}
	else if (newX <= 0)								   // Player Scored
	{
		gameObject->y = newY;
		gameObject->x_velocity = -gameObject->x_velocity;
		gameObject->boundingBox.top = gameObject->y;
	}
	else if (newX + gameObject->width >= world->renderWindow->getSize().x) // AI Scored
	{
		gameObject->y = newY;
		gameObject->x_velocity = -gameObject->x_velocity;
		gameObject->boundingBox.top = gameObject->y;
	}
	else  											   // Hit the top or bottom of the screenof the screen
	{
		gameObject->x = newX;
		gameObject->y_velocity = -gameObject->y_velocity;
		gameObject->boundingBox.left = gameObject->x;
	}

	if (world->CollisionDetection(gameObject, "Player") || world->CollisionDetection(gameObject, "AI"))
	{
		gameObject->x_velocity = -gameObject->x_velocity;
	}


	return 0;
}