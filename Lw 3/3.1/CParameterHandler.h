#pragma once
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "Vertex.h"
#include <boost/noncopyable.hpp>
#include <boost/algorithm/string.hpp>

class CParameterHandler
{
public:
	CParameterHandler() = default;
	bool SetParametersFromFile(std::string& fileName);
	std::vector<dt::Vertex<double>> GetVertex()
	{
		return m_vertex;
	};
	size_t IsEmpty();

private:
	const size_t NUMBERPARAM = 2;
	unsigned long  m_numberVertex = 0;

	std::vector<dt::Vertex<double>> m_vertex;
	void SetNumberVertex(std::ifstream& file);
	void Set—oordinates(std::ifstream& file);
};

template <class T>
std::vector<T> ConvertStringToVector(std::string& line)
{
	std::istringstream stringIterator(line);
	return std::vector<T>(std::istream_iterator<T>(stringIterator), std::istream_iterator<T>());
}

std::string RemoveExtraSpacesInLine(std::string stringToTrim);
unsigned long ConvertStringToUnsigLong(std::string& line);
double ConvertStringToDouble(std::string& line);