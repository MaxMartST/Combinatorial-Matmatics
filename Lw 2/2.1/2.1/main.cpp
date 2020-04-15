#include <algorithm>
#include <iostream>

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

int main()
{
	find_bridges();
	return 0;
}