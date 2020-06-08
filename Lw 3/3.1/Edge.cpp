#include "Edge.h"

namespace dt {

	template<typename T>
	Edge<T>::Edge(const VertexType &v1, const VertexType &v2) 
		: v(&v1)
		, w(&v2)
	{}

	template<typename T>
	bool Edge<T>::operator ==(const Edge<T> &e) const
	{
		return (*(this->v) == *e.v && *(this->w) == *e.w) || (*(this->v) == *e.w && *(this->w) == *e.v);
	}

	template struct Edge<float>;
	template struct Edge<double>;
}
