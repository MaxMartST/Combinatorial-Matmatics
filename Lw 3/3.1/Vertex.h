#pragma once
#include "Numeric.h"
#include <iostream>
#include <cmath>
#include <type_traits>

namespace dt {

	template<typename T>
	struct Vertex
	{
		using Type = T;
		Vertex() = default;
		Vertex(const Vertex<T> &v) = default;
		Vertex(Vertex<T>&&) = default;
		Vertex(const T vx, const T vy);
		Vertex(const T vx, const T vy, const size_t number);

		T dist2(const Vertex<T> &v) const;
		T dist(const Vertex<T> &v) const;
		T norm2() const;

		Vertex &operator=(const Vertex<T>&) = default;
		Vertex &operator=(Vertex &&) = default;
		bool operator ==(const Vertex<T> &v) const;
		template<typename U>
		friend std::ostream &operator <<(std::ostream &str, const Vertex<U> &v);

		T x;
		T y;
		size_t number = 0;

		static_assert(std::is_floating_point<Vertex<T>::Type>::value, "Type must be floating-point");
	};

	template<typename T>
	bool almost_equal(const Vertex<T> &v1, const Vertex<T> &v2)
	{
		return almost_equal(v1.x, v2.x) && almost_equal(v1.y, v2.y);
	}

}