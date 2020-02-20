#include "check_args.h"

bool CheckArgs(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "use one argument" << std::endl;
		return false;
	}

	if (!atoi(argv[1]))
	{
		std::cout << "invalid argument or equal to zero" << std::endl;
		return false;
	}

	return true;
}