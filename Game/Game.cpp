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
#include <random>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>


#pragma endregion

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> introScene;
shared_ptr<Scene> setScene;
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
	play.setPosition(size.x / 2, size.y / 4.2);

	quit.setFont(font);
	quit.setCharacterSize(100);
	quit.setString("Quit");
	quit.setColor(color.Red);

	const auto textRect2 = quit.getGlobalBounds();
	quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	quit.setPosition(size.x / 3.2, size.y / 2.5);

	ButtonOutline.loadFromFile("Res/Fonts/Outline.png");
	Vector2u Outsize = ButtonOutline.getSize();
	outline.setTexture(ButtonOutline);
	outline.setOrigin(textRect.width * .5f, textRect.height * .5f);
	outline.setPosition(size.x / 2.38, size.y / 7);
	

	Controls.setFont(font);
	Controls.setCharacterSize(60);
	Controls.setString("Controls");
	Controls.setColor(color.Red);

	const auto textRect3 = Controls.getGlobalBounds();
	Controls.setOrigin(textRect3.width * .5f, textRect3.height * .5f);
	Controls.setPosition(size.x / 1.5, size.y / 2.5);

	Settings.setFont(font);
	Settings.setCharacterSize(60);
	Settings.setString("Settings");
	Settings.setColor(color.Red);

	const auto textRect4 = Settings.getGlobalBounds();
	Settings.setOrigin(textRect4.width * .5f, textRect4.height * .5f);
	Settings.setPosition(size.x / 2, size.y / 1.8);




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
			outline.setPosition(size.x / 2.38, size.y / 7);
			play.setColor(col.White);
			quit.setColor(col.Red);
			Controls.setColor(col.Red);
			Settings.setColor(col.Red);
			play.setOutlineColor(col.Yellow);
			play.setOutlineThickness(4);
			quit.setOutlineThickness(0);
			Controls.setOutlineThickness(0);
			Settings.setOutlineThickness(0);
		}
		else if (InputManager::GetInstance()->Left())
		{
			index = 1;
			outline.setPosition(Vector2f(size.x / 4.38, size.y / 3.6));
			play.setColor(col.Red);
			Controls.setColor(col.Red);
			Settings.setColor(col.Red);
			quit.setColor(col.White);
			quit.setOutlineColor(col.Yellow);
			quit.setOutlineThickness(4);
			play.setOutlineThickness(0);
			Controls.setOutlineThickness(0);
			Settings.setOutlineThickness(0);
		}
		else if (InputManager::GetInstance()->Right())
		{
			index = 2;
			outline.setPosition(Vector2f(size.x / 1.70, size.y / 3.6));
			play.setColor(col.Red);
			quit.setColor(col.Red);
			Settings.setOutlineColor(col.Red);
			Controls.setColor(col.White);
			Controls.setOutlineColor(col.Yellow);
			Controls.setOutlineThickness(4);
			play.setOutlineThickness(0);
			quit.setOutlineThickness(0);
			Settings.setOutlineThickness(0);
		}

		else if (InputManager::GetInstance()->Down())
		{
			index = 2;
			outline.setPosition(Vector2f(size.x / 2.38, size.y / 2.3));
			play.setColor(col.Red);
			quit.setColor(col.Red);
			Controls.setColor(col.Red);
			Settings.setColor(col.White);
			Settings.setOutlineColor(col.Yellow);
			Settings.setOutlineThickness(4);
			play.setOutlineThickness(0);
			quit.setOutlineThickness(0);
			Controls.setOutlineThickness(0);
		}

	
		if (InputManager::GetInstance()->Interact() && index == 0)
		{

			activeScene = introScene;
			//printf("Scene Changed!");		
		}

		if (InputManager::GetInstance()->Interact() && index == 1)
		{
			Renderer::GetWindow().close();
		}

		if (InputManager::GetInstance()->Interact() && index == 2)
		{
			activeScene = setScene;
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

		sf::Texture::bind(NULL);

		Renderer::Queue(&play);
		Renderer::Queue(&quit);
		Renderer::Queue(&Controls);
		Renderer::Queue(&Settings);
		Renderer::Queue(&gtitle);
		Renderer::Queue(&outline);



}


