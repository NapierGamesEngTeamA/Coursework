#include "Camera.h"
#include "SystemRenderer.h"

Camera::Camera(Entity* p) : Component(p), _view(make_shared<View>())
{
	_view->setSize(Vector2f(1920, 1080));
}

void Camera::Update(Time dt)
{
	//_view->setCenter(_parent->GetPosition());
	_view->setViewport(FloatRect(_parent->GetPosition().x, _parent->GetPosition().y, 1920, 1080));
}

void Camera::Render()
{

}

View& Camera::GetView() const { return *_view; }

void Camera::SetWindow()
{
	Renderer::GetWindow().setView(*_view);
}