#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include "maths.h"

#define ls LevelLoader

using namespace sf;
using namespace std;

class LevelLoader
{
public:
	enum TILE { EMPTY, GRASS, MOUNTAIN, SEA };

	static void LoadLevelFile(const string& path, float tileSize = 100.0f);
	static void Render(RenderWindow& window);
	static Color GetColor(TILE t);
	static void SetColor(TILE t, Color c);
	vector<Vector2ul> FindTiles(TILE);

	static TILE GetTile(Vector2ul);
	static Vector2f GetTilePosition(Vector2ul);
	static TILE GetTileAt(Vector2f);
	static size_t GetHeight() { return _height; }
	static size_t GetWidth() { return _width; }
protected:
	static unique_ptr<TILE[]> _tiles;
	static size_t _width;
	static size_t _height;
	static Vector2f _offset;
	static float _tileSize;
	static map<TILE, Color> _colors;
	static vector<unique_ptr<Sprite>> _sprites;
	static void BuildSprites();
private:
	LevelLoader() = delete;
	~LevelLoader() = delete;

};