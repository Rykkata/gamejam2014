#include "MoveableGraphicComponent.h"
#include "GameObject.h"
#include "World.h"

MoveableGraphicComponent::MoveableGraphicComponent(char* filePath) : GraphicComponent(filePath)
{

}


MoveableGraphicComponent::~MoveableGraphicComponent()
{
}

int MoveableGraphicComponent::Update(GameObject* gameObject, World* world)
{
	m_sprite->setPosition(gameObject->x, gameObject->y);
	m_sprite->setScale(1.0 + gameObject->scaleCount * SCALE, 1.0 + gameObject->scaleCount * SCALE);
	gameObject->boundingBox.left   =  gameObject->x     = m_sprite->getPosition().x;
	gameObject->boundingBox.top    =  gameObject->y     = m_sprite->getPosition().y;
	gameObject->boundingBox.width  = gameObject->width  = m_sprite->getGlobalBounds().width;
	gameObject->boundingBox.height = gameObject->height = m_sprite->getGlobalBounds().height;
	// Draw the sprite
	world->renderWindow->draw(*m_sprite);

	return 0;
}