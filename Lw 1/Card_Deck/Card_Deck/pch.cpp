#include "pch.h"

void PrintCardDeck(std::vector<int> myV)
{
	copy(myV.begin(), myV.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

void ShuffleCardDeck(std::vector<int> &myV, std::mt19937 myG)
{
	std::shuffle(myV.begin(), myV.end(), myG);
}