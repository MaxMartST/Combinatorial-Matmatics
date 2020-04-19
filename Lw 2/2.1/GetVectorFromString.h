#pragma once

#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <class T>
std::vector<T> ConvertStringToVector(std::string& line)
{
	std::istringstream stringIterator(line);
	return std::vector<T>(std::istream_iterator<T>(stringIterator), std::istream_iterator<T>());
}