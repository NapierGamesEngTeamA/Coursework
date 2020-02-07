#pragma once 
#include <ecm.h>

using namespace sf;

class ActorMovementComponent : public Component
{
protected: 
	bool ValidMove(const Vector2f&);
	float _speed;
public:
	ActorMovementComponent() = delete;
	explicit ActorMovementComponent(Entity* p);
	~ActorMovementComponent() = default;

	float GetSpeed() const;
	void SetSpeed(float _speed);
	void Move(const Vector2f&);
	void Move(float x, float y);
	void Update(double dt) override;
	void Render() override { }
};