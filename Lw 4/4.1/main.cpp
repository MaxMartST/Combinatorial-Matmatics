#include "pch.h"
#include "CommandLineParsing.h"
#include "CParameterHandler.h"
#include "CRelabelToFront.h"

using namespace std;

int main(int argc, char *argv[])
{
	string fileName;
	CParameterHandler ph;
	try
	{
		CommandLineParsing(argc, argv, fileName);
		ph.SetParametersFromFile(fileName);
		CRelabelToFront rf(ph.GetAmountVertex(), ph.GetVertex());
		rf.Ltf();
		rf.PrintResult();
	}
	catch (const exception& e)
	{
		cout << e.what();
		return 1;
	}

	return 0;
}