#include "Item.h"
#include "EntityHealEffect.h"
#include "EntityDamageEffect.h"

using namespace sf;
using namespace std;

Item::Item()
{
	EntityHealEffect p("Potion", 20, 0);
	EntityHealEffect e("Ether", 0, 20);
	EntityDamageEffect b("Bomb", 10, Globals::DamageTypes::Physical, Globals::Elements::Neurtal, false);



	Item* potion = new Item("Potion", false, UsableAlignment::Positive, BattleManager::Alive, p.Copy());
	Item* ether = new Item("Ether", false, UsableAlignment::Positive, BattleManager::Alive, e.Copy());
	Item* bomb = new Item("Bomb", false, UsableAlignment::Negative, BattleManager::Alive, b.Copy());
	Item* pDown = new Item("Pheonix Down", false, UsableAlignment::Positive, BattleManager::EntityFilterStates::Dead, d.Copy());

}