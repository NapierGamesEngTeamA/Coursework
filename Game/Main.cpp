#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"
#include "ecm.h"
#include "SystemRenderer.h"

using namespace sf;
using namespace std;

uint16_t _gameHeight = 1080, _gameWidth = 1920;

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
	static Clock clock;
	float dt = clock.restart().asSeconds();

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
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}