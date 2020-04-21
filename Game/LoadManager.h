#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class LoadManager
{
private:
	ofstream file;
	string location;
public:
	LoadManager();
	void SaveFile();
	void LoadFile(string loc);
};