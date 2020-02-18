#include "pch.h"

int main()
{
	setlocale(LC_CTYPE, "rus");

	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::random_device rd;
	std::mt19937 g(rd());
	int command;

	std::cout << "Колода карт до перестановки:" << "\n";
	PrintCardDeck(v);

	do
	{
		ShuffleCardDeck(v, g);
		std::cout << "\n" << "Колода карт после перестановки:" << "\n";
		PrintCardDeck(v);

		std::cout << "\n" << "Перемешать ещё раз?" << "\n" << "(1 - да | 0 - нет)" << "\n";
		std::cin >> command;
	} while (command);

	return 0;
}