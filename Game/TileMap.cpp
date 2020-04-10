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

	
	for (size_t y = 0; y < 93; y++)
	{
		for (size_t x = 0; x < 170; x++)
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

				float r1x = ch->tileX;
				float r1y = ch->tileY;
				Vector2f r2 = s->GetPosition();
				int c;

				int bottom, left, right, up;

				bottom = y * 16 + 16;
				up = y * 16;
				right = x * 16 + 16;
				left = x * 16;

				if (ch->right < left || ch->left > right || ch->top > bottom || ch->bottom < up)
				{
						cout << "No Collision " << '\n';
				}
				else
				{
					cout << "Collision Has Worked " << '\n';
					break;
				}


				//if (r1x <= r2.x + 16 && r1x + 32 >= r2.x && r1y <= r2.y + 16 && r1y + 32 >= r2.y)
				//{
				//	cout << "Collision Has Worked " << '\n';
				//}
				//else
				//{
				//	// nothing...
				//}


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
			else if (list[y][x] == NULL)
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 16, y * 16));
				u->SetRect(IntRect(463, 334, 32, 32));
			}
		}
	}
}
