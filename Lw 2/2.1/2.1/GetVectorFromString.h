#pragma once
#include <iterator>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::size_t> ConvertStringToVector(std::string line)
{
	std::istringstream stringIterator(line);
	return std::vector<size_t>(std::istream_iterator<size_t>(stringIterator), std::istream_iterator<size_t>());
}