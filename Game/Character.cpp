#include "Character.h"
#include "AnimatedSpriteComponent.h"
#include "InputManager.h"

using namespace sf;
using namespace std;

void Character::Update(Time dt)
{
	bottom = GetPosition().y + 51;
	left = GetPosition().x;
	right = GetPosition().x + 30;
	top = GetPosition().y;


	//Vector2i topLeft(Vector2i((int)left / 32, (int)top / 32));
	//Vector2i topRight(Vector2i((int)right / 32, (int)top / 32));
	//Vector2i BottomLeft(Vector2i((int)left / 32, (int)bottom / 32));
	//Vector2i BottomRight(Vector2i((int)right / 32, (int)bottom / 32));

	//tiles.clear();

	//tiles.push_back(topLeft);

	//if (find(tiles.begin(), tiles.end(), topRight) == tiles.end()) tiles.push_back(topRight);
	//if (find(tiles.begin(), tiles.end(), BottomLeft) == tiles.end()) tiles.push_back(BottomLeft);
	//if (find(tiles.begin(), tiles.end(), BottomRight) == tiles.end()) tiles.push_back(BottomRight);

	if (InputManager::GetInstance()->Up())
	{
		tileY += 1;
		currentState = WALK_UP;
	}
	else if (InputManager::GetInstance()->Down())
	{
		tileY -= 1;
		currentState = WALK_DOWN;
	}
	else if (InputManager::GetInstance()->Right())
	{
		tileX += 1;
		currentState = WALK_RIGHT;
	}
	else if (InputManager::GetInstance()->Left())
	{
		tileX -= 1;
		currentState = WALK_LEFT;
	}

	switch (currentState)
	{
	case Character::STAND_UP:
		currentAnim = &_anims["Stand Up"];
		break;
	case Character::STAND_DOWN:
		currentAnim = &_anims["Stand Down"];
		break;
	case Character::STAND_LEFT:
		currentAnim = &_anims["Stand Left"];
		break;
	case Character::STAND_RIGHT:
		currentAnim = &_anims["Stand Right"];
		break;
	case Character::WALK_UP:
		currentAnim = &_anims["Walk Up"];
		break;
	case Character::WALK_DOWN:
		currentAnim = &_anims["Walk Down"];
		break;
	case Character::WALK_RIGHT:
		currentAnim = &_anims["Walk Right"];
		break;
	case Character::WALK_LEFT:
		currentAnim = &_anims["Walk Left"];
		break;
	}

	GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
	GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
	GetComponents<AnimatedSpriteComponent>()[0]->IsLooped();

	Entity::Update(dt);
}

void Character::Render()
{
	Entity::Render();
}