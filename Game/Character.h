#pragma once
#include "ecm.h"

using namespace sf;

class Character : public Entity
{
private:
	float _speed;
public:
	Character() { };
	void Update(double dt) override;
	void Render() override;
};