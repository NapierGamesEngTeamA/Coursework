#pragma once
#include "Scene.h"
#include <list>

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> overworldScene;
extern shared_ptr<Scene> activeScene;

class TitleScene : public Scene
{

public:
	void Update(Time dt) override;
	void Render() override;
	void Load() override;

private:
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

public:
	OverworldScene() = default;
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
};