#pragma once
#include "Scene.h"
#include <list>
#include <SFML/Audio.hpp>
#include <functional>
#include "BattleEntity.h"
#include "BattleManager.h"
#include "LoadManager.h"

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> introScene;
extern shared_ptr<Scene> contScene;
extern shared_ptr<Scene> setScene;
extern shared_ptr<Scene> htpScene;
extern shared_ptr<Scene> overworldScene;
extern shared_ptr<Scene> combatScene;
extern shared_ptr<Scene> winScene;
extern shared_ptr<Scene> loseScene;
extern shared_ptr<Scene> activeScene;
extern sf::Texture spritesheet;
extern int EnemyType;
extern int GoldCount;
extern bool HasHealed;
extern vector<shared_ptr<BattleEntity>> party;
extern int EnemyLevel;
extern bool IsReset;
extern bool IsLoaded;

class TitleScene : public Scene
{

public:
	void Update(Time dt) override;
	void Render() override;
	void Load() override;

private:
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

	Color color;
	Text play;
	Text play2;
	Font font;

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

	Text winsize[3];
	Font font;

	Color color;

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


	Color color;
	Text play;
	Text play2;
	Font font;
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
	BattleManager battleManager;
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
	Text heal;
	Text h1[5];
	Font font;
	Sprite outline;
	Texture hbar;
	Sprite hbarsprite;
	bool Paused = false;
	Color color;
	

	Texture* tileSheet = new Texture();

public:
	OverworldScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
	void Reset();
};

class CombatScene : public Scene
{
private:
	Texture bgTex;
	Sprite background;
	Music battleMusic;
	int turn = 1;
	Font font;
	Text statText;
	Text menuText[3];
	Text enemyText[4];
	RectangleShape canvas;
	BattleManager battleManager;
	View view;
	Color color;
public:
	CombatScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
	typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
	Comparator compFunction = [](pair<string, int> elm1, pair<string, int> elm2)
	{
		return elm1.second < elm2.second;
	};
};

class WinScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture Win;
	Sprite sWin;

public:
	WinScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};


class LoseScene : public Scene
{
private:
	Sprite sprite;
	View view;

	Texture Lose;
	Sprite sLose;
	Font font;
	Text text;
	Color color;
public:
	LoseScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};

