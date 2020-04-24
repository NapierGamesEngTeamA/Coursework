#include "BattleManager.h"
#include "AnimatedSpriteComponent.h"
#include "SystemRenderer.h"
#include "InputManager.h"
#include "Game.h"
#include "AudioManager.h"

using namespace std;
using namespace sf;

BattleManager::BattleManager()
{

}

void BattleManager::Load()
{
	#pragma region Party

	Texture* texture1[4];
	texture1[0] = new Texture();
	texture1[0]->loadFromFile("Res/Sprites/Andrel.png");
	texture1[1] = new Texture();
	texture1[1]->loadFromFile("Res/Sprites/Charity.png");
	texture1[2] = new Texture();
	texture1[2]->loadFromFile("Res/Sprites/Helmaer.png");
	texture1[3] = new Texture();
	texture1[3]->loadFromFile("Res/Sprites/Horo.png");

	vector<int> stats[4];
	stats[0].push_back(4); //Strength
	stats[0].push_back(3); //Dexterity
	stats[0].push_back(1); //Intellect
	stats[0].push_back(3); //Constitution
	stats[0].push_back(10); //Health
	stats[0].push_back(0); //MP

	stats[1].push_back(1);
	stats[1].push_back(2);
	stats[1].push_back(3);
	stats[1].push_back(3);
	stats[1].push_back(10);
	stats[1].push_back(15);

	stats[2].push_back(4);
	stats[2].push_back(1);
	stats[2].push_back(1);
	stats[2].push_back(4);
	stats[2].push_back(20);
	stats[2].push_back(0);

	stats[3].push_back(1);
	stats[3].push_back(2);
	stats[3].push_back(4);
	stats[3].push_back(3);
	stats[3].push_back(10);
	stats[3].push_back(20);

#pragma region Andrel
	auto andrel = make_shared<BattleEntity>();
	andrel->Setup(stats[0], "Andrel");
	andrel->type = BattleEntity::Type::Player;

	Animation* idle = new Animation();
	idle->SetSpriteSheet(*texture1[0]);
	idle->AddFrame(IntRect(21, 205, 21, 48));
	idle->AddFrame(IntRect(84, 205, 21, 48));
	Animation* attack = new Animation();
	attack->SetSpriteSheet(*texture1[0]);
	attack->AddFrame(IntRect(85, 1997, 75, 48));
	attack->AddFrame(IntRect(278, 1999, 75, 48));
	attack->AddFrame(IntRect(468, 1997, 75, 48));
	attack->AddFrame(IntRect(659, 1997, 75, 48));
	attack->AddFrame(IntRect(852, 1997, 75, 48));
	attack->AddFrame(IntRect(1044, 1997, 75, 48));
	Animation* magic = new Animation();
	magic->SetSpriteSheet(*texture1[0]);
	magic->AddFrame(IntRect(20, 973, 35, 48));
	magic->AddFrame(IntRect(85, 975, 35, 48));
	magic->AddFrame(IntRect(149, 974, 35, 48));
	magic->AddFrame(IntRect(212, 974, 35, 48));
	magic->AddFrame(IntRect(276, 973, 52, 48));
	magic->AddFrame(IntRect(340, 973, 53, 48));
	Animation* death = new Animation();
	death->SetSpriteSheet(*texture1[0]);
	death->AddFrame(IntRect(17, 1292, 29, 48));
	death->AddFrame(IntRect(82, 1292, 29, 48));
	death->AddFrame(IntRect(147, 1292, 29, 48));
	death->AddFrame(IntRect(211, 1292, 29, 48));
	death->AddFrame(IntRect(275, 1292, 29, 48));
	death->AddFrame(IntRect(338, 1292, 29, 48));
	andrel->_anims.insert(pair<string, Animation>("Idle", *idle));
	andrel->_anims.insert(pair<string, Animation>("Attack", *attack));
	andrel->_anims.insert(pair<string, Animation>("Magic", *magic));
	andrel->_anims.insert(pair<string, Animation>("Death", *death));

	auto a = andrel->AddComponent<AnimatedSpriteComponent>();
	a->SetAnimation(*idle);
	a->Play();

	andrel->SetPosition(Vector2f(600, 500));
	players.push_back(andrel);
#pragma endregion

#pragma region Charity
	//Charity
	auto charity = make_shared<BattleEntity>();
	charity->Setup(stats[1], "Charity");
	charity->type = BattleEntity::Type::Player;

	Animation* idle1 = new Animation();
	idle1->SetSpriteSheet(*texture1[1]);
	idle1->AddFrame(IntRect(21, 205, 21, 48));
	idle1->AddFrame(IntRect(84, 205, 21, 48));
	Animation* attack1 = new Animation();
	attack1->SetSpriteSheet(*texture1[1]);
	attack1->AddFrame(IntRect(19, 1228, 34, 48));
	attack1->AddFrame(IntRect(83, 1228, 34, 48));
	attack1->AddFrame(IntRect(145, 1228, 34, 48));
	attack1->AddFrame(IntRect(208, 1228, 34, 48));
	attack1->AddFrame(IntRect(272, 1228, 34, 48));
	Animation* magic1 = new Animation();
	magic1->SetSpriteSheet(*texture1[1]);
	magic1->AddFrame(IntRect(20, 973, 35, 48));
	magic1->AddFrame(IntRect(85, 975, 35, 48));
	magic1->AddFrame(IntRect(149, 974, 35, 48));
	magic1->AddFrame(IntRect(212, 974, 35, 48));
	magic1->AddFrame(IntRect(276, 973, 52, 48));
	magic1->AddFrame(IntRect(340, 973, 53, 48));
	Animation* death1 = new Animation();
	death1->SetSpriteSheet(*texture1[1]);
	death1->AddFrame(IntRect(17, 1292, 29, 48));
	death1->AddFrame(IntRect(82, 1292, 29, 48));
	death1->AddFrame(IntRect(147, 1292, 29, 48));
	death1->AddFrame(IntRect(211, 1292, 29, 48));
	death1->AddFrame(IntRect(275, 1292, 29, 48));
	death1->AddFrame(IntRect(338, 1292, 29, 48));
	charity->_anims.insert(pair<string, Animation>("Idle", *idle1));
	charity->_anims.insert(pair<string, Animation>("Attack", *attack1));
	charity->_anims.insert(pair<string, Animation>("Magic", *magic1));
	charity->_anims.insert(pair<string, Animation>("Death", *death1));

	auto b = charity->AddComponent<AnimatedSpriteComponent>();
	b->SetAnimation(*idle1);
	b->Play();

	charity->SetPosition(Vector2f(600, 600));
	players.push_back(charity);
#pragma endregion

#pragma region Helmaer
	//Helmaer
	auto helmaer = make_shared<BattleEntity>();
	helmaer->Setup(stats[2], "Helmaer");
	helmaer->type = BattleEntity::Type::Player;

	Animation* idle2 = new Animation();
	idle2->SetSpriteSheet(*texture1[2]);
	idle2->AddFrame(IntRect(21, 205, 21, 48));
	idle2->AddFrame(IntRect(84, 205, 21, 48));
	Animation* attack2 = new Animation();
	attack2->SetSpriteSheet(*texture1[2]);
	attack2->AddFrame(IntRect(85, 1997, 75, 48));
	attack2->AddFrame(IntRect(278, 1999, 75, 48));
	attack2->AddFrame(IntRect(468, 1997, 75, 48));
	attack2->AddFrame(IntRect(659, 1997, 75, 48));
	attack2->AddFrame(IntRect(852, 1997, 75, 48));
	attack2->AddFrame(IntRect(1044, 1997, 75, 48));
	Animation* magic2 = new Animation();
	magic2->SetSpriteSheet(*texture1[2]);
	magic2->AddFrame(IntRect(20, 973, 35, 48));
	magic2->AddFrame(IntRect(85, 975, 35, 48));
	magic2->AddFrame(IntRect(149, 974, 35, 48));
	magic2->AddFrame(IntRect(212, 974, 35, 48));
	magic2->AddFrame(IntRect(276, 973, 52, 48));
	magic2->AddFrame(IntRect(340, 973, 53, 48));
	Animation* death2 = new Animation();
	death2->SetSpriteSheet(*texture1[2]);
	death2->AddFrame(IntRect(17, 1292, 29, 48));
	death2->AddFrame(IntRect(82, 1292, 29, 48));
	death2->AddFrame(IntRect(147, 1292, 29, 48));
	death2->AddFrame(IntRect(211, 1292, 29, 48));
	death2->AddFrame(IntRect(275, 1292, 29, 48));
	death2->AddFrame(IntRect(338, 1292, 29, 48));
	helmaer->_anims.insert(pair<string, Animation>("Idle", *idle2));
	helmaer->_anims.insert(pair<string, Animation>("Attack", *attack2));
	helmaer->_anims.insert(pair<string, Animation>("Magic", *magic2));
	helmaer->_anims.insert(pair<string, Animation>("Death", *death2));

	auto c = helmaer->AddComponent<AnimatedSpriteComponent>();
	c->SetAnimation(*idle2);
	c->Play();

	helmaer->SetPosition(Vector2f(600, 700));
	players.push_back(helmaer);
#pragma endregion

#pragma region Horo
	//Horo
	auto horo = make_shared<BattleEntity>();
	horo->Setup(stats[3], "Horo");
	horo->type = BattleEntity::Type::Player;

	Animation* idle3 = new Animation();
	idle3->SetSpriteSheet(*texture1[3]);
	idle3->AddFrame(IntRect(21, 205, 21, 48));
	idle3->AddFrame(IntRect(84, 205, 21, 48));
	Animation* attack3 = new Animation();
	attack3->SetSpriteSheet(*texture1[3]);
	attack3->AddFrame(IntRect(19, 1228, 34, 48));
	attack3->AddFrame(IntRect(83, 1228, 34, 48));
	attack3->AddFrame(IntRect(145, 1228, 34, 48));
	attack3->AddFrame(IntRect(208, 1228, 34, 48));
	attack3->AddFrame(IntRect(272, 1228, 34, 48));
	Animation* magic3 = new Animation();
	magic3->SetSpriteSheet(*texture1[3]);
	magic3->AddFrame(IntRect(10, 458, 50, 48));
	magic3->AddFrame(IntRect(68, 458, 52, 48));
	magic3->AddFrame(IntRect(132, 458, 53, 48));
	magic3->AddFrame(IntRect(193, 458, 53, 48));
	magic3->AddFrame(IntRect(263, 458, 53, 48));
	magic3->AddFrame(IntRect(330, 458, 53, 48));
	magic3->AddFrame(IntRect(391, 458, 53, 48));
	magic3->AddFrame(IntRect(449, 458, 53, 48));
	Animation* death3 = new Animation();
	death3->SetSpriteSheet(*texture1[3]);
	death3->AddFrame(IntRect(17, 1292, 29, 48));
	death3->AddFrame(IntRect(82, 1292, 29, 48));
	death3->AddFrame(IntRect(147, 1292, 29, 48));
	death3->AddFrame(IntRect(211, 1292, 29, 48));
	death3->AddFrame(IntRect(275, 1292, 29, 48));
	death3->AddFrame(IntRect(338, 1292, 29, 48));
	horo->_anims.insert(pair<string, Animation>("Idle", *idle3));
	horo->_anims.insert(pair<string, Animation>("Attack", *attack3));
	horo->_anims.insert(pair<string, Animation>("Magic", *magic3));
	horo->_anims.insert(pair<string, Animation>("Death", *death3));

	auto d = horo->AddComponent<AnimatedSpriteComponent>();
	d->SetAnimation(*idle3);
	d->Play();

	horo->SetPosition(Vector2f(600, 800));
	players.push_back(horo);
#pragma endregion
#pragma endregion

	#pragma region Orc Party
	vector<int> orcStats;
	orcStats.push_back(2);
	orcStats.push_back(1); 
	orcStats.push_back(1);
	orcStats.push_back(1);
	orcStats.push_back(10); 
	orcStats.push_back(0);

	Texture* orcTexture = new Texture();
	orcTexture->loadFromFile("Res/Sprites/Orc.png");

	//Orc 1
	auto orc1 = make_shared<BattleEntity>();
	orc1->Setup(orcStats, "Orc");
	orc1->type = BattleEntity::Type::Enemy;
	Animation* idle0 = new Animation();
	idle0->SetSpriteSheet(*orcTexture);
	idle0->AddFrame(IntRect(22, 340, 24, 48));
	idle0->AddFrame(IntRect(83, 340, 24, 48));
	Animation* attack0 = new Animation();
	attack0->SetSpriteSheet(*orcTexture);
	attack0->AddFrame(IntRect(12, 852, 30, 48));
	attack0->AddFrame(IntRect(75, 852, 30, 48));
	attack0->AddFrame(IntRect(141, 852, 30, 48));
	attack0->AddFrame(IntRect(199, 852, 30, 48));
	attack0->AddFrame(IntRect(256, 852, 45, 48));
	attack0->AddFrame(IntRect(321, 852, 45, 48));
	Animation* magic0 = new Animation();
	magic0->SetSpriteSheet(*orcTexture);
	magic0->AddFrame(IntRect(12, 852, 30, 48));
	magic0->AddFrame(IntRect(75, 852, 30, 48));
	magic0->AddFrame(IntRect(141, 852, 30, 48));
	magic0->AddFrame(IntRect(199, 852, 30, 48));
	magic0->AddFrame(IntRect(256, 852, 45, 48));
	magic0->AddFrame(IntRect(321, 852, 45, 48));
	Animation* death0 = new Animation();
	death0->SetSpriteSheet(*orcTexture);
	death0->AddFrame(IntRect(17, 1292, 29, 48));
	death0->AddFrame(IntRect(82, 1292, 29, 48));
	death0->AddFrame(IntRect(147, 1292, 29, 48));
	death0->AddFrame(IntRect(211, 1292, 29, 48));
	death0->AddFrame(IntRect(275, 1292, 29, 48));
	death0->AddFrame(IntRect(338, 1292, 29, 48));

	orc1->_anims.insert(pair<string, Animation>("Idle", *idle0));
	orc1->_anims.insert(pair<string, Animation>("Attack", *attack0));
	orc1->_anims.insert(pair<string, Animation>("Magic", *magic0));
	orc1->_anims.insert(pair<string, Animation>("Death", *death0));
	auto c0 = orc1->AddComponent<AnimatedSpriteComponent>();
	c0->SetAnimation(*idle0);
	c0->Play();
	orc1->SetPosition(Vector2f(900, 500));

	orcs.push_back(orc1);

	//Orc 2
	auto orc2 = make_shared<BattleEntity>();
	orc2->Setup(orcStats, "Orc");
	orc2->type = BattleEntity::Type::Enemy;
	orc2->_anims.insert(pair<string, Animation>("Idle", *idle0));
	orc2->_anims.insert(pair<string, Animation>("Attack", *attack0));
	orc2->_anims.insert(pair<string, Animation>("Magic", *magic0));
	orc2->_anims.insert(pair<string, Animation>("Death", *death0));
	auto c1 = orc2->AddComponent<AnimatedSpriteComponent>();
	c1->SetAnimation(*idle0);
	c1->Play();
	orc2->SetPosition(Vector2f(900, 600));

	orcs.push_back(orc2);

	//Orc 3
	auto orc3 = make_shared<BattleEntity>();
	orc3->Setup(orcStats, "Orc");
	orc3->type = BattleEntity::Type::Enemy;
	orc3->_anims.insert(pair<string, Animation>("Idle", *idle0));
	orc3->_anims.insert(pair<string, Animation>("Attack", *attack0));
	orc3->_anims.insert(pair<string, Animation>("Magic", *magic0));
	orc3->_anims.insert(pair<string, Animation>("Death", *death0));
	auto c2 = orc3->AddComponent<AnimatedSpriteComponent>();
	c2->SetAnimation(*idle0);
	c2->Play();
	orc3->SetPosition(Vector2f(900, 700));

	orcs.push_back(orc3);

	//Orc 3
	auto orc4 = make_shared<BattleEntity>();
	orc4->Setup(orcStats, "Orc");
	orc4->type = BattleEntity::Type::Enemy;
	orc4->_anims.insert(pair<string, Animation>("Idle", *idle0));
	orc4->_anims.insert(pair<string, Animation>("Attack", *attack0));
	orc4->_anims.insert(pair<string, Animation>("Magic", *magic0));
	orc4->_anims.insert(pair<string, Animation>("Death", *death0));
	auto c3 = orc4->AddComponent<AnimatedSpriteComponent>();
	c3->SetAnimation(*idle0);
	c3->Play();
	orc4->SetPosition(Vector2f(900, 800));

	orcs.push_back(orc4);
#pragma endregion

	#pragma region Skeleton Party
	vector<int> skelStats;
	skelStats.push_back(1); //Strength
	skelStats.push_back(2); //Dexterity
	skelStats.push_back(2); //Intellect
	skelStats.push_back(1); //Constitution
	skelStats.push_back(10); //Health
	skelStats.push_back(10); //MP

	Texture* skelTexture = new Texture();
	skelTexture->loadFromFile("Res/Sprites/Skeleton.png");

	//Skeleton 1
	auto skel1 = make_shared<BattleEntity>();
	skel1->Setup(skelStats, "Skeleton");
	skel1->type = BattleEntity::Type::Enemy;
	Animation* idle5 = new Animation();
	idle5->SetSpriteSheet(*skelTexture);
	idle5->AddFrame(IntRect(22, 340, 24, 48));
	idle5->AddFrame(IntRect(83, 340, 24, 48));
	Animation* attack5 = new Animation();
	attack5->SetSpriteSheet(*skelTexture);
	attack5->AddFrame(IntRect(49, 1615, 79, 48));
	attack5->AddFrame(IntRect(226, 1615, 79, 48));
	attack5->AddFrame(IntRect(416, 1615, 79, 48));
	attack5->AddFrame(IntRect(611, 1615, 79, 48));
	attack5->AddFrame(IntRect(795, 1615, 79, 48));
	attack5->AddFrame(IntRect(985, 1615, 79, 48));
	attack5->AddFrame(IntRect(1181, 1615, 79, 48));
	attack5->AddFrame(IntRect(1379, 1615, 79, 48));
	Animation* magic5 = new Animation();
	magic5->SetSpriteSheet(*skelTexture);
	magic5->AddFrame(IntRect(17, 143, 32, 48));
	magic5->AddFrame(IntRect(81, 143, 32, 48));
	magic5->AddFrame(IntRect(147, 143, 32, 48));
	magic5->AddFrame(IntRect(206, 143, 32, 48));
	magic5->AddFrame(IntRect(258, 143, 60, 48));
	magic5->AddFrame(IntRect(328, 143, 60, 48));
	magic5->AddFrame(IntRect(393, 143, 32, 48));
	Animation* death5 = new Animation();
	death5->SetSpriteSheet(*skelTexture);
	death5->AddFrame(IntRect(17, 1292, 29, 48));
	death5->AddFrame(IntRect(82, 1292, 29, 48));
	death5->AddFrame(IntRect(147, 1292, 29, 48));
	death5->AddFrame(IntRect(211, 1292, 29, 48));
	death5->AddFrame(IntRect(275, 1292, 29, 48));
	death5->AddFrame(IntRect(338, 1292, 29, 48));
	skel1->_anims.insert(pair<string, Animation>("Idle", *idle5));
	skel1->_anims.insert(pair<string, Animation>("Attack", *attack5));
	skel1->_anims.insert(pair<string, Animation>("Magic", *magic5));
	skel1->_anims.insert(pair<string, Animation>("Death", *death5));
	auto c5 = skel1->AddComponent<AnimatedSpriteComponent>();
	c5->SetAnimation(*idle5);
	c5->Play();
	skel1->SetPosition(Vector2f(900, 500));

	skeletons.push_back(skel1);

	//Skeleton 2
	auto skel2 = make_shared<BattleEntity>();
	skel2->Setup(skelStats, "Skeleton");
	skel2->type = BattleEntity::Type::Enemy;
	skel2->_anims.insert(pair<string, Animation>("Idle", *idle5));
	skel2->_anims.insert(pair<string, Animation>("Attack", *attack5));
	skel2->_anims.insert(pair<string, Animation>("Magic", *magic5));
	skel2->_anims.insert(pair<string, Animation>("Death", *death5));
	auto c6 = skel2->AddComponent<AnimatedSpriteComponent>();
	c6->SetAnimation(*idle5);
	c6->Play();
	skel2->SetPosition(Vector2f(900, 600));

	skeletons.push_back(skel2);

	//Skeleton 3
	auto skel3 = make_shared<BattleEntity>();
	skel3->Setup(skelStats, "Skeleton");
	skel3->type = BattleEntity::Type::Enemy;
	skel3->_anims.insert(pair<string, Animation>("Idle", *idle5));
	skel3->_anims.insert(pair<string, Animation>("Attack", *attack5));
	skel3->_anims.insert(pair<string, Animation>("Magic", *magic5));
	skel3->_anims.insert(pair<string, Animation>("Death", *death5));
	auto c7 = skel3->AddComponent<AnimatedSpriteComponent>();
	c7->SetAnimation(*idle5);
	c7->Play();
	skel3->SetPosition(Vector2f(900, 700));

	skeletons.push_back(skel3);

	//Skeleton 4
	auto skel4 = make_shared<BattleEntity>();
	skel4->Setup(skelStats, "Skeleton");
	skel4->type = BattleEntity::Type::Enemy;
	skel4->_anims.insert(pair<string, Animation>("Idle", *idle5));
	skel4->_anims.insert(pair<string, Animation>("Attack", *attack5));
	skel4->_anims.insert(pair<string, Animation>("Magic", *magic5));
	skel4->_anims.insert(pair<string, Animation>("Death", *death5));
	auto c8 = skel4->AddComponent<AnimatedSpriteComponent>();
	c8->SetAnimation(*idle5);
	c8->Play();
	skel4->SetPosition(Vector2f(900, 800));

	skeletons.push_back(skel4);
#pragma endregion

	currentState = BattleStates::Start;
	currentAction = ActionTypes::None;

	slog = " ";
	font.loadFromFile("Res/Fonts/riskofrainfont.ttf");
	battleLog.setFont(font);
	battleLog.setColor(Color::White);
	battleLog.setCharacterSize(16);
	battleLog.setPosition(Vector2f(1600, 900));
	battleLog.setString(" ");

	party.push_back(players[0]);
	party.push_back(players[1]);
	party.push_back(players[2]);
	party.push_back(players[3]);

	indicator.setSize(Vector2f(20, 20));
	indicator.setFillColor(Color::White);
	indicator.setRotation(45.0f);
	indicator.setPosition(Vector2f(560, 500));
}

