#include "Tile.h"
#include "SystemRenderer.h"

using namespace sf;
using namespace std;

Tile::Tile(Entity* p) : Component(p), _sprite(make_shared<Sprite>())
{

}

void Tile::Update(Time dt)
{
	
}

void Tile::Render()
{
	Renderer::Queue(_sprite.get());
}

Sprite& Tile::GetSprite() const { return *_sprite; }