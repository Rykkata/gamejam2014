#include "World.h"
#include "GameObject.h"
#include "Player.h"
#include "AI.h"
#include <iostream>
World::World() : m_gameObjects()
{
	renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Pong");
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
}

void World::DrawObjects(void)
{
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