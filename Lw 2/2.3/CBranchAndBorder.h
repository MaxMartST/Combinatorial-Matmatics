#pragma once

#include "pch.h"
#include "CGraph.h"
#include <limits>

struct Edge
{
	size_t ik;
	size_t jk;
};

class CBranchAndBorder
{
public:
	CBranchAndBorder(CGraph& graph, std::ostream& output);
	void FindHamiltonianCycle();
	void PrintHamiltonianCycle();

private:
	const CGraph& m_graph;
	std::ostream& m_output;
	size_t m_vertices;
	Edge m_edge;
	int flag, cnt;
	std::vector<std::vector<int>> m_matrix;

	void CountElementsOX();
	void CountElementsOY();

	void SubtractMinElementFromOX();
	void SubtractMinElementFromOY();

	void LookingForBaseValues();

	void MakeBase();
};
