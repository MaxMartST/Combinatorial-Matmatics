#pragma once
#include <math.h>
#include <limits>
#include <type_traits>

namespace dt {
	template<class T>
	typename std::enable_if<std::is_same<T, float>::value, bool>::type almost_equal(T x, T y, int ulp = 2)
	{
		return fabsf(x - y) <= std::numeric_limits<float>::epsilon() * fabsf(x + y) * static_cast<float>(ulp)
			|| fabsf(x - y) < std::numeric_limits<float>::min();
	}

	template<class T>
	typename std::enable_if<std::is_same<T, double>::value, bool>::type almost_equal(T x, T y, int ulp = 2)
	{
		return fabs(x - y) <= std::numeric_limits<double>::epsilon() * fabs(x + y) * static_cast<double>(ulp)
			|| fabs(x - y) < std::numeric_limits<double>::min();
	}

}