void IntroScene::Load()
{
	Color color;

	view.reset(FloatRect(0, 0, 1920, 1080));
	texture.loadFromFile("Res/Sprites/IntroScene.png");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 200, size.y / 10);

	play.setColor(color.White);
	font.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	play.setFont(font);
	play.setCharacterSize(60);
	play.setString("Press 'W' To Continue");
	play.setColor(color.White);
	play.setOutlineColor(color.Black);
	play.setOutlineThickness(4);

	const auto textRect = play.getGlobalBounds();
	play.setOrigin(textRect.width * .5f, textRect.height * .5f);
	play.setPosition(size.x / 6.2, size.y / 6.2);



}
void IntroScene::Update(Time dt)
{

	if (InputManager::GetInstance()->Up())
	{

		activeScene = overworldScene;
		//printf("Scene Changed!");		
	}

	Scene::Update(dt);
}

void IntroScene::Render()
{
	Scene::Render();
	sf::Texture::bind(&texture);
	Renderer::Queue(&sprite);
	Renderer::Queue(&play);
	sf::Texture::bind(NULL);
}



void SetScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

	Controlsmenu.loadFromFile("Res/Sprites/Controls.png");
	Vector2u size = Controlsmenu.getSize();
	sControlsmenu.setTexture(Controlsmenu);
	sControlsmenu.setOrigin(size.x / 200, size.y / 10);
}

void SetScene::Update(Time dt)
{
	if (InputManager::GetInstance()->Up())
	{

		activeScene = titleScene;
		//printf("Scene Changed!");		
	}
}

void SetScene::Render()
{
	Scene::Render();
	sf::Texture::bind(&Controlsmenu);
	Renderer::Queue(&sControlsmenu);
	sf::Texture::bind(NULL);
}
///////////////////////////////////////////////////////////////

///////////////////////////// OVERWORLD SCENE //////////////////

