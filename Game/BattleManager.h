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
	Font font;
	Text battleLog;
	string slog;
public:
	enum BattleStates { Start, ChooseAction, ChooseTarget, Action, NextTurn, End };
	BattleStates currentState = BattleStates::Start;;
	enum ActionTypes { None, aAttack, aMagic, aFlee };
	ActionTypes currentAction = ActionTypes::None;;
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
	void Win();
	void Lose();
	vector<shared_ptr<BattleEntity>> GetEnts();
	vector<shared_ptr<BattleEntity>> GetBattleEnts();
};