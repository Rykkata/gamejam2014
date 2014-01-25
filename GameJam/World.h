#pragma once
#include <vector>
#include <SFML\Graphics.hpp>



class GameObject;

class World
{
public:
	World();
	~World();
	void AddObject(GameObject* object);
	void UpdateObjects(void);
	void DrawObjects(void);
	bool CollisionDetection(GameObject* object, char* tag);
	bool CanMoveTo(float x, float y, int width, int height);
	GameObject* FindObjectWithTag(char* tag);
	sf::RenderWindow* renderWindow;
	sf::Time deltaTime;
private:

	std::vector<GameObject*> m_gameObjects;
};

