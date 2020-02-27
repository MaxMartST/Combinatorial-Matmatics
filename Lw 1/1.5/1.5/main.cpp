#include <boost/timer.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

class MyClass
{
public:
	MyClass(int k, int n);
	void GetInitialization();
	void GetCombination();
	void PrintParam();

private:
	int elementsCombination;
	int numberElements;
	std::vector<int> сombination;
};

MyClass::MyClass(int k, int n)
{
	elementsCombination = k;
	numberElements = n;
}

void MyClass::GetInitialization()
{
	сombination.resize(elementsCombination + 1);
	сombination.at(0) = -1;
	std::iota(сombination.begin() + 1, сombination.end(), 1);
}

void MyClass::GetCombination()
{
	boost::timer time;
	int m = 1;
	int count = 0;

	time.restart();
	while (m != 0)
	{
		std::vector<int> permutation = сombination;
		do
		{
			//copy(permutation.begin() + 1, permutation.end(), std::ostream_iterator<int>(std::cout, " "));
			//std::cout << std::endl;
		} while (next_permutation(permutation.begin() + 1, permutation.end()));

		m = elementsCombination;
		while (сombination.at(m) == numberElements - elementsCombination + m)
		{
			--m;
		}
		++сombination.at(m);
		for (int i = m + 1; i <= elementsCombination; ++i)
		{
			сombination.at(i) = сombination.at(i - 1) + 1;
		}
	}
	double duration = time.elapsed();
	std::cout << duration << std::endl;
}

void CheckForNegativeSize(int first, int second)
{
	if ((first < 0) || (second < 0))
	{
		throw std::exception("arguments must not be less than zero");
	}
	if (first > second)
	{
		throw std::exception("invalid count of arguments: argv[1] > argv[2]");
	}
}

std::optional<MyClass> CheckArgument(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Error: use two arguments " << std::endl;
		return std::nullopt;
	}

	int firstArg, secondArg;
	try
	{
		firstArg = std::stoi(argv[1]);
		secondArg = std::stoi(argv[2]);
		CheckForNegativeSize(firstArg, secondArg);
		MyClass args(firstArg, secondArg);
		return args;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Error: " << e.what() << ". Argument must be a number" << std::endl;
		return std::nullopt;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return std::nullopt;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return std::nullopt;
	}
}

int main(int argc, char* argv[])
{
	auto content = CheckArgument(argc, argv);

	if (!content)
	{
		return 1;
	}
	
	content->GetInitialization();
	content->GetCombination();

	return 0;
}