#include "EntityDamageEffect.h"

EntityDamageEffect::EntityDamageEffect(string name, int damage, Globals::DamageTypes damagetype, Globals::Elements element, bool basedOnEntityDmg) :
	EntityStatusEffect(name, 0, 0)
{
	Damage = damage;
	DamageType = damagetype;
	Element = element;
}

EntityDamageEffect::EntityDamageEffect(string name, int damage, Globals::DamageTypes damagetype, Globals::Elements element, StatusEffect status, float percentage, bool basedOnEntityDmg) :
	EntityStatusEffect(name, status, percentage)
{
	Damage = damage;
	DamageType = damagetype;
	Element = element;
	BasedOnEntityDamage = basedOnEntityDmg;
}

void EntityDamageEffect::UseEffect(AffectableInfo affectable, vector<BattleEntity> entities)
{
	for (int i = 0; i < entities.size; i++)
	{
		int entityDamage = 0;
		if (BasedOnEntityDamage == true)
		{
			entityDamage = affectable.Affector.CalculateDamageDealt(DamageType, Element);
		}

		entities[i].TakeDamage(affectable, entityDamage + Damage, DamageType, Element);
	}
}

EntityEffect EntityDamageEffect::Copy()
{
	EntityDamageEffect e(EntityEffect::GetName(), Damage, DamageType, Element, Status.Copy(), StatusPercent, BasedOnEntityDamage);

	return e;
}