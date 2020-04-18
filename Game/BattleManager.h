#pragma once
#include <SFML/Graphics.hpp>
#include "BattleEntity.h"

using namespace std;
using namespace sf;

class BattleManager
{
private:
	vector<shared_ptr<BattleEntity>> players;
	vector<shared_ptr<BattleEntity>> enemies;
	vector<shared_ptr<BattleEntity>> orcs;
	vector<shared_ptr<BattleEntity>> skeletons;
	vector<shared_ptr<BattleEntity>> battleEntities;
	shared_ptr<BattleEntity> currentEntity;
	int selectedTarget = -1;
	int index = 0;
	int turn = 0;
public:
	enum BattleStates { Start, ChooseAction, ChooseTarget, Action, NextTurn, End };
	BattleStates currentState;
	enum ActionTypes { None, aAttack, aMagic, aFlee };
	ActionTypes currentAction;
	BattleManager();
	void Load();
	void Update(Time dt);
	void StartBattle(int type, int level);
	void Reset();
	void PickAction();
	void PickTarget();
	void Attack();
	void Magic();
	void Flee();
	void ChangeTurn();
	void Render();
	void CalcEnd();
	vector<shared_ptr<BattleEntity>> GetEnts();
};