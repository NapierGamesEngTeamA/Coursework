#include "EntityStatusEffect.h"

using namespace std;

EntityStatusEffect::EntityStatusEffect(string name, StatusEffect status, float percentage) : EntityEffect(name), Status(1)
{
	Status = status;
	if (percentage < 0)
	{
		StatusPercent = 0;
	}
	else if (percentage > 100)
	{
		StatusPercent = 100;
	}
	else
	{
		StatusPercent = percentage;
	}
}

void EntityStatusEffect::UseEffect(AffectableInfo affectable, vector<BattleEntity> entities)
{
	for (int i = 0; i < entities.size; i++)
	{
		float percent = std::round(rand());
		if (StatusPercent > percent)
		{
			entities[i].InflictStatus(affectable, Status);
		}
	}
}

EntityEffect EntityStatusEffect::Copy()
{
	EntityStatusEffect* e = new EntityStatusEffect(EntityEffect::GetName(), Status.Copy(), StatusPercent);

	return *e;
}