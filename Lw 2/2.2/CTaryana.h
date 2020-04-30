#pragma once
#include "pch.h"
#include "CGraph.h"

class CTaryana
{
public:
	CTaryana(const CGraph& graph, std::ostream& output);
	void StronglyConnectedGraph();

private:
	std::stack<int> m_stack;
	int cnt, scnt;
	std::vector<bool> used;
	std::vector<int> pre, low, id;
	const CGraph& m_graph;
	std::ostream& m_output;

	void DFS(int w);
	int count() const { return scnt; }
	bool stronglyreachable(int v, int w) const
	{
		return id[v] == id[w];
	}
};
