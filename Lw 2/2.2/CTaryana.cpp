#include "pch.h"
#include "CTaryana.h"

using namespace std;

CTaryana::CTaryana(const CGraph& graph, ostream& output)
	: m_graph(graph)
	, m_output(output)
	, cnt(0)
	, scnt(0)
	, used(graph.GetNumberOfVertices(), false)
	, pre(graph.GetNumberOfVertices(), -1)
	, low(graph.GetNumberOfVertices())
	, id(graph.GetNumberOfVertices())
{
}

void CTaryana::DFS(int w)
{
	used[w] = true;
	int t;
	int min = low[w] = pre[w] = cnt++;
	m_stack.push(w);

	typename CMatrixIterator A(m_graph, w);

	for (t = A.beg(); !A.end(); t = A.nxt())
	{
		if (pre[t] == -1)
		{
			DFS(t);
		}

		if (low[t] < min)
		{
			min = low[t];
		}
	}

	if (min < low[w])
	{
		low[w] = min;
		return;
	}

	do
	{
		id[t = m_stack.top()] = scnt;
		low[t] = m_graph.GetNumberOfVertices();
		m_stack.pop();
	} while (t != w);

	scnt++;
}

void CTaryana::StronglyConnectedGraph()
{
	for (int i = 0; i < m_graph.GetNumberOfVertices(); ++i)
	{
		if (!used[i])
		{
			DFS(i);
		}
	}

	if (scnt > 1)
	{
		m_output << "no\n";
	}
	else if (scnt == 1)
	{
		m_output << "yes\n";
	}
	else
	{
		m_output << "Strongly connected components not found\n";
	}
}