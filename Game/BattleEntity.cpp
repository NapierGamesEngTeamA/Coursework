#include "BattleEntity.h"
#include "ecm.h"

BattleEntity::BattleEntity() : Entity()
{
	_stats.insert(pair<string, int>("CurrHP", 10));
	_stats.insert(pair<string, int>("CurrMP", 0));
	_stats.insert(pair<string, int>("MaxHP", 10));
	_stats.insert(pair<string, int>("MaxMP", 0));
	_stats.insert(pair<string, int>("Str", 1));
	_stats.insert(pair<string, int>("Dex", 1));
	_stats.insert(pair<string, int>("Int", 1));
	_stats.insert(pair<string, int>("Con", 1));
}

void BattleEntity::Update(Time dt)
{
	Entity::Update(dt);
}

void BattleEntity::Render()
{
	Entity::Render();
}