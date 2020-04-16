#define _GLIBCXX_USE_CXX11_ABI 0
#include "CErrorMessage.h"
#include "CGraph.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

int const n = 5; // chislo vershin v grafe
int timer, tin[n], fup[n];
bool used[n];
int mx[n][n] = {
	{ 0, 1, 0, 0, 0 },
	{ 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 1 },
	{ 0, 0, 1, 1, 0 }
};

void dfs(int v, int p = -1) // poisk v glubinu
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < n; ++i)
	{
		if (mx[v][i] == 1)
		{
			int to = i;
			if (to == p)
				continue;
			if (used[to])
				fup[v] = std::min(fup[v], tin[to]);
			else
			{
				dfs(to, v);
				fup[v] = std::min(fup[v], fup[to]);
				if (fup[to] > tin[v])
					std::cout << "bridge: (" << v << " , " << to << ")\n";
			}
		}
	}
}

void find_bridges() // poisk mostov
{
	timer = 0;
	for (int i = 0; i < n; ++i)
	{
		used[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
			dfs(i);
	}
}

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
	//find_bridges();
	auto args = ParsingArguments(argc, argv);

	if (!args)
	{
		return 1;
	}

	ifstream file;
	//file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.exceptions(std::ifstream::badbit);

	try
	{
		file.open(*args, ios_base::in);
		Graph graph(file);
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

	cout << "Exit\n";

	return 0;
}