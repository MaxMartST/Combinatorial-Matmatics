#include "pch.h"
#include "CErrorMessage.h"
#include "CGraph.h"
#include "CTaryana.h"

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
		CTaryana taryana(graph, cout);

		taryana.StronglyConnectedGraph();
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