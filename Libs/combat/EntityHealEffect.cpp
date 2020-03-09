#include "EntityHealEffect.h"

using namespace std;
using namespace sf;

void EntityHealEffect::UseEffect(AffectableInfo affectableInfo, vector<BattleEntity> entities)
{
	for (int i = 0; i < entities.size; i++)
	{
		entities[i].Restore(affectableInfo, HPRestored, MPRestored);
	}
}

EntityEffect EntityHealEffect::Copy()
{
	EntityHealEffect i(EntityEffect::AffectableBase::GetName(), HPRestored, MPRestored);
	return i;
}