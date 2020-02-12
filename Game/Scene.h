#pragma once
#include <SFML/Graphics.hpp>
#include "ecm.h"

using namespace std;

class Scene
{
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void Update(Time dt);
	virtual void Render();
	virtual void Load() = 0;
	vector<shared_ptr<Entity>>& GetEnts();
protected:
	EntityManager _ents;
};