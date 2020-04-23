#include "AudioManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

SoundBuffer* sb = new SoundBuffer();
bool isPlaying = false;
Music ovMusic, btMusic, goMusic, victoryMusic;
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
	victoryMusic.stop();

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
	victoryMusic.stop();

	if (!btMusic.openFromFile("Res/Music/BossFight.ogg"))
	{

	}

	btMusic.setLoop(true);
	btMusic.setVolume(volume);
	btMusic.play();
}

void AudioManager::PlayVictory()
{
	ovMusic.stop();
	goMusic.stop();
	btMusic.stop();

	if (!victoryMusic.openFromFile("Res/Music/Victory!.ogg"))
	{

	}

	victoryMusic.setLoop(false);
	victoryMusic.setVolume(volume);
	victoryMusic.play();
}

void AudioManager::PlayGameOver()
{
	ovMusic.stop();
	goMusic.stop();
	btMusic.stop();

	if (!goMusic.openFromFile("Res/Music/Game Over.ogg"))
	{

	}

	goMusic.setLoop(false);
	goMusic.setVolume(volume);
	goMusic.play();
}