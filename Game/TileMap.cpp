#include "TileMap.h"
#include <fstream>
#include <iostream>
#include "Tile.h"
#include "Character.h"

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

void TileMap::GenerateMap(const string& path, const Texture& texture, shared_ptr<Character> ch)
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
	

	BuildSprites(texture, tiles, ch);

}

void TileMap::BuildSprites(const Texture& texture, vector<vector<char>> list, shared_ptr<Character> ch)
{
	ch->tileX = ch->GetPosition().x / 32;
	ch->tileY = ch->GetPosition().y / 32;

	int leftTileUp = ch->tileX - 1 + ch->tileY * 200;
	int leftTileDown = ch->tileX - 1 + (ch->tileY + 1) * 200;
	int rightTileUp = ch->tileX + 1 + ch->tileY * 200;
	int rightTileDown = ch->tileX + 1 + (ch->tileY + 1) * 200;
	int underTile = ch->tileX + (ch->tileY + 2) * 200;
	int topTile = ch->tileX + (ch->tileY - 1) * 200;

	for (size_t y = 0; y < 90; y++)
	{
		for (size_t x = 0; x < 200; x++)
		{
			ch->SetPosition(Vector2f(2000, 400));

			if (list[y][x] == 'g')
			{
				auto t = AddComponent<Tile>();
				//t->SetTexture(texture);
				t->GetSprite().setTexture(texture);
				t->SetPosition(Vector2f(x * 16, y *16));
				t->SetRect(IntRect(0, 0, 32, 32));
			}
			else if (list[y][x] == 'w')
			{
				auto s = AddComponent<Tile>();
				//s->SetTexture(texture);
				s->GetSprite().setTexture(texture);
				s->SetPosition(Vector2f(x * 16, y * 16));
				s->SetRect(IntRect(463, 334, 32, 32));

				//Vector2f rect1 = ch->GetPosition();
				//Vector2f rect2 = list[x][y];
				int c;

				if ((ch->GetPosition().x == x) && (ch->GetPosition().y == y)){
					cout << "Collision Has Worked " << '\n';
				}

			/*	if (rect1.x < rect2.x + 16 &&
					rect1.x + 30 > rect2.x&&
					rect1.y < rect2.y + 16 &&
					rect1.y + 33 > rect2.y) {
					c++;

					printf("collision detected", c);
				}
				*/
			}
			else if (list[y][x] == 's')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 16, y * 16));
				u->SetRect(IntRect(383, 288, 32, 32));
			}
			else if (list[y][x] == 'r')
			{
				auto v = AddComponent<Tile>();
				//s->SetTexture(texture);
				v->GetSprite().setTexture(texture);
				v->SetPosition(Vector2f(x * 16, y * 16));
				v->SetRect(IntRect(388, 0, 32, 32));
			}
		}
	}
}
