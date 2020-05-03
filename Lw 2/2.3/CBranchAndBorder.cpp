#include "pch.h"
#include "CBranchAndBorder.h"

using namespace std;

CBranchAndBorder::CBranchAndBorder(CGraph& graph, ostream& output)
	: m_graph(graph)
	, m_output(output)
	, m_vertices(graph.GetNumberOfVertices())
	, m_matrix(graph.GetAdjacencyMatrix())
{
}

void CBranchAndBorder::MakeBase()
{
	for (size_t i = 0; i < m_vertices; i++)
	{
		if (m_matrix[i][m_edge.jk] >= 0)
		{
			m_matrix[i][m_edge.jk] = -1;
		}
	}

	for (size_t j = 0; j < m_vertices; j++)
	{
		if (m_matrix[m_edge.ik][j] >= 0)
		{
			m_matrix[m_edge.ik][j] = -1;
		}
	}

	m_matrix[m_edge.ik][m_edge.jk] = -2;

	if (m_matrix[m_edge.jk][m_edge.ik] >= 0)
	{
		m_matrix[m_edge.jk][m_edge.ik] = -1;
	}
}

void CBranchAndBorder::CountElementsOX()
{
	for (size_t i = 0; (i < m_vertices) && (flag == 0); i++)
	{

		cnt = 0;

		for (size_t j = 0; j < m_vertices; j++)
		{
			if (m_matrix[i][j] >= 0)
			{
				m_edge.ik = i;
				m_edge.jk = j;
				cnt++;
			}
		}

		if (cnt == 1)
		{
			flag = 1;
		}
	}
}

void CBranchAndBorder::CountElementsOY()
{
	for (size_t j = 0; (j < m_vertices) && (flag == 0); j++)
	{
		cnt = 0;

		for (size_t i = 0; i < m_vertices; i++)
		{
			if (m_matrix[i][j] >= 0)
			{
				m_edge.ik = i;
				m_edge.jk = j;
				cnt++;
			}
		}

		if (cnt == 1)
		{
			flag = 1;
		}
	}
}

void CBranchAndBorder::SubtractMinElementFromOX()
{
	int min;

	for (size_t i = 0; i < m_vertices; i++)
	{
		min = INT_MAX;

		for (size_t j = 0; j < m_vertices; j++)
		{
			if ((m_matrix[i][j] >= 0) && (m_matrix[i][j] < min))
			{
				min = m_matrix[i][j];
			}
		}

		for (size_t j = 0; j < m_vertices; j++)
		{
			if (m_matrix[i][j] >= 0)
			{
				m_matrix[i][j] -= min;
			}
		}
	}
}

void CBranchAndBorder::SubtractMinElementFromOY()
{
	int min;

	for (size_t j = 0; j < m_vertices; j++)
	{
		min = INT_MAX;

		for (size_t i = 0; i < m_vertices; i++)
		{
			if ((m_matrix[i][j] >= 0) && (m_matrix[i][j] < min))
			{
				min = m_matrix[i][j];
			}
		}

		for (size_t i = 0; i < m_vertices; i++)
		{
			if (m_matrix[i][j] >= 0)
			{
				m_matrix[i][j] -= min;
			}
		}
	}
}

void CBranchAndBorder::LookingForBaseValues()
{
	int miniv, minjv, maxv;
	maxv = -1;

	for (size_t i = 0; i < m_vertices; i++)
	{
		for (size_t j = 0; j < m_vertices; j++)
		{
			if (m_matrix[i][j] == 0)
			{
				miniv = INT_MAX;
				minjv = INT_MAX;

				for (size_t i2 = 0; i2 < m_vertices; i2++)
				{
					if ((m_matrix[i2][j] >= 0) && (i2 != i) && (m_matrix[i2][j] < miniv))
					{
						miniv = m_matrix[i2][j];
					}
				}

				for (size_t j2 = 0; j2 < m_vertices; j2++)
				{
					if ((m_matrix[i][j2] >= 0) && (j2 != j) && (m_matrix[i][j2] < minjv))
					{
						minjv = m_matrix[i][j2];
					}
				}

				if (miniv + minjv > maxv)
				{
					maxv = miniv + minjv;
					m_edge.ik = i;
					m_edge.jk = j;
				}
			}
		}
	}
}

void CBranchAndBorder::FindHamiltonianCycle()
{
	for (size_t c = 0; c < m_vertices; c++)
	{
		flag = 0;

		CountElementsOX();
		CountElementsOY();

		if (flag == 1)
		{
			MakeBase();
			continue;
		}

		SubtractMinElementFromOX();
		SubtractMinElementFromOY();

		LookingForBaseValues();
		MakeBase();
	}
}

void CBranchAndBorder::PrintHamiltonianCycle()
{
	size_t i = 0;
	m_output << i + 1;

	for (size_t c = 0; c < m_vertices; c++)
	{
		for (size_t j = 0; j < m_vertices; j++)
		{
			if (m_matrix[i][j] == -2)
			{
				m_output << "->" << j + 1;
				i = j;
				break;
			}
		}
	}
}