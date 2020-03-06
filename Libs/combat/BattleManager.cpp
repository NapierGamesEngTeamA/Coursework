#include "BattleManager.h"

using namespace std;
using namespace sf;

BattleManager* BattleManager::_instance = 0;

BattleManager* BattleManager::GetInstance()
{
	if (_instance == 0)
	{
		_instance = new BattleManager();
	}

	return _instance;
}