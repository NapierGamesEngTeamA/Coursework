#include "PlayerMovementComponent.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"

PlayerMovementComponent::PlayerMovementComponent(Entity *p)
	: ActorMovementComponent(p) { }

void PlayerMovementComponent::Update(Time dt)
{
	if (InputManager::GetInstance()->Up())
	{
		Move(Vector2f(0, -_speed * dt.asSeconds()));
	}
	else if (InputManager::GetInstance()->Down())
	{
		Move(Vector2f(0, _speed * dt.asSeconds()));
	}
	else if (InputManager::GetInstance()->Right())
	{
		Move(Vector2f(_speed * dt.asSeconds(), 0));
	}
	else if (InputManager::GetInstance()->Left())
	{
		Move(Vector2f(-_speed * dt.asSeconds(), 0));
	}

}