void BattleManager::Update(Time dt)
{
	for (auto s : battleEntities)
	{
		s->Update(dt);
	}

	switch (currentState)
	{
	case BattleManager::Start:
		StartBattle(0, 1);
		currentEntity = players[index];
		currentState = BattleStates::ChooseAction;
		break;
	case BattleManager::ChooseAction:
		if (currentEntity->type == BattleEntity::Player)
		{
			indicator.setPosition(Vector2f(currentEntity->GetPosition().x - 50, currentEntity->GetPosition().y));
		}
		else
		{
			indicator.setPosition(Vector2f(currentEntity->GetPosition().x + 80, currentEntity->GetPosition().y));
		}
		PickAction();
		break;
	case BattleManager::ChooseTarget:
		PickTarget();
		if (selectedTarget != -1)
		{
			currentState = BattleStates::Action;
		}
		break;
	case BattleManager::Action:
		switch (currentAction)
		{
		case ActionTypes::aAttack:
			Attack();
			break;
		case ActionTypes::aMagic:
			Magic();
			break;
		case ActionTypes::aFlee:
			Flee();
			break;
		}
		break;
	case BattleManager::NextTurn:
		ChangeTurn();
		break;
	case BattleManager::End:
		break;
	}
}

void BattleManager::StartBattle(int type, int level)
{
	switch (EnemyType)
	{
	case 0:
		enemies = orcs;
		break;
	case 1:
		enemies = skeletons;
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		players[i]->SetStat("CurrHP", party[i]->GetStat("CurrHP"));
		players[i]->SetStat("CurrMP", party[i]->GetStat("CurrMP"));
	}

	for each (shared_ptr<BattleEntity> i in players)
	{
		battleEntities.push_back(i);
	}

	for each (shared_ptr<BattleEntity> i in enemies)
	{
		i->SetupEnemy(EnemyLevel);
		battleEntities.push_back(i);
	}

	for each (shared_ptr<BattleEntity> i in battleEntities)
	{
		if (i->GetStat("CurrHP") > 0)
		{
			i->currentState = BattleEntity::IDLE;
		}
	}

	battleLog.setPosition(Vector2f(1600, 900));
	won = false;
}

