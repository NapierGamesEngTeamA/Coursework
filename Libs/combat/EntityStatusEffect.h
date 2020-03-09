#pragma once
#include <SFML/Graphics.hpp>
#include "EntityEffect.h"
#include "StatusEffect.h"

using namespace std;
using namespace sf;

class EntityStatusEffect : public EntityEffect
{
public:
	StatusEffect Status;
	float StatusPercent = 0;
	EntityStatusEffect(string name, StatusEffect status, float percentage);
	void UseEffect(AffectableInfo af, vector<BattleEntity> entities) override;
	EntityEffect Copy() override;
protected:

private:
};