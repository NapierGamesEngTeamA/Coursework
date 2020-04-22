#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"

class BattleEntity : public Entity
{
public:
	enum AnimStates { IDLE, ATTACK, MAGIC, DEATH };
	enum Type { Player, Enemy };
	Type type;
	AnimStates currentState;
	map<string, Animation> _anims;
	Animation* currentAnim;
	string name;
	map<string, int> stats;
	bool hasLeveled = false;

	BattleEntity();

	void Update(Time dt) override;
	void Render() override;
	void Setup(vector<int> st, string na);
	void Levelup();
	int GetStat(string s);
	void SetStat(string s, int i);
	string GetName();
	void SetName(string s);
	int PhAttack();
	int MgAttack();
	void GiveExp(int i);
	string GetHealthText();
	void SetupEnemy(int level);
	vector<int> GetStatList();
	bool TurnEnded = false;
	string GetSaveString();
	void LoadChar(string s);
private:
};