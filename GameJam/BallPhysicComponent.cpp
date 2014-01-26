#include "BallPhysicComponent.h"
#include "GameObject.h"
#include "World.h"
#include <cstdlib>
#include <cmath>

#define MAX_Y_VEL 500
#define MAX 4
#define MODIFER 40
#define Y_MODIFER 115

#define BALL_X 200

BallPhysicComponent::BallPhysicComponent()
{
	count = 0;
}


BallPhysicComponent::~BallPhysicComponent()
{
}

int BallPhysicComponent::Update(GameObject* gameObject, World* world)
{
	if (GameObject::activateModifier == ON && GameObject::attribute == BALL_SPEED)
	{
		if (GameObject::message == UP && count < MAX)
		{
			++count;
			int newVelocity = BALL_X;
			newVelocity += count * MODIFER;

			if (gameObject->x_velocity > 0)
				gameObject->x_velocity = newVelocity;
			else
				gameObject->x_velocity = -newVelocity;
		}
			
		else if (GameObject::message == DOWN && count > -MAX)
		{
			--count;
			int newVelocity = BALL_X;
			newVelocity += count * MODIFER;

			if (gameObject->x_velocity > 0)
				gameObject->x_velocity = newVelocity;
			else
				gameObject->x_velocity = -newVelocity;
		}
	}
	else if (GameObject::activateModifier == ON && GameObject::attribute == BALL_SIZE)
	{
		if (GameObject::message == UP && gameObject->scaleCount < MAX)
			++gameObject->scaleCount;
		else if (GameObject::message == DOWN && gameObject->scaleCount > -MAX)
			--gameObject->scaleCount;
	}

	float newX = gameObject->x + gameObject->x_velocity * world->deltaTime.asSeconds();
	float newY = gameObject->y + gameObject->y_velocity * world->deltaTime.asSeconds();

	if (world->CanMoveTo(newX, newY, gameObject->width, gameObject->height))
	{
		gameObject->x = newX;
		gameObject->y = newY;
		GameObject::ballY = newY;
		gameObject->boundingBox.left = gameObject->x;
		gameObject->boundingBox.top = gameObject->y;
	}
	else if (newX <= 0)								   // Player Scored
	{
		++world->playerTwoScore;
		world->ResetObjects(true);

		return 0;
	}
	else if (newX + gameObject->width >= world->renderWindow->getSize().x) // AI Scored
	{
		++world->playerOneScore;
		world->ResetObjects(false);
		
		return 0;
	}
	else  											   // Hit the top or bottom of the screenof the screen
	{
		gameObject->x = newX;
		gameObject->y_velocity = -gameObject->y_velocity;
		gameObject->boundingBox.left = gameObject->x;
	}

	if (world->CollisionDetection(gameObject, "Player"))
	{
		gameObject->x_velocity = -gameObject->x_velocity;
		GameObject* player = world->FindObjectWithTag("Player");
		GameObject::activateModifier = OFF;
		if (player->y_velocity != 0)
			gameObject->y_velocity += player->y_velocity;
		else
			gameObject->y_velocity += rand() % 51 - 25;
	}

	if (world->CollisionDetection(gameObject, "AI"))
	{
		gameObject->x_velocity = -gameObject->x_velocity;
		GameObject* AI = world->FindObjectWithTag("AI");
		GameObject::activateModifier = ON;
		if (AI->y_velocity != 0)
			gameObject->y_velocity += AI->y_velocity;
		else
			gameObject->y_velocity += rand() % 51 - 25;
	}

	if (gameObject->y_velocity < -MAX_Y_VEL + -count * Y_MODIFER)
		gameObject->y_velocity = -MAX_Y_VEL - count * Y_MODIFER;

	if (gameObject->y_velocity > MAX_Y_VEL + count * Y_MODIFER)
		gameObject->y_velocity = MAX_Y_VEL + count * Y_MODIFER;

	return 0;
}