#pragma once
#include "ecm.h"
#include <memory>
#include <string>
#include <vector>
#include "Character.h"

using namespace sf;

class TileMap : public Entity
{
protected:
	
public:
	enum TYPE { EMPTY, GRASS, STONE, WATER };

	int _width, _height;
	int _tileSize;
	vector<vector<char>> tiles1;
	TileMap() 
	{ 
		_width = 50 ;
		_height = 50;
		_tileSize = 32;
	};
	void Update(Time dt) override;
	void Render() override;
	void GenerateMap(const string& path, const Texture& texture, shared_ptr<Character> ch);
	void BuildSprites(const Texture& texture, vector<vector<char>> list, shared_ptr<Character> ch);
	void UpdateColMap(shared_ptr<Character> ch, vector<vector<char>> list);
	
};