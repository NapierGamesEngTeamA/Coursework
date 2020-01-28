#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

uint16_t _gameHeight = 1080, _gameWidth = 1920;

void Load()
{

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


}

void Render(RenderWindow& window)
{

}

int main()
{
	RenderWindow window(VideoMode(_gameWidth, _gameHeight), "Game");
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