#include <SFML/Graphics.hpp>
#include <iostream>
#include "SystemRenderer.h"
#include "ecm.h"
#include "Scene.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Character.h"

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> overworldScene;
shared_ptr<Scene> activeScene;

void Scene::Load()
{

}

void Scene::Update(double dt) { _ents.Update(dt); }

void Scene::Render() { _ents.Render(); }


//////////////////////// TITLE SCENE ///////////////////////////////
void TitleScene::Load()
{

}

void TitleScene::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		activeScene = overworldScene;
		printf("Scene Changed!");
	}

	Scene::Update(dt);
}

void TitleScene::Render()
{
	Scene::Render();
}
///////////////////////////////////////////////////////////////

///////////////////////////// OVERWORLD SCENE //////////////////

void OverworldScene::Load()
{
	Texture texture;
	texture.loadFromFile("Res/Sprites/TestSprites.png");
	auto ch = make_shared<Entity>();
	auto s = ch->AddComponent<SpriteComponent>();
	printf("");
	s->SetTexture(texture);
	s->SetRect(IntRect(0, 0, 26, 35));
	ch->SetPosition(Vector2f(1080/2, 1920/2));
	_ents.list.push_back(ch);
	
}

void OverworldScene::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		activeScene = titleScene;
		printf("Scene Changed!");
	}
	Scene::Update(dt);
}

void OverworldScene::Render()
{
	Scene::Render();
}
///////////////////////////////////////////////////////////////
