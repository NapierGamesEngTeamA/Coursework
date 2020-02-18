#include "LevelLoader.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;

unique_ptr<LevelLoader::TILE[]> LevelLoader::_tiles;
size_t LevelLoader::_width;
size_t LevelLoader::_height;
Vector2f LevelLoader::_offset(0, 0);
float LevelLoader::_tileSize(64);
vector<unique_ptr<Sprite>> LevelLoader::_sprites;
map<LevelLoader::TILE, Color> LevelLoader::_colors{ {GRASS, Color::Green}, {SEA, Color::Blue}, {MOUNTAIN, Color::Yellow} };

Color LevelLoader::GetColor(LevelLoader::TILE t)
{
	auto it = _colors.find(t);
	if (it == _colors.end())
	{
		_colors[t] = Color::Transparent;
	}
	return _colors[t];
}

void LevelLoader::SetColor(LevelLoader::TILE t, Color c)
{
	_colors[t] = c;
}

void LevelLoader::LoadLevelFile(const string& path, float tileSize)
{
	_tileSize = tileSize;
	size_t w = 0, h = 0;
	string buffer;

	ifstream f(path);
	if (f.good())
	{
		f.seekg(0, ios::end);
		buffer.resize(f.tellg());
		f.seekg(0);
		f.read(&buffer[0], buffer.size());
		f.close();
	}
	else
	{
		throw string("Couldn't open level file: ") + path;
	}

	vector<TILE> temp_tiles;
	for (int i = 0; i < buffer.size(); ++i)
	{
		const char c = buffer[i];
		switch (c)
		{
		case 'g':
			temp_tiles.push_back(GRASS);
			break;
		case 'm':
			temp_tiles.push_back(MOUNTAIN);
			break;
		case 's':
			temp_tiles.push_back(SEA);
			break;
		case ' ':
			temp_tiles.push_back(EMPTY);
			break;
		case '\n':
			if (w == 0)
			{
				w = i;
			}
			h++;
			break;
		default:
			cout << c << endl;
		}
	}

	_tiles = std::make_unique<TILE[]>(w * h);
	_width = w;
	_height = h;
	std::copy(temp_tiles.begin(), temp_tiles.end(), &_tiles[0]);
	cout << "Level " << path << " Loaded. " << w << "X" << h << endl;
	BuildSprites();

}

void LevelLoader::BuildSprites()
{
	_sprites.clear();
	for (size_t y = 0; y < _height; y++)
	{
		for (size_t x = 0; x < _width; x++)
		{
			auto s = make_unique<sf::Sprite>();
			s->setPosition(GetTilePosition({ x,y }));
			//s->setSize(Vector2f(_tileSize, _tileSize));
			s->setTextureRect(IntRect(0, 0, _tileSize, _tileSize));
			_sprites.push_back(move(s));
		}
	}
}

Vector2f LevelLoader::GetTilePosition(Vector2ul p)
{
	return (Vector2f(p.x, p.y) * _tileSize);
}

void LevelLoader::Render(RenderWindow& window)
{
	for (size_t i = 0; i < _width * _height; i++)
	{
		window.draw(*_sprites[i]);
	}
}