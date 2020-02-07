#include "SpriteComponent.h"
#include "SystemRenderer.h"

void SpriteComponent::Update(double dt)
{
	_sprite->setPosition(_parent->GetPosition());
}

void SpriteComponent::Render()
{
	Renderer::Queue(_sprite.get());
}

Sprite& SpriteComponent::GetSprite() const { return *_sprite; }

SpriteComponent::SpriteComponent(Entity* p) : Component(p), _sprite(make_shared<Sprite>())
{

}