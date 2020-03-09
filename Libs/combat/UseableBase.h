#pragma once
#include "AffectableBase.h"
#include "BattleManager.h"
#include "EntityEffect.h"

using namespace std;

class UsableBase : AffectableBase
{
public:
	enum UsableAlignment { Neutral, Positive, Negative };
	bool GetMultiTarget() { return _multiTarget; }
	UsableAlignment GetAlignment() { return _alignment; }
	EntityEffect GetEffect() { return _entityEffect; }
	BattleEntity::EntityTypes GetEntityTypeBasedOnAlignment(BattleEntity::EntityTypes entityType);
	BattleManager::EntityFilterStates GetFilterState() { return _filterState; }
protected:
	UsableBase() : AffectableBase("Usable") { }
	UsableBase(string name) : AffectableBase(name) { }
	UsableBase(string name, bool multitarget) : AffectableBase(name) { _multiTarget = multitarget; }
	UsableBase(string name, bool multitarget, UsableAlignment alignment) : UsableBase(name, multitarget) { _alignment = alignment; }
	UsableBase(string name, bool multitarget, BattleManager::EntityFilterStates filterstate) : UsableBase(name, multitarget) { _filterState = filterstate; }
	UsableBase(string name, bool multitarget, UsableAlignment alignment, BattleManager::EntityFilterStates filterstate) : UsableBase(name, multitarget) { _alignment = alignment;  _filterState = filterstate; }
	UsableBase(string name, bool multitarget, UsableAlignment alignment, BattleManager::EntityFilterStates filterstate, EntityEffect effect) : UsableBase(name, multitarget, alignment, filterstate) { _entityEffect = effect; }
	void SetMultiTarget(bool s) { _multiTarget = s; }
	void SetAlignment(UsableAlignment s) { _alignment = s; }
	void SetEffect(EntityEffect e) { _entityEffect = e; }
	void SetFilterState(BattleManager::EntityFilterStates f) { _filterState = f; }
private:
	bool _multiTarget;
	UsableAlignment _alignment;
	EntityEffect _entityEffect;
	BattleManager::EntityFilterStates _filterState;
};