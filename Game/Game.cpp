#include <SFML/Graphics.hpp>
#include <iostream>
#include "SystemRenderer.h"
#include "ecm.h"
#include "Scene.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Character.h"
#include "PlayerMovementComponent.h"

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
	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/TestSprites.png");
	auto ch = make_shared<Entity>();
	auto s = ch->AddComponent<SpriteComponent>();
	s->GetSprite().setTexture(*texture);
	s->GetSprite().setTextureRect(IntRect(0, 0, 26, 35));
	ch->SetPosition(Vector2f(100, 100));
	auto pmc = ch->AddComponent<PlayerMovementComponent>();

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
