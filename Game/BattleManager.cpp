#include "BattleManager.h"
#include "AnimatedSpriteComponent.h"
#include "SystemRenderer.h"
#include "InputManager.h"
#include "Game.h"

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
	stats[0].push_back(2); //Strength
	stats[0].push_back(3); //Dexterity
	stats[0].push_back(1); //Intellect
	stats[0].push_back(2); //Constitution
	stats[0].push_back(10); //Health
	stats[0].push_back(0); //MP

	stats[1].push_back(1);
	stats[1].push_back(2);
	stats[1].push_back(3);
	stats[1].push_back(2);
	stats[1].push_back(10);
	stats[1].push_back(15);

	stats[2].push_back(3);
	stats[2].push_back(1);
	stats[2].push_back(1);
	stats[2].push_back(3);
	stats[2].push_back(20);
	stats[2].push_back(0);

	stats[3].push_back(1);
	stats[3].push_back(2);
	stats[3].push_back(4);
	stats[3].push_back(2);
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
	andrel->_anims.insert(pair<string, Animation>("Idle", *idle));

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
	charity->_anims.insert(pair<string, Animation>("Idle", *idle1));

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
	helmaer->_anims.insert(pair<string, Animation>("Idle", *idle2));

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
	horo->_anims.insert(pair<string, Animation>("Idle", *idle3));

	auto d = horo->AddComponent<AnimatedSpriteComponent>();
	d->SetAnimation(*idle3);
	d->Play();

	horo->SetPosition(Vector2f(600, 800));
	players.push_back(horo);
#pragma endregion
#pragma endregion

	#pragma region Orc Party
	vector<int> orcStats;
	orcStats.push_back(3);
	orcStats.push_back(1); 
	orcStats.push_back(1);
	orcStats.push_back(3);
	orcStats.push_back(12); 
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
	orc1->_anims.insert(pair<string, Animation>("Idle", *idle0));
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
	skelStats.push_back(4); //Intellect
	skelStats.push_back(3); //Constitution
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
	skel1->_anims.insert(pair<string, Animation>("Idle", *idle5));
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
	auto c8 = skel4->AddComponent<AnimatedSpriteComponent>();
	c8->SetAnimation(*idle5);
	c8->Play();
	skel4->SetPosition(Vector2f(900, 800));

	skeletons.push_back(skel4);
#pragma endregion

	currentState = BattleStates::Start;
	currentAction = ActionTypes::None;

	slog = " ";
	font.loadFromFile("Res/Fonts/BreatheFire-65pg.ttf");
	battleLog.setFont(font);
	battleLog.setColor(Color::White);
	battleLog.setCharacterSize(24);
	battleLog.setPosition(Vector2f(1600, 900));
	battleLog.setString(" ");

	party.push_back(players[0]);
	party.push_back(players[1]);
	party.push_back(players[2]);
	party.push_back(players[3]);
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
		i->SetupEnemy(level);
		battleEntities.push_back(i);
	}
}

void BattleManager::PickAction()
{
	if (currentEntity->type == BattleEntity::Type::Player)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			currentAction = ActionTypes::aAttack;
			currentState = BattleStates::ChooseTarget;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			currentAction = ActionTypes::aMagic;
			currentState = BattleStates::ChooseTarget;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			currentAction = ActionTypes::aFlee;
			currentState = BattleStates::Action;
		}
	}
	else
	{
		int i = rand() % 2 + 1;

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
			selectedTarget = 4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			selectedTarget = 5;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			selectedTarget = 6;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
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
		battleEntities[selectedTarget]->SetStat("CurrHP",
			battleEntities[selectedTarget]->GetStat("CurrHP") - currentEntity->PhAttack());
		slog += currentEntity->GetName() + " dealt " + to_string(currentEntity->PhAttack()) + " damage to " + battleEntities[selectedTarget]->GetName() + "\n";
		battleLog.setString(slog);
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
		battleEntities[selectedTarget]->SetStat("CurrHP",
			battleEntities[selectedTarget]->GetStat("CurrHP") - currentEntity->MgAttack());
		slog += currentEntity->GetName() + " dealt " + to_string(currentEntity->MgAttack()) + " damage to " + battleEntities[selectedTarget]->GetName() + "\n";
		battleLog.setString(slog);
		currentEntity->SetStat("CurrMP", currentEntity->GetStat("CurrMP") - 5);
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
		slog = "Not enough mana to cast magic. Try something else.";
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

void BattleManager::Reset()
{
	battleEntities.clear();
	enemies.clear();
	currentState = BattleStates::Start;
	currentAction = ActionTypes::None;
	selectedTarget = -1;
	index = 0;
	turn = 0;
}

void BattleManager::Render()
{
	for (auto s : battleEntities)
	{
		s->Render();
	}
	Renderer::Queue(&battleLog);
}

vector<shared_ptr<BattleEntity>> BattleManager::GetEnts()
{
	return players;
}

void BattleManager::Win()
{
	if (battleEntities[0]->GetStat("CurrHP") > 0)
	{
		players[0]->GiveExp((2 * battleEntities[4]->GetStat("Level")) * 4);
		players[0]->SetStat("CurrHP", battleEntities[0]->GetStat("CurrHP"));
	}
	if (battleEntities[1]->GetStat("CurrHP") > 0)
	{
		players[1]->GiveExp((2 * battleEntities[4]->GetStat("Level")) * 4);
		players[1]->SetStat("CurrHP", battleEntities[1]->GetStat("CurrHP"));
	}
	if (battleEntities[2]->GetStat("CurrHP") > 0)
	{
		players[2]->GiveExp((2 * battleEntities[4]->GetStat("Level")) * 4);
		players[2]->SetStat("CurrHP", battleEntities[2]->GetStat("CurrHP"));
	}
	if (battleEntities[3]->GetStat("CurrHP") > 0)
	{
		players[3]->GiveExp((2 * battleEntities[4]->GetStat("Level")) * 4);
		players[3]->SetStat("CurrHP", battleEntities[3]->GetStat("CurrHP"));
	}

	if (players[0]->GetStat("Level") > battleEntities[0]->GetStat("Level"))
	{
		cout << "Andrel leveled up\n" << endl;
	}
	if (players[1]->GetStat("Level") > battleEntities[1]->GetStat("Level"))
	{
		cout << "Charity leveled up\n" << endl;
	}
	if (players[2]->GetStat("Level") > battleEntities[2]->GetStat("Level"))
	{
		cout << "Helmaer leveled up\n" << endl;
	}
	if (players[3]->GetStat("Level") > battleEntities[3]->GetStat("Level"))
	{
		cout << "Horo leveled up\n" << endl;
	}

	party.clear();
	party.push_back(players[0]);
	party.push_back(players[1]);
	party.push_back(players[2]);
	party.push_back(players[3]);

	GoldCount += 100 * battleEntities[4]->GetStat("Level");

	Reset();
	activeScene = overworldScene;
}

void BattleManager::Lose()
{
	Reset();
	// Go to game over screen
	

}

vector<shared_ptr<BattleEntity>> BattleManager::GetBattleEnts()
{
	return battleEntities;
}