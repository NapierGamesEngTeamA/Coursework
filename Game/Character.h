#pragma once
#include "ecm.h"
#include "Animation.h"

using namespace sf;

class Character : public Entity
{
private:
	//float _speed = 10;
public:
	enum AnimStates { STAND_UP, STAND_DOWN, STAND_LEFT, STAND_RIGHT, WALK_UP, WALK_DOWN, WALK_RIGHT, WALK_LEFT };
	AnimStates currentState;
	map<string, Animation> _anims;
	Animation* currentAnim;
	vector<Vector2i> tiles;

	int tileX = 125;
	int tileY = 75;

	float bottom, left, right, top;



	Character() 
	{ 
		currentState = STAND_RIGHT;
		currentAnim = new Animation();
	};
	void Update(Time dt) override;
	void Render() override;
};