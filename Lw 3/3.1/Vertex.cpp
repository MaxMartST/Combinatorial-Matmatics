#include "Vertex.h"

namespace dt {
	template<typename T>
	Vertex<T>::Vertex(const T vx, const T vy)
		: x(vx)
		, y(vy)
	{}

	template<typename T>
	Vertex<T>::Vertex(const T vx, const T vy, const size_t number)
		: x(vx)
		, y(vy)
		, number(number)
	{}

	template<typename T>
	T Vertex<T>::dist2(const Vertex<T> &v) const
	{
		const T dx = x - v.x;
		const T dy = y - v.y;
		return dx * dx + dy * dy;
	}

	template<>
	float Vertex<float>::dist(const Vertex<float> &v) const
	{
		return hypotf(x - v.x, y - v.y);
	}

	template<>
	double Vertex<double>::dist(const Vertex<double> &v) const
	{
		return hypot(x - v.x, y - v.y);
	}

	template<typename T>
	T Vertex<T>::norm2() const
	{
		return x * x + y * y;
	}

	template<typename T>
	bool Vertex<T>::operator ==(const Vertex<T> &v) const
	{
		return (this->x == v.x) && (this->y == v.y);
	}

	template<typename U>
	std::ostream & operator <<(std::ostream &str, const Vertex<U> &v)
	{
		return str << "Point x: " << v.x << " y: " << v.y;
	}

	template struct Vertex<float>;
	template struct Vertex<double>;
}