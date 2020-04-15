#include "TileMap.h"
#include <fstream>
#include <iostream>
#include "Tile.h"
#include "Character.h"
#include "Game.h"
#include "PlayerMovementComponent.h"

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
	
	tiles1 = tiles;

}

void TileMap::BuildSprites(const Texture& texture, vector<vector<char>> list, shared_ptr<Character> ch )
{

	
	for (size_t y = 0; y < 90; y++)
	{
		for (size_t x = 0; x < 200; x++)
		{
			ch->SetPosition(Vector2f(ch->tileX * 32, ch->tileY * 32));

			if (list[y][x] == 'g')
			{
				auto t = AddComponent<Tile>();
				//t->SetTexture(texture);
				t->GetSprite().setTexture(texture);
				t->SetPosition(Vector2f(x * 32, y * 32));
				t->SetRect(IntRect(0, 0, 32, 32));
			}
			else if (list[y][x] == 'w')
			{
				auto s = AddComponent<Tile>();
				//s->SetTexture(texture);
				s->GetSprite().setTexture(texture);
				s->SetPosition(Vector2f(x * 32, y * 32));
				s->SetRect(IntRect(463, 334, 32, 32));

				


			}
			else if (list[y][x] == 's')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(383, 288, 32, 32));
			}
			else if (list[y][x] == 'r')
			{
				auto v = AddComponent<Tile>();
				//s->SetTexture(texture);
				v->GetSprite().setTexture(texture);
				v->SetPosition(Vector2f(x * 32, y * 32));
				v->SetRect(IntRect(388, 0, 32, 32));
			}
			else if (list[y][x] == 'm')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(18, 145, 32, 32));
			}
			else if (list[y][x] == 'd')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(128, 0, 32, 32));
			}
			else if (list[y][x] == 'p')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(64, 95, 32, 32));
			}
			else if (list[y][x] == 'z')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(269, 335, 32, 32));
			}
			else if (list[y][x] == 'b')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(207, 335, 32, 32));
			}
			else if (list[y][x] == 'f')
			{
				auto u = AddComponent<Tile>();
				//s->SetTexture(texture);
				u->GetSprite().setTexture(texture);
				u->SetPosition(Vector2f(x * 32, y * 32));
				u->SetRect(IntRect(272, 47, 32, 32));
			}
		}
	}
}
void TileMap::UpdateColMap(shared_ptr<Character> ch, vector<vector<char>> list, Time dt)
{

	int xpos = ch->GetPosition().x - 5;
	int ypos = ch->GetPosition().y - 5;





	for (size_t y = 0; y < 90; y++)
	{
		for (size_t x = 0; x < 200; x++)
		{
			if (list[y][x] == 'w')
			{
				int bottom, left, right, up;


				bottom = y * 32 + 32;
				up = y * 32;
				right = x * 32 + 32;
				left = x * 32;

				auto s = ch->GetComponents<PlayerMovementComponent>();


				Vector2f prevpos;


				int movespeed;

				movespeed = s[0]->GetSpeed();

				int prevtilex = ch->tileX - 1;
				int prevtiley = ch->tileY;




				float speed = 100;

				if (ch->right < left || ch->left > right || ch->top > bottom || ch->bottom < up)
				{
					//cout << "No Collision " << '\n';


				}
				else
				{
					cout << "Collision Detected" << '\n';
				
				}

				//else if (ch->right > left)
				//{
				//	//speed++;
				//	ch->SetPosition(Vector2f(xpos + 10, ypos));
				//	//s[0]->Move(Vector2f(0, speed));
				//	//s[0]->Move(Vector2f(s[0]->GetSpeed() * dt.asSeconds(), 0));

				//	cout << "RIGHT Has Worked " << '\n';
				//	break;
				//}
				//else if (ch->left < right)
				//{
				//	//speed--;
				//	ch->SetPosition(Vector2f(xpos - 10, ypos));
				//	//s[0]->Move(Vector2f(0, speed));
				////s[0]->Move(Vector2f(s[0]->GetSpeed() * dt.asSeconds(), 0));

				//	cout << "LEFT Has Worked " << '\n';
				//	break;
				//}
				//else if (ch->top < bottom)
				//{
				//	//speed++;
				//	ch->SetPosition(Vector2f(xpos, ypos - 10));
				//	//s[0]->Move(Vector2f(speed, 0));
				////s[0]->Move(Vector2f(0, -s[0]->GetSpeed() * dt.asSeconds()));
				//	cout << "DOWN Has Worked " << '\n';
				//	break;
				//}
				//else if (ch->bottom > up)
				//{
				//	//speed--;
				//	//s[0]->Move(Vector2f(speed, 0));
				//	cout << "UP Has Worked " << '\n';
				//	//s[0]->Move(Vector2f(0, s[0]->GetSpeed() * dt.asSeconds()));
				//	ch->SetPosition(Vector2f(xpos, ypos + 10));
				//	break;
				//	//ch->SetPosition(Vector2f(0, ch->GetPosition().y - speed));
				//}




			}
		}
	}
}