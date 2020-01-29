#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class ShapeComponent : public Component
{
protected:
	shared_ptr<Shape> _shape;
public:
	ShapeComponent() = delete;
	explicit ShapeComponent(Entity* p);
	void Update(double dt) override;
	void Render() override;

	Shape& GetShape() const;

	template<typename T, typename params>
	void SetShape(T)
	{
		_shape.reset(new T(params));
	}

};