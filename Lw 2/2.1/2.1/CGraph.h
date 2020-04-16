#pragma once
#include <fstream>
#include <vector>

class Graph
{
public:
	Graph(std::istream& in);
	void AdjacencyMatrixInitialization();
	void UploadGraph(std::istream& in);
	void PrintAdjacencyMatrix();

private:
	int timer;
	size_t edgesCount;
	size_t pointsCount;

	std::vector<int> tin, fup;
	std::vector<bool> used;
	std::vector<std::vector<size_t>> AdjacencyMatrix;

	static const size_t NUMBER_INPUT_PARAMETERS = 2;
	static const size_t MAX_POINTS_COUNT = 400;
	static const size_t MAX_EDGES_COUNT = Graph::MAX_POINTS_COUNT * (Graph::MAX_POINTS_COUNT - 1) / 2;
};
