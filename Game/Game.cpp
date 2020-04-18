#pragma region INCLUDES

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
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
#include "BattleEntity.h"
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

#pragma region TitleScene
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
	
	//Music titleMusic;
	if (!titleMusic.openFromFile("Res/Music/MenuMusic.wav"))
	{
		cout << "Can't load title music" << endl;
	}
	titleMusic.setVolume(50);
	titleMusic.setLoop(true);
	//titleMusic.play();
}

void TitleScene::Update(Time dt)
{
	
	Vector2u size = texture.getSize();
	Color col;
	RenderWindow window;

	//Move cursor
	if (InputManager::GetInstance()->Up(true))
	{
		index = 0;
		outline.setPosition(Vector2f(size.x / 2.25, size.y / 6));

	}
	else if (InputManager::GetInstance()->Down(true))
	{
		index = 1;
		outline.setPosition(Vector2f(size.x / 2.25, size.y / 2.6));
	}

	if (InputManager::GetInstance()->Interact(true) && index == 0)
	{	

			activeScene = overworldScene;
			printf("Scene Changed!");		
	}

	if (InputManager::GetInstance()->Interact(true) && index == 1)
	{
		Renderer::GetWindow().close();
	}

	Renderer::GetWindow().setView(view);

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
#pragma endregion

#pragma region OverworldScene
///////////////////////////// OVERWORLD SCENE //////////////////
void OverworldScene::Load()
{
	

	texture.loadFromFile("Res/Fonts/HealthBar.png");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);


	Texture* tileSheet = new Texture();
	tileSheet->loadFromFile("Res/Sprites/A2_Ground.png");
	auto tm = make_shared<TileMap>();
	tm->GenerateMap("Res/Maps/TestLevel.txt", *tileSheet);

	_ents.list.push_back(tm);



	Texture* texture = new Texture();
	texture->loadFromFile("Res/Sprites/TstSprt.png");
	auto ch = make_shared<Character>();

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
	if (InputManager::Back(true))
	{
		activeScene = titleScene;
		printf("Scene Changed!");
	}

	if (InputManager::Up(false) || InputManager::Down(false) || InputManager::Right(false) || InputManager::Left(false))
	{
		int d100 = rand() % 100 + 1;
		if (d100 > 80)
		{
			//activeScene = combatScene;
			printf("Scene: Combat Scene");
		}
	}

	
	

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
#pragma endregion

//////////////////// Combat Scene /////////////////////////////
void CombatScene::Load()
{
	bgTex.loadFromFile("Res/Sprites/CombatBackground.jpg");
	//Vector2u size = texture.getSize();
	background.setTexture(bgTex);
	background.setOrigin(0, 0);	

	font.loadFromFile("Res/Fonts/BreatheFire-65pg.ttf");

	//Set starting party stats

	//Add text menu
	canvas.setSize(Vector2f(500, 1080));
	canvas.setPosition(Vector2f(0, 0));
	canvas.setFillColor(Color(0, 0, 255, 255/2));

	statText.setFont(font);
	statText.setColor(Color::White);
	statText.setCharacterSize(36);
	statText.setPosition(Vector2f(50, 500));
	statText.setString(" ");
	
	menuText.setFont(font);
	menuText.setColor(Color::White);
	menuText.setCharacterSize(36);
	menuText.setPosition(Vector2f(50, 100));
	menuText.setString("A:Attack       S:Magic\nD:Flee");

	//Add health 

	if (!battleMusic.openFromFile("Res/Music/BattleMusic.wav"))
	{
		cout << "Can't load title music" << endl;
	}
	battleMusic.setVolume(1);
	battleMusic.setLoop(true);
	battleMusic.play();

	battleManager.Load();

	

}

void CombatScene::Update(Time dt)
{
	battleManager.Update(dt);

	Scene::Update(dt);
}

void CombatScene::Render()
{
	vector<shared_ptr<BattleEntity>> e = battleManager.GetEnts();

	string s = e[0]->GetHealthText() + "\n" + 
		e[1]->GetHealthText() + "\n" +
		e[2]->GetHealthText() + "\n" +
		e[3]->GetHealthText();

	statText.setString(s);
	
	
	Renderer::Queue(&background);
	Renderer::Queue(&canvas);
	Renderer::Queue(&statText);
	Renderer::Queue(&menuText);
	battleManager.Render();
	Scene::Render();


}

void CombatScene::LoadEnemies()
{
	vector<int> stats[4];

	stats[1].push_back(1); //Strength
	stats[1].push_back(2); //Dexterity
	stats[1].push_back(4); //Intellect
	stats[1].push_back(3); //Constitution
	stats[1].push_back(10); //Health
	stats[1].push_back(10); //MP


	//Texture* skeTexture = new Texture();
	//skeTexture->loadFromFile("Res/Sprite/Skeleton.png");

	//auto skeleton = make_shared<BattleEntity>();
	//skeleton->Setup(stats[1], "Skeleton");
	//Animation* idle2 = new Animation();
	//idle2->SetSpriteSheet(*skeTexture);
	//idle2->AddFrame(IntRect(22, 340, 21, 48));
	//idle2->AddFrame(IntRect(83, 340, 21, 48));
	//skeleton->_anims.insert(pair<string, Animation>("Idle", *idle2));
	//auto a = skeleton->AddComponent<AnimatedSpriteComponent>();
	//a->SetAnimation(*idle);
	//a->Play();
	//skeleton->SetPosition(Vector2f(900, 500));
	//enemies.insert(pair<string, shared_ptr<BattleEntity>>("Skeleton", skeleton));
}

void CombatScene::Flee()
{
	activeScene = overworldScene;
}
