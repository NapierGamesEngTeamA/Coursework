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
#include "Enemy.h"
#include <random>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>
#include "BattleEntity.h"

#pragma endregion

using namespace std;
using namespace sf;

shared_ptr<Scene> titleScene;
shared_ptr<Scene> introScene;
shared_ptr<Scene> contScene;
shared_ptr<Scene> setScene;
shared_ptr<Scene> htpScene;
shared_ptr<Scene> overworldScene;
shared_ptr<Scene> combatScene;
shared_ptr<Scene> activeScene;
shared_ptr<Scene> winScene;
shared_ptr<Scene> loseScene;

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

	//Music titleMusic;
	if (!titleMusic.openFromFile("Res/Music/Overworld.ogg"))
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
		if (InputManager::GetInstance()->Up(true))
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
		else if (InputManager::GetInstance()->Left(true))
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
		else if (InputManager::GetInstance()->Right(true))
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

		else if (InputManager::GetInstance()->Down(true))
		{
			index = 3;
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

	
		if (InputManager::GetInstance()->Interact(true) && index == 0)
		{

			activeScene = introScene;
			//printf("Scene Changed!");		
		}

		if (InputManager::GetInstance()->Interact(true) && index == 1)
		{
			Renderer::GetWindow().close();
		}

		if (InputManager::GetInstance()->Interact(true) && index == 2)
		{
			activeScene = contScene;
		}

		if (InputManager::GetInstance()->Interact(true) && index == 3)
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


//Introduction Scene

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

	//Move cursor
	if (InputManager::GetInstance()->Up(true))
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


//Controls Scene

void ContScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

	Controlsmenu.loadFromFile("Res/Sprites/Controls.png");
	Vector2u size = Controlsmenu.getSize();
	sControlsmenu.setTexture(Controlsmenu);
	sControlsmenu.setOrigin(size.x / 200, size.y / 10);

	play.setColor(color.White);
	font.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	play.setFont(font);
	play.setCharacterSize(60);
	play.setString("Press 'W'\nTo Exit");
	play.setColor(color.White);
	play.setOutlineColor(color.Black);
	play.setOutlineThickness(4);

	const auto textRect = play.getGlobalBounds();
	play.setOrigin(textRect.width * .5f, textRect.height * .5f);
	play.setPosition(size.x / 10.2, size.y / 6.2);

	play2.setColor(color.White);
	font.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	play2.setFont(font);
	play2.setCharacterSize(60);
	play2.setString("Press 'D'\nTo View\nHow To Play");
	play2.setColor(color.White);
	play2.setOutlineColor(color.Black);
	play2.setOutlineThickness(4);

	const auto textRect2 = play2.getGlobalBounds();
	play2.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	play2.setPosition(size.x / 10.2, size.y / 2);

}

void ContScene::Update(Time dt)
{

	if (InputManager::GetInstance()->Up(true))
	{

		activeScene = titleScene;
		//printf("Scene Changed!");		
	}
	else if (InputManager::GetInstance()->Right(true))
	{
		activeScene = htpScene;
		//printf("Scene Changed!");		
	}

	//Renderer::GetWindow().setView(view)

}

void ContScene::Render()
{
	Scene::Render();

	sf::Texture::bind(&HTPmenu);
	Renderer::Queue(&sHTPmenu);
	
	sf::Texture::bind(&Controlsmenu);
	Renderer::Queue(&sControlsmenu);
	Renderer::Queue(&play);
	Renderer::Queue(&play2);
	
	sf::Texture::bind(NULL);
}



//Settings Scene
void SetScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

	Settingsmenu.loadFromFile("Res/Sprites/Settings.png");
	Vector2u size = Settingsmenu.getSize();
	sSettingsmenu.setTexture(Settingsmenu);
	sSettingsmenu.setOrigin(size.x / 200, size.y / 10);


}

void SetScene::Update(Time dt)
{

	if (InputManager::GetInstance()->Up(true))
	{

		activeScene = titleScene;
		//printf("Scene Changed!");		
	}
}

void SetScene::Render()
{
	Scene::Render();
	sf::Texture::bind(&Settingsmenu);
	Renderer::Queue(&sSettingsmenu);
	sf::Texture::bind(NULL);
}


