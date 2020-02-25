#include "pch.h"
#include "check_args.h"
#include "initialization_vector.h"
#include "transposition.h"

int main(int argc, char *argv[])
{
	if (!CheckArgs(argc, argv))
	{
		return 1;
	}

	int elements = atoi(argv[1]);
	std::vector<int> sequence(elements + 2, elements + 1);
	std::vector<int> position(elements + 1, 0);
	std::vector<int> direction(elements + 1, 0);

	InitVector(sequence, position, direction, elements);
	GetTransposition(sequence, position, direction, elements);

	return 0;
}