#include "ShapeComponent.h"
#include "SystemRenderer.h"

void ShapeComponent::Update(Time dt)
{
	_shape->setPosition(_parent->GetPosition());
}

void ShapeComponent::Render()
{
	Renderer::Queue(_shape.get());
}

Shape& ShapeComponent::GetShape() const { return *_shape; }

ShapeComponent::ShapeComponent(Entity* p) : Component(p), _shape(make_shared<CircleShape>())
{

}
