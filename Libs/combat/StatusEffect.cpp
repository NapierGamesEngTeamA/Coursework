#include "StatusEffect.h"

using namespace std;
using namespace sf;

void StatusEffect::IncrementTurns()
{
	if (_isFinished == false)
	{
		_turnsPassed++;
		if (_isFinished)
		{
			End();
		}
	}
}