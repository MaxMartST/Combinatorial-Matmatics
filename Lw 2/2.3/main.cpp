#include "pch.h"
#include "CBranchAndBorder.h"
#include "CErrorMessage.h"
#include "CGraph.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "invalid number of arguments on the command line" << endl;
		return 1;
	}

	ifstream file;
	file.exceptions(ifstream::badbit);

	try
	{
		file.open(argv[1], ios_base::in);
		CGraph graph(file);
		CBranchAndBorder branchAndBorder(graph, cout);
		branchAndBorder.FindHamiltonianCycle();
		branchAndBorder.PrintHamiltonianCycle();
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