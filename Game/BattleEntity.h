#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class BattleEntity : public Entity
{
public:
	BattleEntity();
	virtual void Update(Time dt) override;
	virtual void Render() override;

protected:

private:
	map<string, int> _stats;
	/*int _currHP, _currMP;
	int _maxHP, _maxMP;
	int _strength, _dexterity, _intellect, _constitution;*/
};