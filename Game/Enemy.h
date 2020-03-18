#pragma once
#include "ecm.h"
#include "Animation.h"
#include "Character.h"

using namespace sf;

class Enemy : public Character
{
private:
	//float _speed = 10;
public:


	Enemy()
	{
		
	};
	void Update(Time dt) override;
	void Render() override;
};