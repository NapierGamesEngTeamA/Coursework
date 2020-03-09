#include "BattleManager.h"


using namespace std;
using namespace sf;

class BattleEntity
{
public:
	enum EntityTypes { None, Player, Enemy };
	BattleEntity();
	void Restore(AffectableInfo affectableInfo, size_t hp, size_t mp);
	void TurnStart();
	void TurnEnd();
private:

};