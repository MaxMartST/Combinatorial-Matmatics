#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <boost/noncopyable.hpp>
#include <boost/algorithm/string.hpp>

class CParameterHandler
{
public:
	CParameterHandler() = default;
	void SetParametersFromFile(const std::string &fileName);
	unsigned int GetAmountVertex()
	{
		return m_amountVertex;
	};
	std::vector<std::vector<double>> GetVertex()
	{
		return m_vertex;
	};

private:
	std::vector<std::vector<double>> m_vertex;
	unsigned int m_amountVertex;
	unsigned int MAX_DRODER = 400;
	unsigned int MIN_DRODER = 1;

	void SetNumberVertex(std::ifstream& file);
	void SetVertex(std::ifstream& file);
};

template <class T>
std::vector<T> ConvertStringToVector(std::string& line)
{
	std::istringstream stringIterator(line);
	return std::vector<T>(std::istream_iterator<T>(stringIterator), std::istream_iterator<T>());
}

void CheckTheNumberOfVertex(std::string& numbel);
void CheckTheValueOfVertex(std::vector<std::string> &coordinate);
bool IsCharVertexCorrect(char ch);
bool IsCharNumberCorrect(char ch);
std::string RemoveExtraSpacesInLine(const std::string& line);
unsigned int ConvertStringToUnsignedInt(std::string& line);
double ConvertStringToDouble(std::string& line);
