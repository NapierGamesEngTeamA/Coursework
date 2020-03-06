#pragma once
#include <SFML/Graphics.hpp>
#include "BattleEntity.h"

using namespace sf;
using namespace std;

class BattleManager
{
public:	
	enum BattleStates { Init, Combat, TurnDone, Victory, GameOver };
	enum EntityFilterStates { All, Alive, Dead };
	static BattleManager* GetInstance();

	vector<BattleEntity>* Entities = new vector<BattleEntity>();
	vector<BattleEntity>* Enemies = new vector<BattleEntity>();
	vector<BattleEntity>* Players = new vector<BattleEntity>();



private:
	static BattleManager* _instance;
	vector<BattleEntity> _turnOrder;
};