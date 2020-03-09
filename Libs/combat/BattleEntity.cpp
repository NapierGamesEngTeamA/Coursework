#include "UseableBase.h"

BattleEntity::EntityTypes UsableBase::GetEntityTypeBasedOnAlignment(BattleEntity::EntityTypes entityType)
{
	UsableAlignment alignment = _alignment;

	if (alignment == UsableAlignment::Neutral || entityType == BattleEntity::None)
	{
		return BattleEntity::None;
	}

	if (alignment == UsableAlignment::Positive)
	{
		return entityType == BattleEntity::Player ? BattleEntity::Player : BattleEntity::Enemy;
	}
	else
	{
		return entityType == BattleEntity::Player ? BattleEntity::Enemy : BattleEntity::Player;
	}
}
