#include "AI.h"


AI::AI(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent) : GameObject(eventComponent, graphicComponent, physicComponent)
{

}


AI::~AI()
{

}

int AI::Update(World* world)
{
	GameObject::Update(world);

	return 0;
}
