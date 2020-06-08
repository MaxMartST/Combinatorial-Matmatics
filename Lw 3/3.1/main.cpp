#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include "Vertex.h"
#include "Triangle.h"
#include "CDelaunay.h"
#include "CommandLineParsing.h"
#include "CParameterHandler.h"

using namespace std;

int main(int argc, char * argv[])
{
	string fileName;
	CParameterHandler ph;
	try
	{
		ParsingFileNameForDictionary(argc, argv, fileName);
	}
	catch (const invalid_argument &e)
	{
		cout << e.what();
		return 1;
	}

	if (!ph.SetParametersFromFile(fileName))
	{
		return 1;
	}

	std::vector<dt::Vertex<double>> points = ph.GetVertex();
	dt::CDelaunay<double> triangulation;
	const std::vector<dt::Triangle<double>> triangles = triangulation.Triangulate(points);
	cout << triangles.size() << " triangles generated\n";

	if (triangles.size() != 0)
	{
		for (auto value : triangles)
		{
			cout << value.a->number << " " << value.b->number << " " << value.c->number << "\n";
		}
	}

	return 0;
}