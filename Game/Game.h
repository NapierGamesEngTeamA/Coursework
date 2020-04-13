#pragma once
#include "Scene.h"
#include <list>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> introScene;
extern shared_ptr<Scene> setScene;
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
	Text Controls;
	Text Settings; 
	Text gtitle;

};



class IntroScene : public Scene
{
private:
	Texture texture;
	Sprite sprite;
	View view;
	Text play;
	Font font;

public:
	IntroScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};

class SetScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture Controlsmenu;
	Sprite sControlsmenu;

public:
	SetScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};



class OverworldScene : public Scene
{
private:
	int index;
	Texture texture;
	Texture ptexture;
	Sprite sprite;
	Sprite psprite;
	Texture e2;
	Sprite e2sprt;
	Text play;
	Text tile;
	Text quit;
	Font font;
	Sprite outline;
	Texture hbar;
	Sprite hbarsprite;
	bool Paused = false;


	Texture* tileSheet = new Texture();

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