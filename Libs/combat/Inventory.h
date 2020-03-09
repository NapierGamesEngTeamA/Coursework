#pragma once
#include <sfml/Graphics.hpp>

using namespace std;
using namespace sf;

class Inventory
{
public:
	Inventory();
private:
	map<Item, int> ItemDictionary;
};