void HTPScene::Load()
{
	Color color;

	view.reset(FloatRect(0, 0, 1920, 1080));

	htpsmenu.loadFromFile("Res/Sprites/htp.png");
	Vector2u size = htpsmenu.getSize();
	shtpsmenu.setTexture(htpsmenu);
	shtpsmenu.setOrigin(size.x / 200, size.y / 10);

	play.setColor(color.White);
	font.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	play.setFont(font);
	play.setCharacterSize(60);
	play.setString("Press 'S'\nTo View\nCombat Controls");
	play.setColor(color.White);
	play.setOutlineColor(color.Black);
	play.setOutlineThickness(4);

	const auto textRect = play.getGlobalBounds();
	play.setOrigin(textRect.width * .5f, textRect.height * .5f);
	play.setPosition(size.x / 10.2, size.y / 6.2);


	play2.setColor(color.White);
	font.loadFromFile("Res/Fonts/AncientModernTales-a7Po.ttf");
	play2.setFont(font);
	play2.setCharacterSize(60);
	play2.setString("Press 'A'\nTo View\nControls");
	play2.setColor(color.White);
	play2.setOutlineColor(color.Black);
	play2.setOutlineThickness(4);

	const auto textRect2 = play2.getGlobalBounds();
	play2.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
	play2.setPosition(size.x / 10.2, size.y / 2);
}

void HTPScene::Update(Time dt)
{

	if (InputManager::GetInstance()->Up(true))
	{
		play.setString("Press 'S'\nTo View\nCombat Controls");
		htpsmenu.loadFromFile("Res/Sprites/htp.png");
		//printf("Scene Changed!");		
	}
	else if (InputManager::GetInstance()->Left(true))
	{

		activeScene = contScene;
		//printf("Scene Changed!");		
	}
	else if (InputManager::GetInstance()->Down(true))
	{

		play.setString("Press 'W'\nTo View\nHow To Play\nGeneral");
		htpsmenu.loadFromFile("Res/Sprites/htpc.png");
		//printf("Scene Changed!");		
	}
}

void HTPScene::Render()
{
	Scene::Render();
	sf::Texture::bind(&htpsmenu);
	Renderer::Queue(&shtpsmenu);
	Renderer::Queue(&play);
	Renderer::Queue(&play2);
	sf::Texture::bind(NULL);
}


///////////////////////////////////////////////////////////////
#pragma endregion