void BattleManager::PickAction()
{
	if (currentEntity->type == BattleEntity::Type::Player)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			currentAction = ActionTypes::aAttack;
			currentState = BattleStates::ChooseTarget;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			currentAction = ActionTypes::aMagic;
			currentState = BattleStates::ChooseTarget;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			currentAction = ActionTypes::aFlee;
			currentState = BattleStates::Action;
		}
	}
	else
	{
		int i  = rand() % 2 + 1;

		if (i == 1)
		{
			currentAction = ActionTypes::aAttack;
		}
		else
		{
			currentAction = ActionTypes::aMagic;
		}
		currentState = BattleStates::ChooseTarget;
	}
}

void BattleManager::PickTarget()
{
	if (currentEntity->type == BattleEntity::Type::Player)
	{
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			selectedTarget = 4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			selectedTarget = 5;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			selectedTarget = 6;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
			AudioManager::GetInstance()->PlaySoundEffect("Click");
			selectedTarget = 7;
		}
	}
	else
	{
		selectedTarget = rand() % 4;
	}
}

void BattleManager::Attack()
{
	if (battleEntities[selectedTarget]->GetStat("CurrHP") > 0)
	{
		slog = " ";
		slog = currentEntity->GetName() + " is attacking " + battleEntities[selectedTarget]->GetName() + "\n";
		int damage = battleEntities[selectedTarget]->GetStat("Con") - currentEntity->PhAttack();
		if (damage < 1)
		{
			damage = 1;
		}
		battleEntities[selectedTarget]->SetStat("CurrHP",
			battleEntities[selectedTarget]->GetStat("CurrHP") -  damage);
		if (battleEntities[selectedTarget]->GetStat("CurrHP") <= 0)
		{
			battleEntities[selectedTarget]->SetStat("CurrHP", 0);
			battleEntities[selectedTarget]->currentState = BattleEntity::DEATH;
		}
		slog += currentEntity->GetName() + " dealt " + to_string(damage) + " damage to " + battleEntities[selectedTarget]->GetName() + "\n";
		battleLog.setString(slog);

		battleEntities[index]->currentState = BattleEntity::ATTACK;
		AudioManager::GetInstance()->PlaySoundEffect("Attack");

		currentState = BattleStates::NextTurn;

	}
	else
	{
		slog = "Enemy is already vanquished";
		battleLog.setString(slog);
		selectedTarget = -1;
		currentState = BattleStates::ChooseTarget;
	}
}

