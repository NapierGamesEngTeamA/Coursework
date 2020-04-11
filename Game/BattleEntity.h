#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"

class BattleEntity : public Entity
{
public:
	enum AnimStates { IDLE, ATTACK, DEATH };
	AnimStates currentState;
	map<string, Animation> _anims;
	Animation* currentAnim;
	string name;
	map<string, int> stats;

	BattleEntity();

	void Update(Time dt) override;
	void Render() override;
	void Setup(vector<int> st, string na);
	void Levelup();
	int GetStat(string s);
	string GetName();
	void SetName(string s);
	int PhAttack();
	int MgAttack();
	void GiveExp(int i);
	string GetHealthText();
private:
};