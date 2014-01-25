#include "UI.h"


UI::UI(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent) : GameObject(eventComponent, graphicComponent, physicComponent)
{

}


UI::~UI()
{
}

int UI::Update(World* world)
{
	GameObject::Update(world);
	return 0;
}