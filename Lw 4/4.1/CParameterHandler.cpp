#include "CParameterHandler.h"

using namespace std;

void CParameterHandler::SetParametersFromFile(const string &fileName)
{
	ifstream file;
	file.exceptions(ifstream::badbit);
	try
	{
		file.open(fileName, ios_base::in);
		SetNumberVertex(file);
		SetVertex(file);
	}
	catch (const ios_base::failure&)
	{
		throw ("ERROR: Specified file [" + fileName + "] not found!\n");
	}
	catch (const invalid_argument&)
	{
		throw;
	}
	catch (const out_of_range&)
	{
		throw;
	}
}

bool IsCharNumberCorrect(char ch)
{
	return isdigit(ch);
}

void CheckTheNumberOfVertex(string &numbel)
{
	if (numbel.empty())
	{
		throw invalid_argument("ERROR: The number of graph vertices is not specified!\n");
	}

	string::iterator it = numbel.begin();

	if (!all_of(it, numbel.end(), [](char ch) { return IsCharNumberCorrect(ch); }))
	{
		throw invalid_argument("ERROR: Invalid number vertex!\n");
	}
}

unsigned int ConvertStringToUnsignedInt(string& line)
{
	try
	{
		return stoi(line, nullptr, 10);
	}
	catch (const invalid_argument&)
	{
		throw invalid_argument("ERROR: No conversion could be performed!\n");
	}
	catch (const out_of_range&)
	{
		throw out_of_range("ERROR: Converted value would fall out of the range of the result type!\n");
	}
}

string RemoveExtraSpacesInLine(const string& line)
{
	if (line.empty())
	{
		return line;
	}

	istringstream ist(line);
	ostringstream ost;

	copy(istream_iterator<std::string>(ist), istream_iterator<std::string>(), ostream_iterator<string>(ost, " "));
	string resultStr = ost.str();

	size_t size = resultStr.size();

	if (size > 1 && resultStr[size - 1] == ' ')
	{
		resultStr.erase(size - 1, 1);
	}

	return resultStr;
}

void CParameterHandler::SetNumberVertex(ifstream& file)
{
	string line;
	vector<string> parameters;

	getline(file, line);
	string rsult = RemoveExtraSpacesInLine(line);

	CheckTheNumberOfVertex(rsult);
	unsigned int amount = ConvertStringToUnsignedInt(line);

	if (amount < MIN_DRODER && MAX_DRODER < amount)
	{
		throw out_of_range("ERROR: Converted value would fall out of the range of the result type!\n");
	}

	this->m_amountVertex = amount;
	m_vertex.resize(this->m_amountVertex);
}

bool IsCharVertexCorrect(char ch)
{
	return isdigit(ch) || ch == '.';
}

void CheckTheValueOfVertex(std::vector<std::string> &coordinate)
{
	if (coordinate.empty())
	{
		throw invalid_argument("ERROR: No arguments!\n");
	}

	if (coordinate.size() != 5)
	{
		throw invalid_argument("ERROR: Use five parameter!\n");
	}

	for (string str : coordinate)
	{
		string::iterator it = str.begin();

		if (*it == '.')
		{
			throw invalid_argument("ERROR: Invalid number vertex!\n");
		}

		if (*it == '-')
		{
			it++;
		}

		if (!all_of(it, str.end(), [](char ch) { return IsCharVertexCorrect(ch); }))
		{
			throw invalid_argument("ERROR: Invalid number vertex!\n");
		}
	}
}

double  ConvertStringToFloat(std::string& line)
{
	try
	{
		return stod(line);
	}
	catch (const invalid_argument&)
	{
		throw invalid_argument("ERROR: No conversion could be performed!\n");
	}
	catch (const out_of_range&)
	{
		throw out_of_range("ERROR: Converted value would fall out of the range of the result type!\n");
	}
}

void CParameterHandler::SetVertex(ifstream& file)
{
	string line;
	vector<string> parameters;
	size_t count = 0;

	while (getline(file, line))
	{
		string rsult = RemoveExtraSpacesInLine(line);
		boost::split(parameters, rsult, boost::is_any_of(" "));

		CheckTheValueOfVertex(parameters);

		if (parameters.size() != m_amountVertex)
		{
			throw out_of_range("ERROR: Incorrect number of vertices!\n");
		};

		for (size_t i = 0; i < m_amountVertex; i++)
		{
			m_vertex.at(count).push_back(ConvertStringToFloat(parameters[i]));
		}

		count++;
	}

	if (count != m_amountVertex)
	{
		throw out_of_range("ERROR: Incorrect number of vertices!\n");
	}
}