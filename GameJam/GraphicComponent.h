#pragma once
#include <SFML/Graphics.hpp>

class GameObject;
class World;
class GraphicComponent 
{
public:
	GraphicComponent(char* filePath);
	~GraphicComponent();
	virtual int Update(GameObject* gameObject, World* world) = 0;
	int width, height;
protected:
	sf::Sprite* m_sprite;
	sf::Texture* m_texture;
};

