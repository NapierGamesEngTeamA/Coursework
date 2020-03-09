#include "BattleParty.h"
#include "Andrel.h"
#include "Charity.h"
#include "Helmaer.h"
#include "Horo.h"
#include "Goblin.h"
#include "SpriteComponent.h"
#include "ecm.h"
#include <SFML/Graphics.hpp>

using namespace sf;

BattleParty::BattleParty() : Entity()
{

}

void BattleParty::AddPartyMember(BattleEntity b)
{
	Party.push_back(b);
}

void BattleParty::SetupPlayer(Texture* texture)
{
	

	Andrel* a = new Andrel();
	auto sp = a->AddComponent<SpriteComponent>();
	sp->SetTexture(*texture);
	sp->SetRect(IntRect(31, 36, 30, 33));
	a->SetPosition(Vector2f(200, 200));
	AddPartyMember(*a);

	Charity* c = new Charity();
	auto sp1 = c->AddComponent<SpriteComponent>();
	sp1->SetTexture(*texture);
	sp1->SetRect(IntRect(31, 36, 30, 33));
	c->SetPosition(Vector2f(200, 300));
	AddPartyMember(*c);

	Helmaer* he = new Helmaer();
	auto sp2 = he->AddComponent<SpriteComponent>();
	sp2->SetTexture(*texture);
	sp2->SetRect(IntRect(31, 36, 30, 33));
	he->SetPosition(Vector2f(200, 400));
	AddPartyMember(*he);

	Horo* ho = new Horo();
	auto sp3 = ho->AddComponent<SpriteComponent>();
	sp3->SetTexture(*texture);
	sp3->SetRect(IntRect(31, 36, 30, 33));
	ho->SetPosition(Vector2f(200, 500));
	AddPartyMember(*ho);
}

void BattleParty::SetupEnemy()
{
	Goblin* g = new Goblin();
	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/TstSprt.png");
	auto sp1 = g->AddComponent<SpriteComponent>();
	sp1->SetTexture(*texture);
	sp1->SetRect(IntRect(31, 36, 30, 33));
	g->SetPosition(Vector2f(1800, 500));
	AddPartyMember(*g);
}

void BattleParty::Update(Time dt)
{
	for (int i = 0; i < Party.size(); i++)
	{
		Party[i].Update(dt);
	}
	Entity::Update(dt);
}

void BattleParty::Render()
{
	for (int i = 0; i < Party.size(); i++)
	{
		Party[i].Render();
	}

	Entity::Render();
}
