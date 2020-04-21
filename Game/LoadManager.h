#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class LoadManager
{
private:
	ofstream file;
	string location = "SaveFile.txt";
public:
	LoadManager();
	void SaveFile(string s);
	void LoadFile(string loc);
};