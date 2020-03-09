#pragma once
#include <SFML/Graphics.hpp>
#include "AffectableBase.h"
#include "BattleEntity.h"
#include "Globals.h"

using namespace std;
using namespace sf;

class EntityEffect : public AffectableBase
{
public:
	virtual void UseEffect(AffectableInfo affectableInfo, vector<BattleEntity> entities);
	virtual EntityEffect Copy();
	EntityEffect() : AffectableBase("Effect") { }
	EntityEffect(string name) : AffectableBase(name) { }
protected:
	
private:

};