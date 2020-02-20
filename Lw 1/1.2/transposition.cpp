#include "transposition.h"

void GetTransposition(std::vector<int>& sequence, std::vector<int>& position, std::vector<int>& direction, const int elements)
{
	boost::timer t;
	int m = elements + 1;

	t.restart();
	while (m != 1)
	{
		std::copy(sequence.begin() + 1, sequence.end() - 1, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		m = elements;

		while (sequence.at(position.at(m) + direction.at(m)) > m)
		{
			direction.at(m) = -direction.at(m);
			m = m - 1;
		}

		std::swap(sequence.at(position.at(m)), sequence.at(position.at(m) + direction.at(m)));
		std::swap(position.at(sequence.at(position.at(m))), position.at(m));
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;
}