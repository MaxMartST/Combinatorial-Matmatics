#include "CGraph.h"
#include "CErrorMessage.h"
#include "GetVectorFromString.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

CGraph::CGraph(istream& in)
{
	this->UploadGraph(in);
}

void CGraph::AdjacencyMatrixInitialization()
{
	for (size_t i = 0; i < this->pointsCount; i++)
	{
		AdjacencyMatrix.push_back(vector<int>());
		for (size_t j = 0; j < this->pointsCount; j++)
		{
			AdjacencyMatrix[i].push_back(0);
		}
	}
}

void CGraph::UploadGraph(istream& in)
{
	string line;
	if (getline(in, line))
	{
		vector<int> params = ConvertStringToVector<int>(line);
		if (params.size() != CGraph::NUMBER_INPUT_PARAMETERS)
		{
			throw CErrorMessage("ERROR: One of the subsets is missing");
		}

		if (!(params[0] <= CGraph::MAX_POINTS_COUNT && params[1] <= CGraph::MAX_EDGES_COUNT))
		{
			throw CErrorMessage("ERROR: Intersection of the allowable range");
		}
		this->pointsCount = params[0];
		this->edgesCount = params[1];
	}

	this->timer = 0;
	this->used.assign(pointsCount, false);
	this->fup.resize(pointsCount);
	this->tin.resize(pointsCount);

	AdjacencyMatrixInitialization();

	size_t edgesCount = 0;
	vector<int> params;

	while (getline(in, line))
	{
		params = ConvertStringToVector<int>(line);
		if (params.size() != CGraph::NUMBER_INPUT_PARAMETERS)
		{
			throw CErrorMessage("ERROR: One of the subsets is missing");
		}

		AdjacencyMatrix[params[0] - 1][params[1] - 1] = 1;
		AdjacencyMatrix[params[1] - 1][params[0] - 1] = 1;

		++edgesCount;
	}

	if (!in.eof())
	{
		throw CErrorMessage("ERROR: Input error");
	}

	if (edgesCount != this->edgesCount)
	{
		throw CErrorMessage("ERROR: Invalid edges count");
	}
}

void CGraph::AddBridges(int v, int to)
{
	Bridge bridge(v, to);

	junctionBridges.push_back(bridge);
}

void CGraph::AddPoint(int v)
{
	auto it = find(junctionPoints.begin(), junctionPoints.end(), v);

	if (it == junctionPoints.end())
	{
		junctionPoints.push_back(v);
	}
}

void CGraph::DFS(int v, int p)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;

	for (int i = 0; i < pointsCount; ++i)
	{
		if (AdjacencyMatrix[v][i] == 1)
		{
			int to = i;

			if (to == p)
			{
				continue;
			}

			if (used[to])
			{
				fup[v] = min(fup[v], tin[to]);
			}
			else
			{
				++children;
				DFS(to, v);
				fup[v] = min(fup[v], fup[to]);

				if (fup[to] > tin[v])
				{
					AddBridges(v, to);
				}

				if (fup[to] >= tin[v] && p != -1)
				{
					AddPoint(v);
				}
			}
		}
	}
	if (p == -1 && children > 1)
	{
		AddPoint(v);
	}
}

void CGraph::FindPointsAndBridges()
{
	for (int i = 0; i < this->pointsCount; ++i)
	{
		if (!used[i])
		{
			DFS(i);
		}
	}
}

void CGraph::PrintPointsAndBridges()
{
	if (junctionPoints.empty())
	{
		cout << "There are no points in the graph" << endl;
	}
	else
	{
		cout << "Points:" << endl;
		for (auto value : junctionPoints)
		{
			cout << ++value << " ";
		}
	}

	if (junctionBridges.empty())
	{
		cout << "\nThere are no bridges in the graph" << endl;
	}
	else
	{
		cout << "\nBridges:" << endl;
		for (auto value : junctionBridges)
		{
			cout << ++value.start << " " << ++value.end << endl;
		}
	}
}