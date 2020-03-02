#include "AudioManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

SoundBuffer* sb = new SoundBuffer();
bool isPlaying = false;
Music menuMusic;

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
	menuMusic.openFromFile("Res/Music/MenuMusic.mp3");
}

void AudioManager::Update()
{

}

void AudioManager::PlaySong()
{
	if (!isPlaying)
	{
		isPlaying = true;
		menuMusic.play();
	}
}

void AudioManager::PlaySound(Sound& s)
{
	/*s.setBuffer(*sb);
	s.play();*/
}