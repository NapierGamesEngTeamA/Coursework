//TO DO:
//Anims: Animations work but need to change deltaTime to time instead of double.

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"
#include "ecm.h"
#include "SystemRenderer.h"
#include "InputManager.h"

using namespace sf;
using namespace std;

uint16_t _gameHeight = 1080, _gameWidth = 1920;
Time dt;
//test
void Load()
{
	// Initialise Scenes
	titleScene.reset(new TitleScene());
	introScene.reset(new IntroScene());
	contScene.reset(new ContScene());
	setScene.reset(new SetScene());
	htpScene.reset(new HTPScene());
	overworldScene.reset(new OverworldScene());
	combatScene.reset(new CombatScene());
	loseScene.reset(new LoseScene());
	winScene.reset(new WinScene());
	titleScene->Load();
	introScene->Load();
	contScene->Load();
	setScene->Load();
	htpScene->Load();
	overworldScene->Load();
	combatScene->Load();
	loseScene->Load();
	winScene->Load();

	// Set current scene
	activeScene = titleScene;
}

void Update(RenderWindow& window)
{
	//Check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}

		InputManager::GetInstance()->Update();
	}

	//Debug exit
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

	

	//Update current scene
	activeScene->Update(dt);

	//Update renderer
	Renderer::Update(dt);
}

void Render(RenderWindow& window)
{
	// Render Active scene
	activeScene->Render();

	Renderer::Render();
}

int main()
{
	RenderWindow window(VideoMode(_gameWidth, _gameHeight), "Game");
	Renderer::Initialise(window);
	Load();
	Clock clock;
	while (window.isOpen())
	{
		dt = clock.restart();
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}