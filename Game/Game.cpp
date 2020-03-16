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
#include "InputManager.h"
#include "AudioManager.h"
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>


#pragma endregion

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> overworldScene;
shared_ptr<Scene> combatScene;
shared_ptr<Scene> activeScene;

void Scene::Load()
{

}

void Scene::Update(Time dt) 
{
	//Update all entities in scene
	_ents.Update(dt); 
}

void Scene::Render() 
{ 
	//Render all entities in scene
	_ents.Render(); 
}


//////////////////////// TITLE SCENE ///////////////////////////////
void TitleScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

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
	play.setPosition(size.x / 2, size.y / 4.0);

	quit.setFont(font);
	quit.setCharacterSize(200);
	quit.setString("Quit");
	quit.setColor(color.Red);

	const auto textRect2 = quit.getGlobalBounds();
	quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	quit.setPosition(size.x / 2, size.y / 2);

	ButtonOutline.loadFromFile("Res/Fonts/Outline.png");
	Vector2u Outsize = ButtonOutline.getSize();
	outline.setTexture(ButtonOutline);
	outline.setOrigin(textRect.width * .5f, textRect.height * .5f);
	outline.setPosition(size.x / 2.25, size.y / 6);
	
	/*buffer.loadFromFile("Res/Music/MenuMusic.wav");
	s.setBuffer(buffer);
	s.play();*/
	//Music titleMusic;
	if (!titleMusic.openFromFile("Res/Music/MenuMusic.wav"))
	{
		cout << "Can't load title music" << endl;
	}
	titleMusic.setVolume(50);
	titleMusic.setLoop(true);
	titleMusic.play();
}

void TitleScene::Update(Time dt)
{
	
	Vector2u size = texture.getSize();
	Color col;
	RenderWindow window;

	//Move cursor
	if (InputManager::GetInstance()->Up())
	{
		index = 0;
		outline.setPosition(Vector2f(size.x / 2.25, size.y / 6));

	}
	else if (InputManager::GetInstance()->Down())
	{
		index = 1;
		outline.setPosition(Vector2f(size.x / 2.25, size.y / 2.6));
	}

	if (InputManager::GetInstance()->Interact() && index == 0)
	{	

			activeScene = overworldScene;
			printf("Scene Changed!");		
	}

	if (InputManager::GetInstance()->Interact() && index == 1)
	{
		Renderer::GetWindow().close();
	}

	Renderer::GetWindow().setView(view);
	InputManager::GetInstance()->Update();

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
	
	auto ch = make_shared<Character>();

	texture.loadFromFile("Res/Fonts/HealthBar.png");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);


	Texture* tileSheet = new Texture();
	tileSheet->loadFromFile("Res/Sprites/A2_Ground.png");
	auto tm = make_shared<TileMap>();
	tm->GenerateMap("Res/Maps/TestLevel.txt", *tileSheet, ch);

	_ents.list.push_back(tm);



	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/TstSprt.png");


	auto pmc = ch->AddComponent<PlayerMovementComponent>();

	//Add Camera
	auto cam = ch->AddComponent<Camera>();
	//cam->SetWindow();

	////////////////// Set animations /////////////////////////////////
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
	//////////////////////////////////////////////////////////////////////////

	ch->SetPosition(Vector2f(2000, 600));

	_ents.list.push_back(ch);
}

void OverworldScene::Update(Time dt)
{


	//Debug: Back to menu
	if (InputManager::Back())
	{
		activeScene = titleScene;
		printf("Scene Changed!");
	}

	if (InputManager::Up() || InputManager::Down() || InputManager::Right() || InputManager::Left())
	{
		int d100 = rand() % 100 + 1;
		if (d100 > 80)
		{
			//activeScene = combatScene;
			printf("Scene: Combat Scene");
		}
	}

	InputManager::GetInstance()->Update();

	Scene::Update(dt);
}

void OverworldScene::Render()
{
	//Renderer::GetWindow().setView();


	Scene::Render();
	sf::Texture::bind(&texture);
	Renderer::Queue(&sprite);
	sf::Texture::bind(NULL);
}
///////////////////////////////////////////////////////////////

//////////////////// Combat Scene /////////////////////////////
void CombatScene::Load()
{

}

void CombatScene::Update(Time dt)
{
	Scene::Update(dt);
}

void CombatScene::Render()
{
	Scene::Render();
}

void CombatScene::Setup()
{

}
