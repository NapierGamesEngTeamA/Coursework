#pragma once
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class AffectableBase
{
public:
	enum AffectableTypes { None, Attack, Item, Spell, Status };
	string GetName() { return _name; }
	AffectableTypes GetType() { return _type; }
	AffectableBase() { };
	static void SetType(AffectableTypes t) { _type = t; }
protected:
	AffectableBase(string name) { _name = name; }
	void SetName(string s) { _name = s; }
private:
	string _name;
	static AffectableTypes _type;
};