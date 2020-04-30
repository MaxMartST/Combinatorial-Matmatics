#include "pch.h"
#include "CGraph.h"
#include "CErrorMessage.h"

using namespace std;

CGraph::CGraph(istream& in)
{
	this->UploadGraph(in);
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

		if (!(params[0] <= CGraph::MAX_POINTS_COUNT))
		{
			throw CErrorMessage("ERROR: Intersection of the allowable range");
		}

		this->numberOfVertices = params[0];
	}

	size_t numberOfVertices = 0;
	vector<int> params;

	while (getline(in, line))
	{
		params = ConvertStringToVector<int>(line);
		if (params.size() != this->numberOfVertices)
		{
			throw CErrorMessage("ERROR: One of the subsets is missing");
		}

		adjacencyMatrix.push_back(params);

		++numberOfVertices;
	}

	if (!in.eof())
	{
		throw CErrorMessage("ERROR: Input error");
	}

	if (numberOfVertices != this->numberOfVertices)
	{
		throw CErrorMessage("ERROR: Invalid edges count");
	}
}

template <class T>
vector<T> CGraph::ConvertStringToVector(string& line)
{
	istringstream stringIterator(line);
	return vector<T>(istream_iterator<T>(stringIterator), istream_iterator<T>());
}