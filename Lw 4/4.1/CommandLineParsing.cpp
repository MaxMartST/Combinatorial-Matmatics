#include "CommandLineParsing.h"

using namespace std;

void CommandLineParsing(int argc, char* argv[], string& fileName)
{
	if (argc == 2)
	{
		fileName = argv[1];
	}
	else
	{
		throw invalid_argument("ERROR: Invalid argument. Use program.exe file.txt");
	}
}