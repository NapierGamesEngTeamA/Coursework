#pragma once
#include "Scene.h"
#include <list>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> introScene;
extern shared_ptr<Scene> contScene;
extern shared_ptr<Scene> setScene;
extern shared_ptr<Scene> htpScene;
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
	RectangleShape fade;

public:
	IntroScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};



class ContScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture Controlsmenu;
	Sprite sControlsmenu;

	Texture HTPmenu;
	Sprite sHTPmenu;

public:
	ContScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};



class SetScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture Settingsmenu;
	Sprite sSettingsmenu;

public:
	SetScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};

class HTPScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture htpsmenu;
	Sprite shtpsmenu;

public:
	HTPScene() = default;
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
	Texture HH;
	Sprite sHH;
	Sprite sprite[5];
	Sprite psprite;
	Texture e2;
	Sprite e2sprt[5];
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