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

	static bool Up(bool released);
	static bool Down(bool released);
	static bool Right(bool released);
	static bool Left(bool released);
	static bool Interact(bool released);
	static bool Back(bool released);
	static bool Start(bool released);
	

	
};