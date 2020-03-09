#pragma once
#include <SFML/Graphics.hpp>
#include "UseableBase.h"

using namespace std;
using namespace sf;

class Item : public UsableBase
{
public:
	enum ItemTypes { None, Heal, Damage, NegativeStatus, PositiveStatus };
	void ItemUse(Item item, BattleEntity user);
	static Item ItemTable[4];
	Item();
	Item(string name, bool multitarget, UsableAlignment alignment, EntityEffect entityeffect)
		: UsableBase(name, multitarget, alignment, BattleManager::Alive, entityeffect) { }
	Item(string name, bool multitarget, UsableAlignment alignment, BattleManager::EntityFilterStates filterState, EntityEffect entityEffect)
		: UsableBase(name, multitarget, alignment, filterState, entityEffect) { }
	void OnUse(BattleEntity user, vector<BattleEntity> entities);
	Item Copy();
protected:
	Item(string name) : UsableBase(name) { name = name; AffectableBase::SetType(AffectableBase::Item); }
	Item(string name, bool multitarget) : Item(name) { UsableBase::SetMultiTarget(multitarget); }
private:
	
};