#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class SpriteComponent : public Component
{
protected:
	shared_ptr<Sprite> _sprite;
public:
	SpriteComponent() = delete;
	explicit SpriteComponent(Entity* p);
	void Update(double dt) override;
	void Render() override;

	Sprite& GetSprite() const;
	void SetTexture(Texture texture)
	{
		_sprite->setTexture(texture, false);
	}

	void SetRect(IntRect rect)
	{
		_sprite->setTextureRect(rect);
	}

};
