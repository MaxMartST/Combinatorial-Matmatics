#include "CheckParameters.h"

using namespace std;

bool IsCharNumberCorrect(char ch)
{
	return isdigit(ch);
}

bool IsCharCoordinateCorrect(char ch)
{
	return isdigit(ch) || ch == '.';
}

void CheckNumberVertex(vector<string> &numbel)
{
	if (numbel.empty())
	{
		throw invalid_argument("ERROR: No arguments!\n");
	}

	if (numbel.size() != 1)
	{
		throw invalid_argument("ERROR: Use one parameter!\n");
	}

	string::iterator it = numbel[0].begin();

	if (!all_of(it, numbel[0].end(), [](char ch) { return IsCharNumberCorrect(ch); }))
	{
		throw invalid_argument("ERROR: Invalid number vertex!\n");
	}
}

void CheckCoordinate(std::vector<std::string> &coordinate)
{
	if (coordinate.empty())
	{
		throw invalid_argument("ERROR: No arguments!\n");
	}

	if (coordinate.size() != 2)
	{
		throw invalid_argument("ERROR: Use two parameter!\n");
	}

	for (string str : coordinate)
	{
		string::iterator it = str.begin();

		if (*it == '-')
		{
			it++;
		}

		if (!all_of(it, str.end(), [](char ch) { return IsCharCoordinateCorrect(ch); }))
		{
			throw invalid_argument("ERROR: Invalid number coordinate!\n");
		}
	}
}