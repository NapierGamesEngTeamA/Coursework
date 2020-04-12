#pragma once
#include "ecm.h"

using namespace sf;
using namespace std;

class Camera : public Component
{
protected:
	shared_ptr<View> _view;
	shared_ptr<View> _view2;
public:
	Camera() = delete;
	explicit Camera(Entity* p);
	void Update(Time dt) override;
	void Render() override;

	View& GetView() const;

	void SetPosition(Vector2f p)
	{
		_view->setCenter(p);
	}

	void SetWindow();
private:
	Texture texture;
	Sprite sprite;
};