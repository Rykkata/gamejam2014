#include "EventComponent.h"
#include "GraphicComponent.h"
#include "PhysicComponent.h"
#pragma once

enum MODIFY_WORLD { PADDLE_SIZE, PADDLE_SPEED, BALL_SIZE, BALL_SPEED, THOMAS_TANK_BREATH_FIRE };
enum ACTIVATE {OFF, ON};
enum UI_MESSAGE {LEFT, RIGHT, UP, DOWN, NONE};

class World;
class GameObject
{
public:
	GameObject(EventComponent* eventComponent, GraphicComponent* graphicComponent, PhysicComponent* physicComponent);
	~GameObject();
	virtual int Update(World* world);
	virtual int Draw(World* world);
	int x_velocity, y_velocity;				// Current Velocity
	float x, y;								// The position of the object
	int width, height;						// The width and heigh of the object
	char* tag;
	sf::Rect<float> boundingBox;
	static ACTIVATE activateModifier;
	static MODIFY_WORLD attribute;
	static float ballY;
	static UI_MESSAGE message;
	int scaleCount;
private:
	EventComponent* m_eventComponent;
	GraphicComponent* m_graphicComponent;
	PhysicComponent* m_physicComponent;
};

