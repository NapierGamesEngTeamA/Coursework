#pragma once
#include "BattleEntity.h"

using namespace std;
using namespace sf;

class Andrel : public BattleEntity
{
public:
	Andrel();
	~Andrel() { };
	void Update(Time dt) override;
	void Render() override;
protected:

private:
};