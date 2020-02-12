#pragma once
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>
#include <vector>

namespace sf
{
	//PI
	const double pi = 3.14159265358979323846;

	//Create a definition for a sf::vector using size_t types
	typedef Vector2<size_t> Vector2ul;
	//Returns the length of a sf::vector
	template <typename T> double Length(const Vector2<T>& v)
	{
		return sqrt(pow(v.x, 2), pow(v.y, 2));
	}

	//Returns normalized sf::vector
	template <typename T> Vector2<T> Normalize(const Vector2<T>& v)
	{
		Vector2<T> vector;
		double l = Length(v);
		if (l != 0)
		{
			vector.x = v.x / l;
			vector.y = v.y / l;
		}
		return vector;
	}

	//Allow casting from one sf::vector internal type to another
	template <typename T, typename U> Vector2<T> Vcast(const Vector2<U>& v)
	{
		return Vector2<T>(static_cast<T>(v.x), static_cast<T>(v.y));
	};

	//Degrees to radians conversion
	static double ToRadians(double degrees)
	{
		return (degrees * pi / 180);
	}

	//Rotate a sf::vector by an angle(degrees)
	template <typename T> Vector2<T> Rotate(const Vector2<T>& v, const double degrees)
	{
		const double theta = ToRadians(degrees);
		const double cs = cos(theta);
		const double sn = sin(theta);
		return { (T)(v.x * cs - v.y * sn), (T)(v.x * sn + v.y * cs) };
	}

	//Allow sf::vectors to be cout'ed
	template <typename T> std::ostream& operator<<(std::ostream& os, const Vector2<T>& v)
	{
		os << '(' << v.x << ',' << v.y << ')';
		return os;
	}
}