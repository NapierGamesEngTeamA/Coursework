#include "BattleEntity.h"
#include "AnimatedSpriteComponent.h"
#include <string>

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
	stats.insert(pair<string, int>("Exp", 0));
	stats.insert(pair<string, int>("Level", 1));
}

void BattleEntity::Update(Time dt)
{
	switch (currentState)
	{
	case BattleEntity::IDLE:
		currentAnim = &_anims["Idle"];
		GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
		GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		GetComponents<AnimatedSpriteComponent>()[0]->IsLooped();
		break;
	case BattleEntity::ATTACK:
		currentAnim = &_anims["Attack"];
		GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
		GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		break;
	case BattleEntity::DEATH:
		currentAnim = &_anims["Death"];
		GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
		GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		break;
	}

	

	Entity::Update(dt);
}

void BattleEntity::Render()
{
	Entity::Render();
}

void BattleEntity::Setup(vector<int> st, string na)
{
	name = na;
	stats["Str"] = st[0];
	stats["Dex"] = st[1];
	stats["Int"] = st[2];
	stats["Con"] = st[3];

	stats["MaxHP"] = st[4];
	stats["MaxMP"] = st[5];
	stats["CurrHP"] = stats["MaxHP"];
	stats["CurrMP"] = stats["MaxMP"];

	stats["Level"] = 1;
}

int BattleEntity::GetStat(string s)
{
	int i = stats[s];

	return i;
}

string BattleEntity::GetName()
{
	return name;
}

void BattleEntity::SetName(string s)
{
	name = s;
}

int BattleEntity::PhAttack()
{
	int i = 1 + (stats["Str"] * 1.5f);

	return i;
}

int BattleEntity::MgAttack()
{
	int i = 5 + (stats["Int"] * 1.5f);

	return i;
}

void BattleEntity::GiveExp(int i)
{
	stats["Exp"] += i;

	if (stats["Exp"] >= stats["Level"] * 100)
	{
		Levelup();
	}
}

void BattleEntity::Levelup()
{
	stats["Str"] += rand() % 3;
	stats["Dex"] += rand() % 2;
	stats["Int"] += rand() % 3;
	stats["Con"] += rand() % 3;
	stats["MaxHP"] += rand() % 5 + 1;
	stats["MaxMP"] += rand() % 3 + 1;
	stats["CurrHP"] = stats["MaxHP"];
	stats["CurrMP"] = stats["MaxMP"];
	stats["Exp"] -= stats["Level"] * 100;
	stats["Level"] += 1;
}

string BattleEntity::GetHealthText()
{
	string s = name + "  HP " + to_string(stats["CurrHP"]) + "/" + to_string(stats["MaxHP"]) + "  MP " + to_string(stats["CurrMP"]) + "/" + to_string(stats["MaxMP"]);

	return s;
}