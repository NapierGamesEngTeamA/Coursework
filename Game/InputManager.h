#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class InputManager
{
private:
	static InputManager* _instance;
	InputManager();

public:
	static InputManager* GetInstance();
	static Keyboard::Key GetControls(unsigned int i);
	static void SetControl(int index, Keyboard::Key k);
	static void Update();

	static bool Up();
	static bool Down();
	static bool Right();
	static bool Left();
	static bool Interact();
	static bool Back();
	static bool Start();
	

	
};