#include "Character.h"

using namespace sf;
using namespace std;

void Character::Update(double dt)
{
	Entity::Update(dt);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		SetPosition(Vector2f(GetPosition().x, GetPosition().y + 10));
	}

}

void Character::Render()
{
	Entity::Render();
}