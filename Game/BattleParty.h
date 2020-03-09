#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>
#include "BattleEntity.h"

using namespace sf;
using namespace std;

class BattleParty : public Entity
{
public:
	vector<BattleEntity> Party;
	BattleParty();
	virtual void Update(Time dt) override;
	virtual void Render() override;
	void AddPartyMember(BattleEntity b);
	void SetupPlayer(Texture* texture);
	void SetupEnemy();
	vector<BattleEntity> GetParty() { return Party; }
	//void SetTexture(Texture t) { texture = t; }
protected:

private:
};