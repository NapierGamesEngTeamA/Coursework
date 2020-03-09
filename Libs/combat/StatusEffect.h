#pragma once
#include <SFML/Graphics.hpp>
#include "AffectableBase.h"
#include "BattleEntity.h"

class StatusEffect : AffectableBase
{
public:
	void StatusFinished(StatusEffect status);
	BattleEntity GetEntity() { return _entity; }
	BattleEntity SetAfflicter() { return _afflicter; }
	int GetTurns() { return _turns; }
	int GetTurnsPassed() { return _turnsPassed; }
	virtual void Refresh() { _turnsPassed = 0; }
	virtual void OnInflict();
	void End() { OnEnd(); }
	virtual StatusEffect Copy();
	StatusEffect(int turns);
protected:
	void SetEntity(BattleEntity b) { _entity = b; }
	void SetAfflicter(BattleEntity b) { _afflicter = b; }
	void SetTurns(int i) { _turns = i; }
	void GetTurnsPassed(int i) { _turnsPassed = i; }
	void IncrementTurns();
	virtual void OnEnd();
	virtual void OnStartTurn();
	virtual void OnTurnEnd();
private:
	BattleEntity _entity;
	BattleEntity _afflicter;
	int _turns;
	int _turnsPassed;
	bool _isFinished;
};