#pragma region OverworldScene
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
		sprite[i].setPosition((rand() % 2000 + 4000) , (rand() % 1000 + 1500) - 80);

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

			psprite.setPosition(10000, 10000);
			play.setPosition(10000, 10000);
			quit.setPosition(10000, 10000);

		
	
			int bottom, top, left, right;
			bottom = sHH.getPosition().y + 260;
			left = sHH.getPosition().x;
			right = sHH.getPosition().x + 260;
			top = sHH.getPosition().y;

			if (c[0]->right < left || c[0]->left > right || c[0]->top > bottom || c[0]->bottom < top)
			{
				heal.setPosition(10000, 10000);
			}
			else
			{
				heal.setColor(color.Black);
				font.loadFromFile("Res/Fonts/SuperLegendBoy-4w8Y.ttf");
				heal.setFont(font);
				heal.setCharacterSize(30);
				heal.setString("Press Enter\nto accept a 1000 credit fee to\nheal your party");
				heal.setPosition(s2[0]->GetView().getCenter().x - 400, s2[0]->GetView().getCenter().y - 50);

				if (InputManager::GetInstance()->Interact(true))
				{

					heal.setString("Your party is on full health");
				
				}


			}



			for (int i = 0; i < 5; i++)
			{
				int bottom, top, left, right;
				int bottom2, top2, left2, right2;
			

				bottom = sprite[i].getPosition().y + 51;
				left = sprite[i].getPosition().x;
				right = sprite[i].getPosition().x + 30;
				top = sprite[i].getPosition().y;

				bottom2 = e2sprt[i].getPosition().y + 51;
				left2 = e2sprt[i].getPosition().x;
				right2 = e2sprt[i].getPosition().x + 30;
				top2 = e2sprt[i].getPosition().y;

				//Orc collision
				if (c[0]->right < left || c[0]->left > right || c[0]->top > bottom || c[0]->bottom < top)
				{

				}
				else
				{
					sprite[i].setPosition(Vector2f(-1000, -1000));
					activeScene = combatScene;
					cout << "Battle Comencing" << '\n';
				}

				//Skel Collision
				if (c[0]->right < left2 || c[0]->left > right2 || c[0]->top > bottom2 || c[0]->bottom < top2)
				{

				}
				else
				{
					sprite[i].setPosition(Vector2f(-1000, -1000));
					activeScene = combatScene;
					cout << "Battle Comencing" << '\n';
				}

			}
			s[0]->UpdateColMap(c[0], s[0]->tiles1, dt);
			//Debug: Back to menu

			if (InputManager::Start(true))
			{
				Paused = true;

			}




			//if (InputManager::Up(true) || InputManager::Down(true) || InputManager::Right(true) || InputManager::Left(true))
			//{
			//	int d100 = rand() % 100 + 1;
			//	if (d100 > 80)
			//	{
			//		//activeScene = combatScene;
			//		printf("Scene: Combat Scene");
			//	}
			//}

			InputManager::GetInstance()->Update();



			Scene::Update(dt);
		/*}*/
	}

	else
	{

		ptexture.loadFromFile("Res/Sprites/PauseMenu.png");
		Vector2u size = ptexture.getSize();
		psprite.setTexture(ptexture);
		psprite.setOrigin(size.x / 2, size.y / 2 );
		psprite.setPosition((s2[0]->GetView().getCenter().x), (s2[0]->GetView().getCenter().y));


		play.setColor(color.Red);
		font.loadFromFile("Res/Fonts/SuperLegendBoy-4w8Y.ttf");
		play.setFont(font);
		play.setCharacterSize(60);
		play.setString("Press 'W'\nTo Continue");



		const auto textRect = play.getGlobalBounds();
		play.setOrigin(textRect.width * .5f, textRect.height * .5f);
		play.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y - 100);


		quit.setFont(font);
		quit.setCharacterSize(60);
		quit.setString("Press 'S'\nTo Quit");
		quit.setColor(color.Red);

		const auto textRect2 = quit.getGlobalBounds();
		quit.setOrigin(textRect2.width * .5f, textRect2.height * .5f);
		quit.setPosition(s2[0]->GetView().getCenter().x, s2[0]->GetView().getCenter().y + 100);



		for (auto s : battleManager.GetEnts())
		{
			string str = s->GetHealthText();

			h1.setFont(font);
			h1.setCharacterSize(30);
			h1.setString(str);
			h1.setColor(color.Red);
		}
	
		

		const auto textRect3 = h1.getGlobalBounds();
		h1.setOrigin(textRect3.width * .5f, textRect3.height * .5f);
		h1.setPosition(s2[0]->GetView().getCenter().x , s2[0]->GetView().getCenter().y );

		if (InputManager::GetInstance()->Up(true))
		{
			index = 0;
			outline.setPosition(size.x / 2.38, size.y / 6);
			play.setColor(color.White);
			quit.setColor(color.Red);
			play.setOutlineColor(color.Yellow);
			play.setOutlineThickness(4);
			quit.setOutlineThickness(0);
		}
		else if (InputManager::GetInstance()->Down(true))
		{
			index = 1;
			outline.setPosition(Vector2f(size.x / 2.38, size.y / 2.6));
			play.setColor(color.Red);
			quit.setColor(color.White);
			quit.setOutlineColor(color.Yellow);
			quit.setOutlineThickness(4);
			play.setOutlineThickness(0);
		}

		if (InputManager::GetInstance()->Up(true) && index == 0)
		{

			Paused = false;
			//printf("Scene Changed!");		
		}

		if (InputManager::GetInstance()->Down(true) && index == 1)
		{
			activeScene = titleScene;
			Paused = false;
		}


		//if (InputManager::Start(true))
		//{
		//	Paused = false;
		//}
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

	Renderer::Queue(&sHH);
	Renderer::Queue(&psprite);
	Renderer::Queue(&play);
	Renderer::Queue(&quit);
	Renderer::Queue(&heal);
	Renderer::Queue(&h1);
//	Renderer::Queue(&tile);
	sf::Texture::bind(&ptexture);

	sf::Texture::bind(NULL);
}

///////////////////////////////////////////////////////////////
#pragma endregion

