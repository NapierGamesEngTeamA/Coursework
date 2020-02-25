#include "InputManager.h"
#include <iostream>

using namespace std;

static Keyboard::Key _controls[7] = {
		Keyboard::W,
		Keyboard::S,
		Keyboard::A,
		Keyboard::D,
		Keyboard::Enter,
		Keyboard::Tab,
		Keyboard::Escape
};

Joystick _controller;

InputManager* InputManager::_instance = 0;

InputManager* InputManager::GetInstance()
{
	if (_instance == 0)
	{
		_instance = new InputManager();
	}

	return _instance;
}

InputManager::InputManager()
{
	if (_controller.isConnected(0))
	{
		cout << "Controller Connected!" << endl;
	}
	else
	{
		cout << "No controller detected!" << endl;
	}
}

Keyboard::Key InputManager::GetControls(unsigned int i)
{
	return _controls[i];
}

void InputManager::Update()
{
	if (_controller.isConnected(0))
	{
		_controller.update();
	}
}

bool InputManager::Up()
{
	return (Keyboard::isKeyPressed(_controls[0])) || (_controller.getAxisPosition(0, Joystick::Axis::PovY) >= 100);
}

bool InputManager::Down()
{
	return (Keyboard::isKeyPressed(_controls[1])) || (_controller.getAxisPosition(0, Joystick::Axis::PovY) <= -100);
}

bool InputManager::Left()
{
	return (Keyboard::isKeyPressed(_controls[2])) || (_controller.getAxisPosition(0, Joystick::Axis::PovX) <= -100);
}

bool InputManager::Right()
{
	return (Keyboard::isKeyPressed(_controls[3])) || (_controller.getAxisPosition(0, Joystick::Axis::PovX) >= 100);
}

bool InputManager::Interact()
{
	return (Keyboard::isKeyPressed(_controls[4])) || (_controller.isButtonPressed(0, 0));
}

bool InputManager::Start()
{
	return (Keyboard::isKeyPressed(_controls[5])) || (_controller.isButtonPressed(0, 7));
}

bool InputManager::Back()
{
	return (Keyboard::isKeyPressed(_controls[6])) || (_controller.isButtonPressed(0, 6));
}