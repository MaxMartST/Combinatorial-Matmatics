#include "initialization_vector.h"

void InitVector(std::vector<int> &sequence, std::vector<int> &position, std::vector<int> &direction, const int elem)
{
	for (int number = 1; number <= elem; number++)
	{
		sequence.at(number) = position.at(number) = number;
		direction.at(number) = -1;
	}
	direction.at(1) = 0;
}