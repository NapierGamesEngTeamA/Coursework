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
		if (currentAnim != &_anims["Idle"])
		{
			currentAnim = &_anims["Idle"];
			GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
			GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
			GetComponents<AnimatedSpriteComponent>()[0]->SetLooped(true);
		}
		break;
	case BattleEntity::ATTACK:
		if (currentAnim != &_anims["Attack"])
		{
			currentAnim = &_anims["Attack"];
			GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
			GetComponents<AnimatedSpriteComponent>()[0]->SetFrame(0);
			GetComponents<AnimatedSpriteComponent>()[0]->SetLooped(false);
			GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		}
		if (!GetComponents<AnimatedSpriteComponent>()[0]->IsPlaying())
		{
			currentState = BattleEntity::IDLE;
		}
		
		break;
	case BattleEntity::MAGIC:
		if (currentAnim != &_anims["Magic"])
		{
			currentAnim = &_anims["Magic"];
			GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
			GetComponents<AnimatedSpriteComponent>()[0]->SetFrame(0);
			GetComponents<AnimatedSpriteComponent>()[0]->SetLooped(false);
			GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		}
		if (!GetComponents<AnimatedSpriteComponent>()[0]->IsPlaying())
		{
			currentState = BattleEntity::IDLE;
		}
		break;
	case BattleEntity::DEATH:
		if (currentAnim != &_anims["Death"])
		{
			currentAnim = &_anims["Death"];
			GetComponents<AnimatedSpriteComponent>()[0]->SetAnimation(*currentAnim);
			GetComponents<AnimatedSpriteComponent>()[0]->SetFrame(0);
			GetComponents<AnimatedSpriteComponent>()[0]->SetLooped(false);
			GetComponents<AnimatedSpriteComponent>()[0]->Play(*currentAnim);
		}
		if (!GetComponents<AnimatedSpriteComponent>()[0]->IsPlaying())
		{
			GetComponents<AnimatedSpriteComponent>()[0]->SetFrame(5);
		}
		if (stats["CurrHP"] > 0)
		{
			currentState = BattleEntity::IDLE;
		}
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

void BattleEntity::SetupEnemy(int level)
{
	stats["Level"] = level;
	stats["Str"] += level;
	stats["Dex"] += level;
	stats["Int"] += level;
	stats["Con"] += level;

	stats["MaxHP"] += (level * 2);
	stats["MaxMP"] += (level * 2);
	stats["CurrHP"] = stats["MaxHP"];
	stats["CurrMP"] = stats["MaxMP"];
}

int BattleEntity::GetStat(string s)
{
	int i = stats[s];

	return i;
}

void BattleEntity::SetStat(string s, int i)
{
	stats[s] = i;
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
	int i = 1 + (stats["Str"]);

	return i;
}

int BattleEntity::MgAttack()
{
	int i = 3 + (stats["Int"]);

	return i;
}

void BattleEntity::GiveExp(int i)
{
	stats["Exp"] += i;

	if (stats["Exp"] >= stats["Level"] * 5)
	{
		Levelup();
	}
}

void BattleEntity::Levelup()
{
	hasLeveled = true;
	stats["Str"] += rand() % 5 + 2;
	stats["Dex"] += rand() % 3 + 1;
	stats["Int"] += rand() % 5 + 2;
	stats["Con"] += rand() % 3 + 1;
	stats["MaxHP"] += rand() % 10 + 2;
	stats["MaxMP"] += rand() % 6 + 2;
	stats["CurrHP"] = stats["MaxHP"];
	stats["CurrMP"] = stats["MaxMP"];
	stats["Exp"] = 0;
	stats["Level"] += 1;
}

string BattleEntity::GetHealthText()
{
	string s = name + "  HP " + to_string(stats["CurrHP"]) + "/" + to_string(stats["MaxHP"]) + "  MP " + to_string(stats["CurrMP"]) + "/" + to_string(stats["MaxMP"]);

	return s;
}

vector<int> BattleEntity::GetStatList()
{
	vector<int> i;
	i.push_back(stats["Str"]);
	i.push_back(stats["Dex"]);
	i.push_back(stats["Int"]);
	i.push_back(stats["Con"]);
	i.push_back(stats["MaxHP"]);
	i.push_back(stats["MaxMP"]);
	i.push_back(stats["CurrHP"]);
	i.push_back(stats["CurrMP"]);

	return i;
}

string BattleEntity::GetSaveString()
{
	string s;
	s += name + ",";
	for each (pair<string, int> i in stats)
	{
		s += to_string(i.second) + ",";
	}
	return s;
}