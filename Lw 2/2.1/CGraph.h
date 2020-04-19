#pragma once
#include <fstream>
#include <vector>
#include <map>

class CGraph
{
public:
	CGraph(std::istream& in);
	void AdjacencyMatrixInitialization();
	void UploadGraph(std::istream& in);
	void AddBridges(int v, int to);
	void AddPoint(int v);
	void DFS(int v, int p = -1);
	void FindBridges();
	void PrintBridgesAndPoints();

private:
	struct Bridge
	{
		int start;
		int end;
	};

	int timer;
	int edgesCount;
	int pointsCount;

	std::vector<int> tin, fup;
	std::vector<bool> used;
	std::vector<std::vector<int>> AdjacencyMatrix;
	std::vector<Bridge> junctionBridges;
	std::vector<int> junctionPoints;

	static const size_t NUMBER_INPUT_PARAMETERS = 2;
	static const size_t MAX_POINTS_COUNT = 400;
	static const size_t MAX_EDGES_COUNT = CGraph::MAX_POINTS_COUNT * (CGraph::MAX_POINTS_COUNT - 1) / 2;
};