#include "GraphicComponent.h"
#include "GameObject.h"

GraphicComponent::GraphicComponent(char* filePath)
{
	// Create the texture
	m_texture = new sf::Texture();

	m_texture->loadFromFile(filePath);

	width  = m_texture->getSize().x;
	height = m_texture->getSize().y;
	//Create the sprite
	m_sprite = new sf::Sprite(*m_texture);
}

GraphicComponent::~GraphicComponent()
{
	delete m_sprite;
	delete m_texture;
}

