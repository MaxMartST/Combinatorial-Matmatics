#pragma once
#include <string>

class CMatrixIterator;

class CGraph
{
public:
	CGraph(std::istream& in);
	int GetNumberOfVertices() const { return numberOfVertices; }

	friend class CMatrixIterator;

private:
	template <class T>
	std::vector<T> ConvertStringToVector(std::string& line);
	std::vector<std::vector<int>> adjacencyMatrix;
	int numberOfVertices;

	void UploadGraph(std::istream& in);

	static const size_t NUMBER_INPUT_PARAMETERS = 1;
	static const size_t MAX_POINTS_COUNT = 400;
};

class CMatrixIterator
{
private:
	const CGraph& m_graph;
	int i, v;

public:
	CMatrixIterator(const CGraph& graph, int v)
		: m_graph(graph)
		, v(v)
		, i(-1)
	{
	}

	int beg()
	{
		i = -1;
		return nxt();
	}

	int nxt()
	{
		for (i++; i < m_graph.GetNumberOfVertices(); i++)
		{
			if (m_graph.adjacencyMatrix[v][i] == 1)
			{
				return i;
			}
		}

		return -1;
	}

	bool end()
	{
		return i >= m_graph.GetNumberOfVertices();
	}
};