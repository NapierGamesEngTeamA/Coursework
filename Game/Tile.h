#pragma once
#include "ecm.h"

using namespace sf;
using namespace std;

class Tile : public Component
{
protected:
	shared_ptr<Sprite> _sprite;
public:
	Tile() = delete;
	explicit Tile(Entity* p);
	void Update(Time dt) override;
	void Render() override;

	Sprite& GetSprite() const;

	void SetPosition(Vector2f p)
	{
		_sprite->setPosition(p);
	}

	void SetTexture(Texture texture)
	{
		_sprite->setTexture(texture);
	}

	void SetRect(IntRect rect)
	{
		_sprite->setTextureRect(rect);
	}
};