void OverworldScene::Load()
{
	
	//if (!spritesheet.loadFromFile("Res/Sprites/Orc.png"))
	//{
	//	cerr << "Failed to load spritesheet!" << endl;
	//}

	//
	//hbar.loadFromFile("Res/Sprites/HealthBar.png");
	//hbarsprite.setTexture(hbar);
	//Vector2u size = hbar.getSize();
	//hbarsprite.setOrigin(size.x * .5f, size.y * .5f);



	HH.loadFromFile("Res/Sprites/HealthHouse.png");
	sHH.setTexture(HH);
	Vector2u size = HH.getSize();
	sHH.setOrigin(size.x * .5f, size.y * .5f);
	sHH.setPosition(4000, 2600);



	auto ch = make_shared<Character>();

	
	float x = rand() % 100 + 4000;
	float y = rand() % 100 + 960;

//	int Random = Randomizer::Random(0, 100);


	float offset = 0.0f;

	float offsety = 0.0f;
	//float y = 0.0f;
	for (int i = 0; i < 5; i++)
	{
		offset = offset + 100;
		offsety = offsety + 40;

		e2.loadFromFile("Res/Sprites/Skeleton.png");
		e2sprt[i].setTexture(e2);
		e2sprt[i].setTextureRect(IntRect(16, 145, 37, 51));
		const auto textRect2 = e2sprt[i].getGlobalBounds();
		e2sprt[i].setOrigin(textRect2.width * .5f, textRect2.height * .5f);
		e2sprt[i].setPosition((rand() % 2000 + 3000) + offset, (rand() % 300 + 300) + offsety);

		texture.loadFromFile("Res/Sprites/Orc.png");
		sprite[i].setTexture(texture);
		sprite[i].setTextureRect(IntRect(16, 145, 37, 51));
		const auto textRect = sprite[i].getGlobalBounds();
		sprite[i].setOrigin(textRect.width * .5f, textRect.height * .5f);
		sprite[i].setPosition((rand() % 2000 + 4000) , (rand() % 1000 + 1500) );

		if (e2sprt[i].getPosition() == e2sprt[i + 1].getPosition())
		{
			e2sprt[i].setPosition(e2sprt[i].getPosition().x + 30, e2sprt[i].getPosition().y + 30);
		}

	}


	

	

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
	Color color;
	
	

	auto s = _ents.GetEntitys<TileMap>();
	auto c = _ents.GetEntitys<Character>();
	auto s2 = c[0]->GetComponents<Camera>();

	if (Paused == false)
	{

		//hbarsprite.setPosition(s2[0]->GetView().getViewport().getPosition().x, s2[0]->GetView().getViewport().getPosition().y);

		
		psprite.setPosition(100000000000, 10000000000000);
		play.setPosition(100000000000, 1000000000);
		quit.setPosition(100000000000, 1000000000);


		tile.setColor(color.Red);
		font.loadFromFile("Res/Fonts/SuperLegendBoy-4w8Y.ttf");
		play.setFont(font);
		tile.setCharacterSize(60);
		tile.setString("Tile : " + c[0]->tileX + c[0]->tileY);



		const auto textRect = tile.getGlobalBounds();
		tile.setOrigin(textRect.width * .5f, textRect.height * .5f);
		tile.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y);

		int bottom, top, left, right;
		bottom = sHH.getPosition().y + 260;
		left = sHH.getPosition().x;
		right = sHH.getPosition().x + 260;
		top = sHH.getPosition().y;

		if (c[0]->right < left || c[0]->left > right || c[0]->top > bottom || c[0]->bottom < top)
		{
			
		}
		else
		{
			cout << "Healing" << '\n';
		}


		s[0]->UpdateColMap(c[0], s[0]->tiles1, dt);
		//Debug: Back to menu
		if (InputManager::Start())
		{
			Paused = true;



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
	else
	{

		ptexture.loadFromFile("Res/Sprites/PauseMenu.png");
		Vector2u size = ptexture.getSize();
		psprite.setTexture(ptexture);
		psprite.setOrigin(size.x * .5f , size.y * .5f );
		psprite.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y);


		play.setColor(color.Red);
     	font.loadFromFile("Res/Fonts/SuperLegendBoy-4w8Y.ttf");
		play.setFont(font);
		play.setCharacterSize(60);
		play.setString("Continue");



		const auto textRect = play.getGlobalBounds();
		play.setOrigin(textRect.width * .5f, textRect.height * .5f);
		play.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y - 50);


		quit.setFont(font);
		quit.setCharacterSize(60);
		quit.setString("Quit");
		quit.setColor(color.Red);

		const auto textRect2 = quit.getGlobalBounds();
		quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
		quit.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y + 50);


		if (InputManager::GetInstance()->Up())
		{
			index = 0;
			outline.setPosition(size.x / 2.38, size.y / 6);
			play.setColor(color.White);
			quit.setColor(color.Red);
			play.setOutlineColor(color.Yellow);
			play.setOutlineThickness(4);
			quit.setOutlineThickness(0);
		}
		else if (InputManager::GetInstance()->Down())
		{
			index = 1;
			outline.setPosition(Vector2f(size.x / 2.38, size.y / 2.6));
			play.setColor(color.Red);
			quit.setColor(color.White);
			quit.setOutlineColor(color.Yellow);
			quit.setOutlineThickness(4);
			play.setOutlineThickness(0);
		}

		if (InputManager::GetInstance()->Interact() && index == 0)
		{

			Paused = false;
			//printf("Scene Changed!");		
		}

		if (InputManager::GetInstance()->Interact() && index == 1)
		{
			activeScene = titleScene;
		}


		if (InputManager::Start())
		{
			Paused = false;
		}

	}
}

void OverworldScene::Render()
{
	//Renderer::GetWindow().setView();


	Scene::Render();


	sf::Texture::bind(&e2);
	sf::Texture::bind(&texture);
	sf::Texture::bind(&HH);


	for (int i = 0; i < 5; i++)
	{
		Renderer::Queue(&e2sprt[i]);
		Renderer::Queue(&sprite[i]);
	}

	Renderer::Queue(&psprite);
	Renderer::Queue(&sHH);
	Renderer::Queue(&play);
	Renderer::Queue(&quit);
	Renderer::Queue(&tile);
	sf::Texture::bind(&ptexture);

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
