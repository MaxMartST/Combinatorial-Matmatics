#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <numeric>
#include <optional>
#include <random>
#include <string>
#include <vector>

class MyClass
{
public:
	MyClass(int namber);
	int GetNamber();
	void GetRandomPermutation();
	void GetSequence();

private:
	int quantity;
	std::vector<int> sequence;
};

MyClass::MyClass(int namber)
{
	quantity = namber;
}

int MyClass::GetNamber()
{
	return quantity;
}

void MyClass::GetRandomPermutation()
{
	std::random_device rd;
	std::uniform_int_distribution<int> g(0, quantity);
	sequence.resize(quantity);
	std::iota(sequence.begin(), sequence.end(), 1);

	for (int i = 0; i < quantity; ++i)
	{
		const int randomPosition = g(rd) % quantity;
		std::swap(sequence.at(i), sequence.at(randomPosition));
	}
}

void MyClass::GetSequence()
{
	copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

void CheckForNegativeSize(int sizeVector)
{
	if (sizeVector < 0)
	{
		throw std::exception("size cannot be less than zero");
	}
}

std::optional<MyClass> CheckArgument(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Use one argument - a positive integer " << std::endl;
		return std::nullopt;
	}

	int temp;
	try
	{
		temp = std::stoi(argv[1]);
		CheckForNegativeSize(temp);
		MyClass args(temp);
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
	auto args = CheckArgument(argc, argv);

	if (!args)
	{
		return 1;
	}

	args->GetRandomPermutation();
	args->GetSequence();

	return 0;
}