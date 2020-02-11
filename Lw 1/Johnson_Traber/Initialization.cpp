#include "Initialization.h"

void initVectors(vector<size_t> &myP, vector<size_t> &myR, vector<int> &myD, int myN)
{
	int m = myN + 1;
	int pSize = myN + 2;

	// инициализация вектора перестановок(myP)
	for (int i = 0; i < pSize; i++)
	{
		if (!i || i == pSize - 1)
		{
			myP.push_back(m);
			continue;
		}
		myP.push_back(i);
	}

	// инициализация вектора направления движения(myD) и позиций(myR)
	// вектор myD: движение влево -> -1; движение вправо -> 1; не сдвигается -> 0 
	for (int i = 0; i < m; i++)
	{
		if (!i || i == 1)
		{
			myD.push_back(0);
			if (!i)
			{
				myR.push_back(0); 
				continue;
			}
			myR.push_back(i);
			continue;
		}
		myD.push_back(-1);
		myR.push_back(i);
	}
}