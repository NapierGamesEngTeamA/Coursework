#pragma once
#include "ActorMovementComponent.h"

class PlayerMovementComponent : public ActorMovementComponent
{
public:
	PlayerMovementComponent() = delete;
	explicit PlayerMovementComponent(Entity* p);
	~PlayerMovementComponent() = default;

	void Update(double dt) override;
	void Render() override { };
};