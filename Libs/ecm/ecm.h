#pragma once
#include "maths.h"
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Component;

class Entity
{
protected:
	vector<shared_ptr<Component>> _components;
	Vector2f _position;
	float _rotation;
	bool _alive = true;				//Should be updated
	bool _visible = true;			//Should be rendered
	bool _fordeletion = false;		//Should be deleted
public:
	Entity();
	virtual ~Entity() { };
	virtual void Update(Time dt);
	virtual void Render();

	const Vector2f GetPosition() const;
	void SetPosition(const Vector2f& _position);
	bool Is_ForDeletion() const;
	float GetRotation() const;
	void SetRotation(float _rotation);
	bool IsAlive() const;
	void SetAlive(bool _alive);
	void SetForDelete();
	bool IsVisible() const;
	void SetVisible(bool _visible);

	template <typename T>
	shared_ptr<T> AddComponent()
	{
		static_assert(is_base_of<Component, T>::value, "T != component");
		shared_ptr<T> sp(make_shared<T>(this));
		_components.push_back(sp);
		return sp;
	}

	template <typename T>
	const vector<shared_ptr<T>> GetComponents() const
	{
		static_assert(is_base_of<Component, T>::value, "T != Component");
		vector<shared_ptr<T>> ret;
		for (const auto c : _components)
		{
			if (typeid(*c) == typeid(T))
			{
				ret.push_back(dynamic_pointer_cast<T>(c));
			}
		}

		return move(ret);
	}

	template <typename T>
	const vector<shared_ptr<T>> GetCompatibleComponent()
	{
		static_assert(is_base_of<Component, T>::value, "T != Component");
		vector<shared_ptr<T>> ret;
		for (auto c : _components)
		{
			auto dd = dynamic_cast<T*>(&(*c));
			if (dd)
			{
				ret.push_back(dynamic_pointer_cast<T>(c));
			}
		}
	}
};

class Component
{
protected:
	Entity* const _parent;
	bool _forDeletion;
	explicit Component(Entity* const p) : _parent(p), _forDeletion(false) { };
public:
	Component() = delete;
	bool Is_ForDeletion() const;
	virtual void Update(Time dt) = 0;
	virtual void Render() = 0;
	virtual ~Component() { };
};

struct EntityManager
{
	vector<shared_ptr<Entity>> list;
	void Update(Time dt);
	void Render();

	template <typename T>
	const vector<shared_ptr<T>> GetEntitys() const
	{
		static_assert(is_base_of<Entity, T>::value, "T != Entity");
		vector<shared_ptr<T>> ret;
		for (const auto c : list)
		{
			if (typeid(*c) == typeid(T))
			{
				ret.push_back(dynamic_pointer_cast<T>(c));
			}
		}

		return move(ret);
	}
};