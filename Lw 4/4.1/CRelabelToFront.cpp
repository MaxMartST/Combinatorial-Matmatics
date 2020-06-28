#include "CRelabelToFront.h"

using namespace std;

CRelabelToFront::CRelabelToFront(unsigned int numberVertex, vector<std::vector<double>> vertex)
{
	try
	{
		this->m_edgeCount = numberVertex;
		this->m_n = numberVertex;
		this->m_c.assign(m_n, VInt(m_n, 0));

		for (size_t i = 0; i < m_edgeCount; i++)
		{
			for (size_t j = 0; j < m_edgeCount; j++)
			{
				if (vertex[i][j] > 0)
				{
					m_c[i][j] = vertex[i][j];
				}

				if (vertex[i][j] < 0)
				{
					throw invalid_argument("ERROR: Invalid vertex value!\n");
				}
			}
		}

		this->m_src = 0;
		this->m_dest = numberVertex - 1;
	}
	catch (const invalid_argument&)
	{
		throw;
	}
}

void CRelabelToFront::lift(unsigned long u)
{
	double height = 2 * (double)m_n;

	for (LIter it = m_nei[u].begin(); it != m_nei[u].end(); it++)
	{
		if (m_c[u][(unsigned long)*it] > m_f[u][(unsigned long)*it])
		{
			height = fmin(height, m_h[(unsigned long)*it]);
		}
	}

	m_h[u] = height + 1;
}

void CRelabelToFront::push(unsigned long u, unsigned long v)
{

	double value = min(m_c[u][v] - m_f[u][v], m_e[u]);
	m_f[u][v] += value;
	m_f[v][u] = -m_f[u][v];
	m_e[u] -= value;
	m_e[v] += value;
}

bool CRelabelToFront::discharge(unsigned long u)
{
	bool lifted = false;

	while (m_e[u] > 0)
	{
		if (m_current[u] == m_nei[u].end())
		{
			lift(u);
			lifted = true;
			m_current[u] = m_nei[u].begin();
			continue;
		}

		unsigned long v = (unsigned long)*m_current[u];

		if (m_c[u][v] > m_f[u][v] && m_h[u] == m_h[v] + 1)
		{
			push(u, v);
		}
		else
		{
			m_current[u]++;
		}
	}

	return lifted;
}

void CRelabelToFront::Ltf()
{
	unsigned long u, v;

	m_nei.resize(m_n);
	m_current.resize(m_n);
	for (u = 0; u < m_n; u++)
	{
		for (v = 0; v < m_n; v++)
		{
			if (m_c[u][v] > 0 || m_c[v][u] > 0)
			{
				m_nei[u].push_back(v);
			}
		}

		m_current[u] = m_nei[u].begin();
	}

	m_f.assign(m_n, VInt(m_n, 0));
	m_e.assign(m_n, 0);
	m_h.assign(m_n, 0);
	m_h[m_src] = m_n;

	for (u = 0; u < m_n; u++)
	{
		if (m_c[m_src][u] > 0)
		{
			m_e[u] = m_c[m_src][u];
			m_f[m_src][u] = m_c[m_src][u];
			m_f[u][m_src] = -m_f[m_src][u];
		}
	}

	LInt theList;
	for (u = 0; u < m_n; u++)
	{
		if (u != m_src && u != m_dest)
		{
			theList.push_back(u);
		}
	}

	LIter cur = theList.begin();
	while (cur != theList.end())
	{
		u = (unsigned long)*cur;
		if (discharge(u))
		{
			theList.erase(cur);
			cur = theList.insert(theList.begin(), u);
		}
		cur++;
	}

	m_maxStream = (unsigned long)m_e[m_dest];
}


void CRelabelToFront::PrintResult()
{
	unsigned long i, j;

	cout << "amount vertex: " << to_string(m_edgeCount) << endl;
	for (i = 0; i < m_n; i++)
	{
		for (j = 0; j < m_n; j++)
		{
			cout << m_f[i][j];

			if (j < m_edgeCount - 1)
			{
				cout << "\t";
			}
		}

		cout << endl;
	}

	cout << "\n" << "max stream : " << m_maxStream << endl;
}