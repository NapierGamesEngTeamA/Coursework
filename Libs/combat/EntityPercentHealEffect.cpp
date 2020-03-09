#include "EntityPercentHealEffect.h"
#include "EntityEffect.h"

EntityPercentHealEffect::EntityPercentHealEffect(string name, float percentagehp, float percentagemp) :
	EntityHealEffect(name, 0, 0)
{
	if (percentagehp < 0)
	{
		_percentageHP = 0;
	}
	else if (percentagehp > 1)
	{
		_percentageHP = 1;
	}
	else
	{
		_percentageHP = percentagehp;
	}

	if (percentagemp < 0)
	{
		_percentageMP = 0;
	}
	else if (percentagemp > 1)
	{
		_percentageMP = 1;
	}
	else
	{
		_percentageMP = percentagemp;
	}
}

void EntityPercentHealEffect::UseEffect(AffectableInfo affectable, vector<BattleEntity> entities)
{
	for (int i = 0; i < entities.size; i++)
	{
		int hpRestored = (int)(entities[i].MaxHP * _percentageHP);
		int mpRestored = (int)(entities[i].MaxMP * _percentageMP);

		entities[i].Restore(affectable, hpRestored, mpRestored);
	}
}

EntityEffect EntityPercentHealEffect::Copy()
{
	EntityPercentHealEffect i(EntityEffect::GetName(), _percentageHP, _percentageMP);
}
