#include "BattleEntity.h"
#include "AnimatedSpriteComponent.h"

BattleEntity::BattleEntity() : Entity()
{
	currentState = IDLE;
	currentAnim = new Animation();

	stats.insert(pair<string, int>("CurrHP", 10));
	stats.insert(pair<string, int>("CurrMP", 10));
	stats.insert(pair<string, int>("MaxHP", 10));
	stats.insert(pair<string, int>("MaxMP", 10));
	stats.insert(pair<string, int>("Str", 1));
	stats.insert(pair<string, int>("Dex", 1));
	stats.insert(pair<string, int>("Int", 1));
	stats.insert(pair<string, int>("Con", 1));
}

void BattleEntity::Update(Time dt)
{
	switch (currentState)
	{
	case BattleEntity::IDLE:
		currentAnim = &_anims["Idle"];
		break;
	case BattleEntity::ATTACK:
		currentAnim = &_anims["Attack"];
		break;
	case BattleEntity::DEATH:
		currentAnim = &_anims["Death"];
		break;
	}

	GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
	GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
	GetComponents<AnimatedSpriteComponent>()[0]->IsLooped();

	Entity::Update(dt);
}

void BattleEntity::Render()
{
	Entity::Render();
}