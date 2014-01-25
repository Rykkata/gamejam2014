#include "Ball.h"
#include "World.h"

Ball::Ball(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent) : GameObject(eventComponent, graphicComponent, physicComponent)
{
}


Ball::~Ball()
{
}

int Ball::Update(World* world)
{
	GameObject::Update(world);
	return 0;
}