void BattleManager::Magic()
{
	if (battleEntities[selectedTarget]->GetStat("CurrHP") > 0 && currentEntity->GetStat("CurrMP") >= 5)
	{
		slog = " ";
		slog = currentEntity->GetName() + " is casting at " + battleEntities[selectedTarget]->GetName() + "\n";
		int damage = battleEntities[selectedTarget]->GetStat("Int") - currentEntity->MgAttack();
		if (damage < 3)
		{
			damage = 3;
		}
		battleEntities[selectedTarget]->SetStat("CurrHP",
			battleEntities[selectedTarget]->GetStat("CurrHP") - damage);
		if (battleEntities[selectedTarget]->GetStat("CurrHP") <= 0)
		{
			battleEntities[selectedTarget]->SetStat("CurrHP", 0);
			battleEntities[selectedTarget]->currentState = BattleEntity::DEATH;
		}
		slog += currentEntity->GetName() + " dealt " + to_string(damage) + " damage to " + battleEntities[selectedTarget]->GetName() + "\n";
		battleLog.setString(slog);
		battleEntities[index]->SetStat("CurrMP", currentEntity->GetStat("CurrMP") - 5);
		battleEntities[index]->currentState = BattleEntity::MAGIC;
		AudioManager::GetInstance()->PlaySoundEffect("Magic");
		currentState = BattleStates::NextTurn;
	}
	else if (battleEntities[selectedTarget]->GetStat("CurrHP") <= 0)
	{
		slog = "Enemy is already vanquished. Choose another.";
		battleLog.setString(slog);
		selectedTarget = -1;
		currentState = BattleStates::ChooseTarget;
	}
	else if (currentEntity->GetStat("CurrMP") < 5)
	{
		slog = "Not enough mana to cast magic.\nTry something else.";
		battleLog.setString(slog);
		selectedTarget = -1;
		currentAction = ActionTypes::None;
		currentState = BattleStates::ChooseAction;
	}
}

