#include "LoadManager.h"
#include "Game.h"

using namespace std;

LoadManager::LoadManager()
{

}

void LoadManager::SaveFile(string s)
{
	file.open(location);
	file << s;
	file.close();
}

void LoadManager::LoadFile(string loc)
{
	string s;
	file.open(location);
	
	file.close();
}