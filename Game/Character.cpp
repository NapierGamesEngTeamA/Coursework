#include "Character.h"

using namespace sf;
using namespace std;

void Character::Update(double dt)
{
	Entity::Update(dt);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		SetPosition(_position + Vector2f(0, -10));
		printf("Moved!");
	}

}

void Character::Render()
{
	Entity::Render();
}