#include "World.h"
#include "GameObject.h"
#include "Player.h"
#include "AI.h"
#include <iostream>

#define BACKGROUND_PATH "Images/background.jpg"

// The player constants
#define PLAYER_X 720
#define PLAYER_Y 280

// The AI constants
#define AI_X 60
#define AI_Y 280

// The ball constants
#define BALL_X 395
#define BALL_Y 295
#define BALL_X_VEL 200
#define BALL_Y_VEL 50

World::World() : m_gameObjects()
{
	canChangeGame = true;
	renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Candy Saga: The Crushing Scrolls");

	if (!m_backgroundTexture.loadFromFile(BACKGROUND_PATH))
		std::cout << "Error loading background" << std::endl;

	m_backgroundImage.setTexture(m_backgroundTexture);
}


World::~World()
{
	m_gameObjects.clear();
	delete renderWindow;
}

void World::AddObject(GameObject* object)
{
	m_gameObjects.push_back(object);
}

void World::UpdateObjects(void)
{
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->Update(this);

	if (FindObjectWithTag("Ball") != NULL && FindObjectWithTag("Ball")->x_velocity < 0)
	{
		canChangeGame = false;
		GameObject::activateModifier = OFF;
	}	
	else
	{
		canChangeGame = true;
		GameObject::activateModifier = ON;
	}
		
}

void World::DrawBackground(void)
{
	renderWindow->draw(m_backgroundImage);
}

void World::DrawObjects(void)
{
	DrawBackground();
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->Draw(this);
}

bool World::CanMoveTo(float x, float y, int width, int height)
{
	if (x < 0 || y < 0 || x + width > renderWindow->getSize().x || y + height > renderWindow->getSize().y)
		return false;

	return true;
}

// TODO: Convert to a vector so we can detect against all possible objects
GameObject* World::FindObjectWithTag(char* tag)
{
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
		if (m_gameObjects[i]->tag == tag)
			return m_gameObjects[i];

	return NULL;
}

// TODO: Make more efficient than O(n)
// TODO: Convert to for loop and use a vector
bool World::CollisionDetection(GameObject* object, char* tag)
{
	GameObject* objectToTest = FindObjectWithTag(tag);
	if (!objectToTest)
		return false;

	return object->boundingBox.intersects(objectToTest->boundingBox);
}

void World::ResetObjects(bool didPlayerScore)
{
	// Reset the player
	GameObject* player = FindObjectWithTag("Player");
	player->x = PLAYER_X;
	player->y = PLAYER_Y;
	player->x_velocity = player->y_velocity = 0;

	// Reset the AI
	GameObject* ai = FindObjectWithTag("AI");
	ai->x = AI_X;
	ai->y = AI_Y;
	ai->x_velocity = ai->y_velocity = 0;
	GameObject* ball = FindObjectWithTag("Ball");
	ball->x = BALL_X;
	ball->y = BALL_Y;
	ball->y_velocity = BALL_Y_VEL;

	if (didPlayerScore)
	{
		ball->x_velocity = -BALL_X_VEL;
		canChangeGame = true;
		GameObject::activateModifier = ON;
	}	
	else
	{
		ball->x_velocity = BALL_X_VEL;
		canChangeGame = false;
		GameObject::activateModifier = OFF;
	}

	GameObject::ballY = BALL_Y;
}

void World::ResetModifers(void)
{
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->scaleCount = 0;
		m_gameObjects[i]->count = 0;
	}

	GameObject::attribute = PADDLE_SIZE;
	GameObject::message = NONE;
	GameObject::activateModifier = ON;
}