void BattleManager::Flee()
{
	int i = rand() % 100 + 1;

	if (i > 60)
	{
		Reset();
		AudioManager::GetInstance()->PlayOverworld();
		activeScene = overworldScene;
	}
	else
	{
		slog = "Party failed to flee\n";
		battleLog.setString(slog);
		currentState = BattleStates::NextTurn;
	}
}

void BattleManager::ChangeTurn()
{
	if (battleEntities[4]->GetStat("CurrHP") <= 0 && battleEntities[5]->GetStat("CurrHP") <= 0 &&
		battleEntities[6]->GetStat("CurrHP") <= 0 && battleEntities[7]->GetStat("CurrHP") <= 0)
	{
		Win();
	}
	else if (battleEntities[0]->GetStat("CurrHP") <= 0 && battleEntities[1]->GetStat("CurrHP") <= 0 &&
		battleEntities[2]->GetStat("CurrHP") <= 0 && battleEntities[3]->GetStat("CurrHP") <= 0)
	{
		Lose();
	
	}
	else
	{
		if (battleEntities[index]->currentState == BattleEntity::IDLE ||
			battleEntities[index]->currentState == BattleEntity::DEATH)
		{
			selectedTarget = -1;
			if (index < 7)
			{
				index++;
			}
			else
			{
				index = 0;
			}
			if (battleEntities[index]->GetStat("CurrHP") > 0)
			{
				currentEntity = battleEntities[index];
				currentAction = ActionTypes::None;
				currentState = BattleStates::ChooseAction;
			}
			else
			{
				ChangeTurn();
			}
		}
	}
}

