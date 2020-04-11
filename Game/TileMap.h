#pragma once
#include "ecm.h"
#include <memory>
#include <string>
#include <vector>

using namespace sf;

class TileMap : public Entity
{
protected:
	
public:
	enum TYPE { EMPTY, GRASS, STONE, WATER };

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
	void GenerateMap(const string& path, const Texture& texture);
	void BuildSprites(const Texture& texture, vector<vector<char>> list);

};