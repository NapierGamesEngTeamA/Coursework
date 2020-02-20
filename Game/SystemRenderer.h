#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Renderer
{
	void Initialise(RenderWindow&);
	RenderWindow& GetWindow();
	//const View& GetView();

	void Shutdown();
	void Update(const Time&);
	void Queue(const Drawable* s);
	void Render();
}