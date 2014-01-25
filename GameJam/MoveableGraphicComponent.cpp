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

	// Draw the sprite
	world->renderWindow->draw(*m_sprite);

	return 0;
}