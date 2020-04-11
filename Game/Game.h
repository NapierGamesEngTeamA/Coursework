#pragma once
#include "Scene.h"
#include <list>
#include <SFML/Audio.hpp>
#include <functional>

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> overworldScene;
extern shared_ptr<Scene> combatScene;
extern shared_ptr<Scene> activeScene;

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
	Text play;
	Text quit;
};

class OverworldScene : public Scene
{
private:
	Texture texture;
	Sprite sprite;
	
public:
	OverworldScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};

class CombatScene : public Scene
{
private:
	enum BattleState { Start, Combat, End };
	enum Turns { PlayerTurn, EnemyTurn };
	BattleState currentBS;
	Turns currentTurn;
	Texture bgTex;
	Sprite background;
	Music battleMusic;
	map<string, int> battleOrder;
	int turn = 1;
	Font font;
	Text statText;
	Text menuText;
	RectangleShape canvas;
	RectangleShape selector;
	Vector2f index = Vector2f(0, 0);
public:
	CombatScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
	void Setup();
	int ManageMenu();
	typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
	Comparator compFunction = [](pair<string, int> elm1, pair<string, int> elm2)
	{
		return elm1.second < elm2.second;
	};
};