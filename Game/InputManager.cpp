#include "InputManager.h"

InputManager* InputManager::instance = 0;

InputManager* InputManager::GetInstance()
{
	if (instance == 0)
	{
		instance = new InputManager();
	}

	return instance;
}

InputManager::InputManager()
{

}