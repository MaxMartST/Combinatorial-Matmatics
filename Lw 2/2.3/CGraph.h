#pragma once

#include <string>
#include <vector>

class CGraph
{
public:
	CGraph(std::istream& in);
	int GetNumberOfVertices() const { return numberOfVertices; }
	std::vector<std::vector<int>> GetAdjacencyMatrix() { return adjacencyMatrix; }

private:
	template <class T>
	std::vector<T> ConvertStringToVector(std::string& line);
	std::vector<std::vector<int>> adjacencyMatrix;
	int numberOfVertices;

	void UploadGraph(std::istream& in);

	static const size_t NUMBER_INPUT_PARAMETERS = 1;
	static const size_t MAX_POINTS_COUNT = 15;
};