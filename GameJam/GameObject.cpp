#include "GameObject.h"


GameObject::GameObject(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent) : x(0), y(0), boundingBox()
{
	m_eventComponent = eventComponent;
	m_graphicComponent = graphicComponent;
	m_physicComponent = physicComponent;

	width  = m_graphicComponent->width;
	height = m_graphicComponent->height;

	boundingBox.left = x;
	boundingBox.top = y;
	boundingBox.width = (float)width;
	boundingBox.height = (float)height;
}


GameObject::~GameObject()
{
	delete m_eventComponent;
	delete m_graphicComponent;
	delete m_physicComponent;
}

int GameObject::Update(World* world)
{
	m_eventComponent->Update(this);
	m_physicComponent->Update(this, world);
	m_graphicComponent->Update(this, world);

	return 0;
}

int GameObject::Draw(World* world)
{
	m_graphicComponent->Update(this, world);

	return 0;
}
