#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class InputManager
{
private:
	static InputManager* instance;
	InputManager();
public:
	static InputManager* GetInstance();
};