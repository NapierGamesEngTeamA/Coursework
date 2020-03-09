#pragma once
#include <SFML/Graphics.hpp>
#include "EntityEffect.h"

using namespace std;
using namespace sf;

class EntityHealEffect : public EntityEffect
{
public:
	size_t HPRestored = 0;
	size_t MPRestored = 0;
	
	EntityHealEffect(string name, size_t hprestored, size_t mprestored) : EntityEffect(name) { HPRestored = hprestored; MPRestored = mprestored; }
	void UseEffect(AffectableInfo affectableInfo, vector<BattleEntity> entities) override;
	EntityEffect Copy() override;
private:
};
