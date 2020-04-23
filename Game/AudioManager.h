#pragma once
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class AudioManager
{
private:
	static AudioManager* _instance;
	AudioManager();

public:
	static AudioManager* GetInstance();
	static void Load();
	static void Update();
	static void PlayOverworld();
	static void PlayBattle();
	static void PlayGameOver();
};
