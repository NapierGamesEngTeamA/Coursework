#include "AudioManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

SoundBuffer* sb = new SoundBuffer();
bool isPlaying = false;
Music ovMusic, btMusic, goMusic;
float volume = 1;

AudioManager* AudioManager::_instance = 0;

AudioManager* AudioManager::GetInstance()
{
	if (_instance == 0)
	{
		_instance = new AudioManager();
	}

	return _instance;
}

AudioManager::AudioManager()
{

}

void AudioManager::Load()
{
	
}

void AudioManager::Update()
{

}

void AudioManager::PlayOverworld()
{
	btMusic.stop();
	goMusic.stop();

	if (!ovMusic.openFromFile("Res/Music/Overworld.ogg"))
	{
		
	}

	ovMusic.setLoop(true);
	ovMusic.setVolume(volume);
	ovMusic.play();
}

void AudioManager::PlayBattle()
{
	ovMusic.stop();
	goMusic.stop();

	if (!btMusic.openFromFile("Res/Music/BossFight.ogg"))
	{

	}

	btMusic.setLoop(true);
	btMusic.setVolume(volume);
	btMusic.play();
}