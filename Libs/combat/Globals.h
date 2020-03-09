#pragma once
#include "BattleEntity.h"
#include "AffectableBase.h"

static class Globals
{
public:
	static enum DamageTypes { None, Physical, Magic };
	static enum Elements { Neurtal, Fire, Earth, Ice, Poison };
};

static struct AffectableInfo
{
public:
	BattleEntity Affector;
	AffectableBase AffectableObj;
	AffectableInfo(BattleEntity affector, AffectableBase affectableObj)
	{
		Affector = affector;
		AffectableObj = affectableObj;
	}
};