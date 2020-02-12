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

	/*static void LoadLevelFile(const string& path, float tileSize = 100.0f);
	static void Render(RenderWindow& window);
	static Color GetColor(TILE t);*/

};