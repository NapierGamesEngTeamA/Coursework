#include "ActorMovementComponent.h"

using namespace sf;

void ActorMovementComponent::Update(Time dt) { }

ActorMovementComponent::ActorMovementComponent(Entity *p)
	: _speed(100.0f), Component(p) { }

bool ActorMovementComponent::ValidMove(const Vector2f& pos)
{
	return false;
}

void ActorMovementComponent::Move(const Vector2f& p)
{
	auto pp = _parent->GetPosition() + p;
	_parent->SetPosition(pp);
}

void ActorMovementComponent::Move(float x, float y)
{
	Move(Vector2f(x, y));
}

float ActorMovementComponent::GetSpeed() const
{
	return _speed;
}

void ActorMovementComponent::SetSpeed(float speed)
{
	_speed = speed;
}