void BattleManager::Reset()
{
	battleEntities.clear();
	enemies.clear();
	currentState = BattleStates::Start;
	currentAction = ActionTypes::None;
	selectedTarget = -1;
	index = 0;
	turn = 0;
	slog = " ";
	battleLog.setString(slog);
	HasHealed = false;
	for (int i = 0; i < 4; i++)
	{
		orcs[i]->SetStat("CurrHP", orcs[i]->GetStat("MaxHP"));
		skeletons[i]->SetStat("CurrHP", skeletons[i]->GetStat("MaxHP"));
	}
}

void BattleManager::Render()
{
	for (auto s : battleEntities)
	{
		s->Render();
	}
	Renderer::Queue(&indicator);
	Renderer::Queue(&battleLog);
}

vector<shared_ptr<BattleEntity>> BattleManager::GetEnts()
{
	return players;
}

void BattleManager::Win()
{
	if (won == false)
	{
		AudioManager::GetInstance()->PlayVictory();

		slog = " ";
		battleLog.setPosition(Vector2f(1600, 700));
		if (battleEntities[0]->GetStat("CurrHP") > 0)
		{
			int i = 2 * ((battleEntities[4]->GetStat("Level") + 1) * 4);
			players[0]->GiveExp(i);
			players[0]->SetStat("CurrHP", battleEntities[0]->GetStat("CurrHP"));
			slog += players[0]->GetName() + " gained " + to_string(i) + " experience\n";
		}
		if (battleEntities[1]->GetStat("CurrHP") > 0)
		{
			int i = 2 * ((battleEntities[4]->GetStat("Level") + 1) * 4);
			players[1]->GiveExp(i);
			players[1]->SetStat("CurrHP", battleEntities[1]->GetStat("CurrHP"));
			slog += players[1]->GetName() + " gained " + to_string(i) + " experience\n";
		}
		if (battleEntities[2]->GetStat("CurrHP") > 0)
		{
			int i = 2 * ((battleEntities[4]->GetStat("Level") + 1) * 4);
			players[2]->GiveExp(i);
			players[2]->SetStat("CurrHP", battleEntities[2]->GetStat("CurrHP"));
			slog += players[2]->GetName() + " gained " + to_string(i) + " experience\n";
		}
		if (battleEntities[3]->GetStat("CurrHP") > 0)
		{
			int i = 2 * ((battleEntities[4]->GetStat("Level")+1) * 4);
			players[3]->GiveExp(i);
			players[3]->SetStat("CurrHP", battleEntities[3]->GetStat("CurrHP"));
			slog += players[3]->GetName() + " gained " + to_string(i) + " experience\n";
		}

		if (players[0]->hasLeveled == true)
		{
			slog += "Andrel leveled up\n";
			players[0]->hasLeveled = false;
		}
		if (players[1]->hasLeveled == true)
		{
			slog += "Charity leveled up\n";
			players[1]->hasLeveled = false;
		}
		if (players[2]->hasLeveled == true)
		{
			slog += "Helmaer leveled up\n";
			players[2]->hasLeveled = false;
		}
		if (players[3]->hasLeveled == true)
		{
			slog += "Horo leveled up\n";
			players[3]->hasLeveled = false;
		}

		party.clear();
		party.push_back(players[0]);
		party.push_back(players[1]);
		party.push_back(players[2]);
		party.push_back(players[3]);

		int j = 1050;

		GoldCount += j;

		slog += "You gained " + to_string(j) + " gold\n";
		slog += "Press Enter to continue...";
		battleLog.setString(slog);
		won = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		Reset();
		AudioManager::GetInstance()->PlayOverworld();
		activeScene = overworldScene;
	}
}

void BattleManager::Lose()
{
	Reset();
	AudioManager::GetInstance()->PlayGameOver();
	activeScene = loseScene;
}

vector<shared_ptr<BattleEntity>> BattleManager::GetBattleEnts()
{
	return battleEntities;
}