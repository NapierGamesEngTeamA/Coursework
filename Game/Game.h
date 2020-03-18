#pragma once
#include "Scene.h"
#include <list>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> overworldScene;
extern shared_ptr<Scene> combatScene;
extern shared_ptr<Scene> activeScene;
extern sf::Texture spritesheet;

class TitleScene : public Scene
{

public:
	void Update(Time dt) override;
	void Render() override;
	void Load() override;

private:
	Music titleMusic;
	//SoundBuffer buffer;
	//Sound s;
	int index;
	View view;
	Sprite sprite;
	Sprite outline;
	Texture texture;
	Texture ButtonOutline;
	Font font;
	Font gtitlefont;
	Text play;
	Text quit;
	Text gtitle;
};

class OverworldScene : public Scene
{
private:
	Texture texture;
	Sprite sprite;
	Texture e2;
	Sprite e2sprt;

	Texture hbar;
	Sprite hbarsprite;
	
public:
	OverworldScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};

class CombatScene : public Scene
{
private:

public:
	CombatScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
	void Setup();
};