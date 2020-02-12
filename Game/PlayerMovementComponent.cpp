#include "PlayerMovementComponent.h"
#include <SFML/Graphics.hpp>

PlayerMovementComponent::PlayerMovementComponent(Entity *p)
	: ActorMovementComponent(p) { }

void PlayerMovementComponent::Update(Time dt)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Move(Vector2f(0, -_speed * dt.asSeconds()));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Move(Vector2f(0, _speed * dt.asSeconds()));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Move(Vector2f(_speed * dt.asSeconds(), 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Move(Vector2f(-_speed * dt.asSeconds(), 0));
	}
}