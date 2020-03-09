#include "UseableBase.h"

using namespace std;
using namespace sf;

BattleEntity::EntityTypes UsableBase::GetEntityTypeBasedOnAlignment(BattleEntity::EntityTypes entityType)
{
	UsableAlignment alignment = _alignment;

	if (_alignment == UsableAlignment::Neutral || entityType == BattleEntity::None)
	{
		return BattleEntity::None;
	}

	if (_alignment == UsableAlignment::Positive)
	{
		return entityType == BattleEntity::Player ? BattleEntity::Player : BattleEntity::Enemy;
	}
	else
	{
		return entityType == BattleEntity::Player ? BattleEntity::Enemy : BattleEntity::Player;
	}
}