//////////////////// Combat Scene /////////////////////////////
void CombatScene::Load()
{


	bgTex.loadFromFile("Res/Sprites/CombatBackground.png");
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
	
	menuText[0].setFont(font);
	menuText[0].setColor(Color::White);
	menuText[0].setCharacterSize(36);
	menuText[0].setPosition(Vector2f(50, 100));
	menuText[0].setString("<:Attack");
	menuText[0].setOutlineColor(color.Red);
	menuText[0].setOutlineThickness(4);

	menuText[1].setFont(font);
	menuText[1].setColor(Color::White);
	menuText[1].setCharacterSize(36);
	menuText[1].setPosition(Vector2f(125, 150));
	menuText[1].setString("\\/:Flee");
	menuText[1].setOutlineColor(color.Red);
	menuText[1].setOutlineThickness(4);

	menuText[2].setFont(font);
	menuText[2].setColor(Color::White);
	menuText[2].setCharacterSize(36);
	menuText[2].setPosition(Vector2f(200, 100));
	menuText[2].setString(">:Magic");
	menuText[2].setOutlineColor(color.Red);
	menuText[2].setOutlineThickness(4);




	for (int i = 0; i < 4; i++)
	{
		enemyText[i].setFont(font);
		enemyText[i].setColor(Color::White);
		enemyText[i].setCharacterSize(36);
		enemyText[i].setPosition(Vector2f(950, 500 + (100 * i)));
		enemyText[i].setString(to_string(i + 1));
	}

	//Add health 

	if (!battleMusic.openFromFile("Res/Music/BossFight.ogg"))
	{
		cout << "Can't load battle music" << endl;
	}
	battleMusic.setVolume(100);
	battleMusic.setLoop(true);
	//battleMusic.play();

	battleManager.Load();

	view.reset(FloatRect(0, 0, 1920, 1080));

}

void CombatScene::Update(Time dt)
{
	battleManager.Update(dt);

	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		menuText[0].setOutlineThickness(0);
		menuText[1].setOutlineThickness(0);
		menuText[2].setOutlineThickness(0);
		for (int i = 0; i < 4; i++)
		{
			enemyText[i].setOutlineColor(color.Red);
			enemyText[i].setOutlineThickness(4);
		}


	}
	else if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4))
	{
		menuText[0].setOutlineThickness(4);
		menuText[1].setOutlineThickness(4);
		menuText[2].setOutlineThickness(4);

		for (int i = 0; i < 4; i++)
		{
			enemyText[i].setOutlineColor(color.Red);
			enemyText[i].setOutlineThickness(0);
		}
	}


	//if (battleManager.Lose() == true)
	//{
	//	activeScene == loseScene;
	//}

	Scene::Update(dt);
}

void CombatScene::Render()
{
	
	if (battleManager.GetBattleEnts().size() > 4)
	{
		vector<shared_ptr<BattleEntity>> e = battleManager.GetBattleEnts();

		string s = e[0]->GetHealthText() + "\n" +
			e[1]->GetHealthText() + "\n" +
			e[2]->GetHealthText() + "\n" +
			e[3]->GetHealthText();

		statText.setString(s);
	}
	
	Renderer::GetWindow().setView(view);
	Renderer::Queue(&background);
	Renderer::Queue(&canvas);
	Renderer::Queue(&statText);
	Renderer::Queue(&menuText[0]);
	Renderer::Queue(&menuText[1]);
	Renderer::Queue(&menuText[2]);
	for (int i = 0; i < 4; i++)
	{
		Renderer::Queue(&enemyText[i]);
	}
	battleManager.Render();
	Scene::Render();


}

void WinScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

	Win.loadFromFile("Res/Sprites/YouWin.png");
	Vector2u size = Win.getSize();
	sWin.setTexture(Win);
	sWin.setOrigin(size.x / 200 , size.y / 10 );
}

void WinScene::Update(Time dt)
{
	Scene::Update(dt);
}


void WinScene::Render()
{
	Scene::Render();

	sf::Texture::bind(&Win);
	Renderer::Queue(&sWin);


	sf::Texture::bind(NULL);
}




void LoseScene::Load()
{
	view.reset(FloatRect(0, 0, 1920, 1080));

	Lose.loadFromFile("Res/Sprites/YouLose.png");
	Vector2u size = Lose.getSize();
	sLose.setTexture(Lose);
	sLose.setOrigin(size.x / 2 , size.y / 2);
}

void LoseScene::Update(Time dt)
{
}


void LoseScene::Render()
{
	Scene::Render();

	sf::Texture::bind(&Lose);
	Renderer::Queue(&sLose);


	sf::Texture::bind(NULL);
}

