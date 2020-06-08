#include "CommandLineParsing.h"

void ParsingFileNameForDictionary(int argc, char* argv[], std::string& fileName)
{
	if (argc == 2)
	{
		fileName = argv[1];
	}
	else
	{
		throw std::invalid_argument("ERROR: Invalid argument. Use program.exe file.txt");
	}
}