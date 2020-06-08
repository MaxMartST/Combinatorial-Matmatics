#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "Triangle.h"

#include <vector>
#include <algorithm>

namespace dt {

	template<typename T>
	class CDelaunay
	{
		using Type = T;
		using VertexType = Vertex<Type>;
		using EdgeType = Edge<Type>;
		using TriangleType = Triangle<Type>;

		static_assert(std::is_floating_point<CDelaunay<T>::Type>::value, "Type must be floating-point");

		std::vector<TriangleType> _triangles;
		std::vector<EdgeType> _edges;
		std::vector<VertexType> _vertices;

	public:

		CDelaunay() = default;
		CDelaunay(const CDelaunay&) = delete;
		CDelaunay(CDelaunay&&) = delete;

		const std::vector<TriangleType>& Triangulate(std::vector<VertexType> &vertices);
		const std::vector<TriangleType>& GetTriangles() const;
		const std::vector<EdgeType>& GetEdges() const;
		const std::vector<VertexType>& GetVertices() const;

		CDelaunay& operator=(const CDelaunay&) = delete;
		CDelaunay& operator=(CDelaunay&&) = delete;
	};

}