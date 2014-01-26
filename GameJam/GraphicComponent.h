#pragma once
#include <SFML/Graphics.hpp>

#define SCALE 0.2f

class GameObject;
class World;
class GraphicComponent 
{
public:
	GraphicComponent();
	GraphicComponent(char* filePath);
	~GraphicComponent();
	virtual int Update(GameObject* gameObject, World* world) = 0;
	int width, height;
protected:
	sf::Sprite* m_sprite;
	sf::Texture* m_texture;
};

