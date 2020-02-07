#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Renderer
{
	void Initialise(RenderWindow&);
	RenderWindow& GetWindow();

	void Shutdown();
	void Update(const double&);
	void Queue(const Drawable* s);
	void Render();
}