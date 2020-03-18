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
#include "Enemy.h"
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

	texture.loadFromFile("Res/Fonts/Background.png");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 200, size.y / 10);


	gtitlefont.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	gtitle.setFont(font);
	gtitle.setCharacterSize(100);
	gtitle.setString("Fantasy & Ash");
	gtitle.setColor(color.Yellow);
	gtitle.setOutlineColor(color.Black);
	gtitle.setOutlineThickness(6);

	const auto textRecta = gtitle.getGlobalBounds();
	gtitle.setOrigin(textRecta.width * .5f, textRecta.height * .5f);
	gtitle.setPosition(size.x /4, size.y/12);

	play.setColor(color.White);
	font.loadFromFile("Res/Fonts/SuperLegendBoy-4w8Y.ttf");
	play.setFont(font);
	play.setCharacterSize(100);
	play.setString("Play");
	play.setColor(color.White);
	play.setOutlineColor(color.Yellow);
	play.setOutlineThickness(4);

	const auto textRect = play.getGlobalBounds();
	play.setOrigin(textRect.width * .5f, textRect.height * .5f);
	play.setPosition(size.x / 2, size.y / 3.2);

	quit.setFont(font);
	quit.setCharacterSize(100);
	quit.setString("Quit");
	quit.setColor(color.Red);

	const auto textRect2 = quit.getGlobalBounds();
	quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	quit.setPosition(size.x / 2, size.y / 2);

	ButtonOutline.loadFromFile("Res/Fonts/Outline.png");
	Vector2u Outsize = ButtonOutline.getSize();
	outline.setTexture(ButtonOutline);
	outline.setOrigin(textRect.width * .5f, textRect.height * .5f);
	outline.setPosition(size.x / 2.38, size.y / 6);
	
	/*buffer.loadFromFile("Res/Music/MenuMusic.wav");
	s.setBuffer(buffer);
	s.play();*/
	//Music titleMusic;
	if (!titleMusic.openFromFile("Res/Music/MenuMusic.mp3"))
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
		outline.setPosition(size.x / 2.38, size.y / 6);
		play.setColor(col.White);
		quit.setColor(col.Red);
		play.setOutlineColor(col.Yellow);
		play.setOutlineThickness(4);
		quit.setOutlineThickness(0);
	}
	else if (InputManager::GetInstance()->Down())
	{
		index = 1;
		outline.setPosition(Vector2f(size.x / 2.38, size.y / 2.6));
		play.setColor(col.Red);
		quit.setColor(col.White);
		quit.setOutlineColor(col.Yellow);
		quit.setOutlineThickness(4);
		play.setOutlineThickness(0);
	}


	if (InputManager::GetInstance()->Interact() && index == 0)
	{	

			activeScene = overworldScene;
			//printf("Scene Changed!");		
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
	Renderer::Queue(&gtitle);

}
///////////////////////////////////////////////////////////////

///////////////////////////// OVERWORLD SCENE //////////////////

void OverworldScene::Load()
{
	
	//if (!spritesheet.loadFromFile("Res/Sprites/Orc.png"))
	//{
	//	cerr << "Failed to load spritesheet!" << endl;
	//}

	


	auto ch = make_shared<Character>();


	texture.loadFromFile("Res/Sprites/Orc.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(16, 145, 37, 51));
	const auto textRect = sprite.getGlobalBounds();
	sprite.setOrigin(textRect.width * .5f, textRect.height * .5f);
	sprite.setPosition(2000, 300);

	e2.loadFromFile("Res/Sprites/Skeleton.png");
	e2sprt.setTexture(e2);
	e2sprt.setTextureRect(IntRect(16, 145, 37, 51));
	const auto textRect2 = sprite.getGlobalBounds();
	e2sprt.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	e2sprt.setPosition(1800, 300);

	
	hbar.loadFromFile("Res/Fonts/HealthBar.png");
	hbarsprite.setTexture(texture);
	sprite.setOrigin(0, 0);


	Texture* tileSheet = new Texture();
	tileSheet->loadFromFile("Res/Sprites/A2_Ground.png");
	auto tm = make_shared<TileMap>();
	tm->GenerateMap("Res/Maps/TestLevel.txt", *tileSheet, ch);
	

	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/Main.png");

	auto pmc = ch->AddComponent<PlayerMovementComponent>();

	//Add Camera
	auto cam = ch->AddComponent<Camera>();
	//cam->SetWindow();

	////////////////// Set animations /////////////////////////////////
	Animation* su = new Animation();
	su->SetSpriteSheet(*texture);
	su->AddFrame(IntRect(17, 17, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Stand Up", *su));

	Animation* sd = new Animation();
	sd->SetSpriteSheet(*texture);
	sd->AddFrame(IntRect(17, 397, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Stand Down", *sd));

	Animation* sr = new Animation();
	sr->SetSpriteSheet(*texture);
	sr->AddFrame(IntRect(19, 206, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Stand Right", *sr));

	Animation* sl = new Animation();
	sl->SetSpriteSheet(*texture);
	sl->AddFrame(IntRect(19, 334, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Stand Left", *sl));

	Animation* wu = new Animation();
	wu->SetSpriteSheet(*texture);
	wu->AddFrame(IntRect(145, 524, 30, 51));
	wu->AddFrame(IntRect(400, 524, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Walk Up", *wu));

	Animation* wr = new Animation();
	wr->SetSpriteSheet(*texture);
	wr->AddFrame(IntRect(84, 717, 30, 51));
	wr->AddFrame(IntRect(335, 717, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Walk Right", *wr));

	Animation* wd = new Animation();
	wd->SetSpriteSheet(*texture);
	wd->AddFrame(IntRect(145, 652, 30, 51));
	wd->AddFrame(IntRect(400, 652, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Walk Down", *wd));

	Animation* wl = new Animation();
	wl->SetSpriteSheet(*texture);
	wl->AddFrame(IntRect(82, 589, 30, 51));
	wl->AddFrame(IntRect(340, 589, 30, 51));
	ch->_anims.insert(pair<string, Animation>("Walk Left", *wl));

	auto as = ch->AddComponent<AnimatedSpriteComponent>();
	as->SetAnimation(*sl);
	as->Play();
	//////////////////////////////////////////////////////////////////////////

	//ch->SetPosition(Vector2f(2000, 600));


	_ents.list.push_back(tm);
	_ents.list.push_back(ch);

}


void OverworldScene::Update(Time dt)
{


	//Debug: Back to menu
	if (InputManager::Back())
	{
		activeScene = titleScene;
		//printf("Scene Changed!");
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
	sf::Texture::bind(&e2);
	Renderer::Queue(&e2sprt);
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
