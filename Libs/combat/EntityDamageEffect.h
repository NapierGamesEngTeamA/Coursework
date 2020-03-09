#pragma once
#include <SFML/Graphics.hpp>
#include "EntityStatusEffect.h"
#include "Globals.h"

class EntityDamageEffect : EntityStatusEffect
{
public:
	int Damage = 0;
	Globals::DamageTypes DamageType = Globals::DamageTypes::None;
	Globals::Elements Element = Globals::Elements::Neurtal;
	bool BasedOnEntityDamage = false;
	EntityDamageEffect(string name, int damage, Globals::DamageTypes damagetype, Globals::Elements element, bool basedOnEntityDmg);
	EntityDamageEffect(string name, int damage, Globals::DamageTypes damagetype, Globals::Elements element, StatusEffect status, float percentage, bool basedOnEntityDmg);
	void UseEffect(AffectableInfo affectable, vector<BattleEntity> entities) override;
	EntityEffect Copy() override;
protected:

private:

};