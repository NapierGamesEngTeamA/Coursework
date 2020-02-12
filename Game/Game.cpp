#include <SFML/Graphics.hpp>
#include <iostream>
#include "SystemRenderer.h"
#include "ecm.h"
#include "Scene.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Character.h"
#include "PlayerMovementComponent.h"
#include "AnimatedSpriteComponent.h"

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> overworldScene;
shared_ptr<Scene> activeScene;

void Scene::Load()
{

}

void Scene::Update(double dt) 
{ 
	_ents.Update(dt); 
}

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
	auto ch = make_shared<Character>();
	//auto s = ch->AddComponent<SpriteComponent>();
	//s->GetSprite().setTexture(*texture);
	//s->GetSprite().setTextureRect(IntRect(0, 0, 26, 35));	

	auto pmc = ch->AddComponent<PlayerMovementComponent>();

	Animation* su = new Animation();
	su->SetSpriteSheet(*texture);
	su->AddFrame(IntRect(31, 0, 30, 33));
	ch->_anims.insert(pair<string, Animation>("Stand Up", *su));

	Animation* sd = new Animation();
	sd->SetSpriteSheet(*texture);
	sd->AddFrame(IntRect(31, 72, 30, 33));
	ch->_anims.insert(pair<string, Animation>("Stand Down", *sd));

	Animation* sr = new Animation();
	sr->SetSpriteSheet(*texture);
	sr->AddFrame(IntRect(31, 36, 30, 33));
	ch->_anims.insert(pair<string, Animation>("Stand Right", *sr));

	Animation* sl = new Animation();
	sl->SetSpriteSheet(*texture);
	sl->AddFrame(IntRect(31, 108, 30, 33));
	ch->_anims.insert(pair<string, Animation>("Stand Left", *sl));

	Animation* wu = new Animation();
	wu->SetSpriteSheet(*texture);
	wu->AddFrame(IntRect(0, 0, 30, 35));
	wu->AddFrame(IntRect(64, 0, 30, 35));
	ch->_anims.insert(pair<string, Animation>("Walk Up", *wu));

	Animation* wr = new Animation();
	wr->SetSpriteSheet(*texture);
	wr->AddFrame(IntRect(0, 38, 30, 35));
	wr->AddFrame(IntRect(68, 38, 30, 35));
	ch->_anims.insert(pair<string, Animation>("Walk Right", *wr));

	Animation* wd = new Animation();
	wd->SetSpriteSheet(*texture);
	wd->AddFrame(IntRect(0, 74, 30, 35));
	wd->AddFrame(IntRect(64, 74, 30, 35));
	ch->_anims.insert(pair<string, Animation>("Walk Down", *wd));

	Animation* wl = new Animation();
	wl->SetSpriteSheet(*texture);
	wl->AddFrame(IntRect(0, 110, 30, 35));
	wl->AddFrame(IntRect(64, 110, 30, 35));
	ch->_anims.insert(pair<string, Animation>("Walk Left", *wl));

	auto as = ch->AddComponent<AnimatedSpriteComponent>();
	as->SetAnimation(*sl);
	as->Play();

	ch->SetPosition(Vector2f(100, 100));

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
