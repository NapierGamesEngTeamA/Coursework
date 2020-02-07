#include "PlayerMovementComponent.h"
#include <SFML/Graphics.hpp>

PlayerMovementComponent::PlayerMovementComponent(Entity *p)
	: ActorMovementComponent(p) { }

void PlayerMovementComponent::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Move(Vector2f(0, -_speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Move(Vector2f(0, _speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Move(Vector2f(_speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Move(Vector2f(-_speed * dt, 0));
	}
}