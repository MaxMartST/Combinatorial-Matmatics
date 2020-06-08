#include "CParameterHandler.h"
#include "CParameterHandler.h"
#include "CheckParameters.h"

using namespace std;

bool CParameterHandler::SetParametersFromFile(string& fileName)
{
	bool result = true;
	ifstream file;
	file.exceptions(ifstream::badbit);
	try
	{
		file.open(fileName, ios_base::in);
	}
	catch (const ios_base::failure&)
	{
		cout << "ERROR: Specified file [" + fileName + "] not found!\n";
		result = false;
	}

	try
	{
		SetNumberVertex(file);
		Set—oordinates(file);
	}
	catch (const invalid_argument &e)
	{
		cout << e.what();
		result = false;
	}
	catch (const ios_base::failure& e)
	{
		cout << e.what();
		result = false;
	}
	catch (const out_of_range &e)
	{
		cout << e.what();
		result = false;
	}

	return result;
}

void CParameterHandler::SetNumberVertex(ifstream &file)
{
	string line;
	vector<string> parameters;

	getline(file, line);

	line = RemoveExtraSpacesInLine(line);
	boost::split(parameters, line, boost::is_any_of(" "));

	CheckNumberVertex(parameters);
	this->m_numberVertex = ConvertStringToUnsigLong(parameters[0]);
}

void CParameterHandler::Set—oordinates(ifstream& file)
{
	string line;
	vector<string> parameters;
	size_t count = 1;

	while (getline(file, line))
	{
		line = RemoveExtraSpacesInLine(line);
		boost::split(parameters, line, boost::is_any_of(" "));

		CheckCoordinate(parameters);

		double x = ConvertStringToDouble(parameters[0]);
		double y = ConvertStringToDouble(parameters[1]);

		m_vertex.push_back(dt::Vertex<double>{x, y, count});
		count++;
	}

	if (m_vertex.size() != m_numberVertex)
	{
		throw out_of_range("ERROR: The number of vertices [" + to_string(m_vertex.size()) + "] does not match the set value [" + to_string(m_numberVertex) + "]!\n");
	}
}

unsigned long ConvertStringToUnsigLong(std::string& line)
{
	try
	{
		return stoul(line, nullptr, 10);
	}
	catch (invalid_argument&)
	{
		throw new invalid_argument("ERROR: No conversion could be performed!\n");
	}
	catch (out_of_range&)
	{
		throw new out_of_range("ERROR: Converted value would fall out of the range of the result type!\n");
	}
}

double ConvertStringToDouble(std::string& line)
{
	try
	{
		return stod(line);
	}
	catch (invalid_argument&)
	{
		throw new invalid_argument("ERROR: No conversion could be performed!\n");
	}
	catch (out_of_range&)
	{
		throw new out_of_range("ERROR: Converted value would fall out of the range of the result type!\n");
	}
}

string RemoveExtraSpacesInLine(string stringToTrim)
{
	if (stringToTrim.empty())
	{
		return stringToTrim;
	}

	boost::trim(stringToTrim);
	for (string::iterator it = stringToTrim.begin(); it != stringToTrim.end(); it++)
	{
		string::iterator begin = it;
		while (it != stringToTrim.end() && isspace(*it))
		{
			it++;
		}
		if (it - begin > 1)
		{
			it = stringToTrim.erase(begin + 1, it) - 1;
		}
	}

	return stringToTrim;
}

rsize_t CParameterHandler::IsEmpty()
{
	return m_vertex.empty();
}