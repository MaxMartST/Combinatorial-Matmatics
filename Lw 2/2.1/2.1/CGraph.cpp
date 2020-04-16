#include "CGraph.h"
#include "CErrorMessage.h"
#include "GetVectorFromString.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

Graph::Graph(istream& in)
{
	this->UploadGraph(in);
}

void Graph::AdjacencyMatrixInitialization()
{
	for (size_t i = 0; i < pointsCount; i++)
	{
		AdjacencyMatrix.push_back(vector<size_t>());
		for (size_t j = 0; j < pointsCount; j++)
		{
			AdjacencyMatrix[i].push_back(0);
		}
	}
}

void Graph::UploadGraph(istream& in)
{
	string line;
	if (getline(in, line))
	{
		vector<size_t> params = ConvertStringToVector(line);
		if (params.size() != Graph::NUMBER_INPUT_PARAMETERS)
		{
			throw CErrorMessage("ERROR: One of the subsets is missing");
		}

		if (!(params[0] <= Graph::MAX_POINTS_COUNT && params[1] <= Graph::MAX_EDGES_COUNT))
		{
			throw CErrorMessage("ERROR: Intersection of the allowable range");
		}
		this->pointsCount = params[0];
		this->edgesCount = params[1];
	}

	this->timer = 0;
	this->used.assign(pointsCount, false);
	this->fup.resize(pointsCount);
	this->tin.reserve(pointsCount);

	AdjacencyMatrixInitialization();

	size_t edgesCount = 0;
	vector<size_t> params;
	while (getline(in, line))
	{
		params = ConvertStringToVector(line);
		if (params.size() != Graph::NUMBER_INPUT_PARAMETERS)
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