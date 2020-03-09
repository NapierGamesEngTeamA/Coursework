#pragma once
#include <SFML/Graphics.hpp>
#include "EntityHealEffect.h"

using namespace std;
using namespace sf;

class EntityPercentHealEffect : public EntityHealEffect
{
public:
	EntityPercentHealEffect(string name, float percentagehp, float percentagemp);
	void UseEffect(AffectableInfo affectable, vector<BattleEntity> entities) override;
	EntityEffect Copy() override;
private:
	float _percentageHP = 0;
	float _percentageMP = 0;

};