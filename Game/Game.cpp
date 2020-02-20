#pragma region INCLUDES

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
#include "TileMap.h"
#include "Tile.h"
#include "Camera.h"

#pragma endregion

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> overworldScene;
shared_ptr<Scene> activeScene;

void Scene::Load()
{

}

void Scene::Update(Time dt) 
{ 
	_ents.Update(dt); 
}

void Scene::Render() { _ents.Render(); }


//////////////////////// TITLE SCENE ///////////////////////////////



void TitleScene::Load()
{
	Color color;

	texture.loadFromFile("Res/Fonts/MenuBack.jpg");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 200, size.y / 10);

	font.loadFromFile("Res/Fonts/BreatheFire-65pg.ttf");
	play.setFont(font);
	play.setCharacterSize(200);
	play.setString("Play");
	play.setColor(color.Red);

	const auto textRect = play.getGlobalBounds();
	play.setOrigin(textRect.width * .5f, textRect.height * .5f);
	play.setPosition(size.x / 2, size.y / 2.5);

	quit.setFont(font);
	quit.setCharacterSize(200);
	quit.setString("Quit");
	quit.setColor(color.Red);

	const auto textRect2 = quit.getGlobalBounds();
	quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	quit.setPosition(size.x / 4, size.y / 2.5);

	ButtonOutline.loadFromFile("Res/Fonts/Outline.png");
	Vector2u Outsize = ButtonOutline.getSize();
	outline.setTexture(ButtonOutline);
	outline.setOrigin(textRect.width * .5f, textRect.height * .5f);
	outline.setPosition(size.x / 5, size.y / 10);



}

void TitleScene::Update(Time dt)
{
	Vector2u size = texture.getSize();
	Color col;
	RenderWindow window;

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		outline.setPosition(size.x / 5, size.y / 3.5);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		outline.setPosition(size.x / 5, size.y / 10);


	}

	if (Keyboard::isKeyPressed(Keyboard::Enter) && outline.getPosition() == Vector2f(size.x / 5, size.y / 10))
	{
	
			activeScene = overworldScene;
			printf("Scene Changed!");
		
	}


	if (Keyboard::isKeyPressed(Keyboard::Enter) && outline.getPosition() == Vector2f(size.x / 5, size.y / 3.5))
	{

		cout << "Exit";
		window.close();
		
		

	}

	Scene::Update(dt);
}

void TitleScene::Render()
{
	Scene::Render();

	sf::Texture::bind(&texture);
	sf::Texture::bind(&ButtonOutline);
	Renderer::Queue(&sprite);
	Renderer::Queue(&outline);
	sf::Texture::bind(NULL);

	Renderer::Queue(&play);
	Renderer::Queue(&quit);

}
///////////////////////////////////////////////////////////////

///////////////////////////// OVERWORLD SCENE //////////////////

void OverworldScene::Load()
{

	Texture* tileSheet = new Texture();
	tileSheet->loadFromFile("Res/Sprites/TileSheet.png");
	auto tm = make_shared<TileMap>();
	tm->GenerateMap("Res/Maps/TestLevel.txt", *tileSheet);

	//for (int y = 0; y < tm->_height; y++)
	//{
	//	for (int x = 0; x < tm->_width; x++)
	//	{
	//		auto t = tm->AddComponent<Tile>();
	//		//t->SetTexture(*tileSheet);
	//		t->GetSprite().setTexture(*tileSheet);
	//		t->SetRect(IntRect(324, 137, 16, 16));
	//		t->SetPosition(Vector2f(x * 16, y * 16));
	//	}
	//}

	_ents.list.push_back(tm);

	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/TestSprites.png");
	auto ch = make_shared<Character>();
	//auto s = ch->AddComponent<SpriteComponent>();
	//s->GetSprite().setTexture(*texture);
	//s->GetSprite().setTextureRect(IntRect(0, 0, 26, 35));	

	auto pmc = ch->AddComponent<PlayerMovementComponent>();

	//Add Camera
	auto cam = ch->AddComponent<Camera>();
	//cam->SetWindow();

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
	wr->AddFrame(IntRect(0, 38, 28, 33));
	//wr->AddFrame(IntRect(36, 36, 24, 36));
	wr->AddFrame(IntRect(69, 38, 24, 33));
	ch->_anims.insert(pair<string, Animation>("Walk Right", *wr));

	Animation* wd = new Animation();
	wd->SetSpriteSheet(*texture);
	wd->AddFrame(IntRect(0, 74, 30, 35));
	wd->AddFrame(IntRect(64, 74, 30, 35));
	ch->_anims.insert(pair<string, Animation>("Walk Down", *wd));

	Animation* wl = new Animation();
	wl->SetSpriteSheet(*texture);
	wl->AddFrame(IntRect(0, 110, 28, 33));
	wl->AddFrame(IntRect(64, 110, 28, 33));
	ch->_anims.insert(pair<string, Animation>("Walk Left", *wl));

	auto as = ch->AddComponent<AnimatedSpriteComponent>();
	as->SetAnimation(*sl);
	as->Play();

	ch->SetPosition(Vector2f(100, 100));


	_ents.list.push_back(ch);
}

void OverworldScene::Update(Time dt)
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
	//Renderer::GetWindow().setView();
	
	Scene::Render();
}
///////////////////////////////////////////////////////////////
