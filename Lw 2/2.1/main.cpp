#include "CErrorMessage.h"
#include "CGraph.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

optional<string> ParsingArguments(int argc, char* argv[])
{
	if (argc == 2)
	{
		return argv[1];
	}

	return nullopt;
}

int main(int argc, char* argv[])
{
	auto args = ParsingArguments(argc, argv);

	if (!args)
	{
		return 1;
	}

	ifstream file;
	file.exceptions(std::ifstream::badbit);

	try
	{
		file.open(*args, ios_base::in);
		CGraph graph(file);
		graph.FindPointsAndBridges();
		graph.PrintPointsAndBridges();
	}
	catch (const ios_base::failure& e)
	{
		cout << e.what() << '\n';
		return 1;
	}
	catch (CErrorMessage e)
	{
		cout << e.GetErrorMessage() << '\n';
		return 1;
	}

	return 0;
}