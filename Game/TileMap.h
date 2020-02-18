#pragma once
#include "ecm.h"

using namespace sf;

class TileMap : public Entity
{
protected:
	
public:
	int _width, _height;
	int _tileSize;
	TileMap() 
	{ 
		_width = 50;
		_height = 50;
		_tileSize = 32;
	};
	void Update(Time dt) override;
	void Render() override;

};