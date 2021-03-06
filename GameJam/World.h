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
	void DrawBackground(void);
	GameObject* FindObjectWithTag(char* tag);
	void ResetObjects(bool didPlayerScore);
	sf::RenderWindow* renderWindow;
	sf::Time deltaTime;
	bool canChangeGame;
	int playerOneScore, playerTwoScore;
	void ResetModifers(void);
private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundImage;
	std::vector<GameObject*> m_gameObjects;
};

