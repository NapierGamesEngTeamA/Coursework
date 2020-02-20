#include "Camera.h"
#include "SystemRenderer.h"

Camera::Camera(Entity* p) : Component(p), _view(make_shared<View>())
{
	/*_view->setSize(Vector2f(1920, 1080));
	_view->setViewport(FloatRect(_parent->GetPosition().x, _parent->GetPosition().y, 1920, 1080));
	_view->setCenter(_parent->GetPosition().x, _parent->GetPosition().y);
	_view->setViewport(FloatRect(_parent->GetPosition().x, _parent->GetPosition().y, 1, 1));*/
	_view->reset(FloatRect(_parent->GetPosition(), Vector2f(1920, 1080)));
}

void Camera::Update(Time dt)
{
	//_view->move(Vector2f(_parent->GetPosition().x, _parent->GetPosition().y));
	_view->setCenter(_parent->GetPosition());
	SetWindow();
	//cout << _view->getCenter() << endl;
}

void Camera::Render()
{

}

View& Camera::GetView() const { return *_view; }

void Camera::SetWindow()
{
	Renderer::GetWindow().setView(*_view);
}