#include "TileMap.h"
#include <fstream>
#include <iostream>
#include "Tile.h"

using namespace sf;
using namespace std;

void TileMap::Update(Time dt)
{
	Entity::Update(dt);
}

void TileMap::Render()
{
	Entity::Render();
}

void TileMap::GenerateMap(const string& path, const Texture& texture)
{
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

	
	cout << buffer << endl;

	vector<vector<char>> tiles;
	tiles.push_back(vector<char>());
	int j = 0;

	for (size_t i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == '\n')
		{
			j++;
			tiles.push_back(vector<char>());
		}
		else
		{
			tiles[j].push_back(buffer[i]);
		}
		//cout << tiles[j][i] << endl;
		cout << tiles[j].size();
	}

	cout << tiles.size() << endl;
	

	BuildSprites(texture, tiles);

}

void TileMap::BuildSprites(const Texture& texture, vector<vector<char>> list)
{
	for (size_t y = 0; y < 50; y++)
	{
		for (size_t x = 0; x < 50; x++)
		{
			/*auto t = AddComponent<Tile>();
			t->SetTexture(texture);
			t->GetSprite().setTexture(texture);
			t->SetPosition(Vector2f(x * 16, y * 16));*/
			if (list[y][x] == 'g')
			{
				auto t = AddComponent<Tile>();
				//t->SetTexture(texture);
				t->GetSprite().setTexture(texture);
				t->SetPosition(Vector2f(x * 16, y * 16));
				t->SetRect(IntRect(324, 137, 16, 16));
			}
			else if (list[y][x] == 'w')
			{
				auto s = AddComponent<Tile>();
				//s->SetTexture(texture);
				s->GetSprite().setTexture(texture);
				s->SetPosition(Vector2f(x * 16, y * 16));
				s->SetRect(IntRect(290, 273, 16, 16));
			}
			else
			{
				
			}
		}
	}
}
