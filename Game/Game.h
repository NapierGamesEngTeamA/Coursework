#pragma once
#include "Scene.h"

using namespace std;
using namespace sf;

extern shared_ptr<Scene> titleScene;
extern shared_ptr<Scene> overworldScene;
extern shared_ptr<Scene> activeScene;

class TitleScene : public Scene
{
private:

public:
	TitleScene() { }
	void Update(Time dt) override;
	void Render() override;
	void Load() override;
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