//TO DO:
//Anims: Animations work but need to change deltaTime to time instead of double.

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"
#include "ecm.h"
#include "SystemRenderer.h"

using namespace sf;
using namespace std;

uint16_t _gameHeight = 1080, _gameWidth = 1920;
Time dt;

void Load()
{
	

	titleScene.reset(new TitleScene());
	overworldScene.reset(new OverworldScene());
	titleScene->Load();
	overworldScene->Load();

	activeScene = titleScene;
}

void Update(RenderWindow& window)
{
	//Reset clock, recalculate deltatime
	/*static Clock clock;
	Time dt = clock.getElapsedTime();
	clock.restart();*/

	//Check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	//Debug exit
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

	activeScene->Update(dt);
}

void Render(RenderWindow& window)
{
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
		//window.setView();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}