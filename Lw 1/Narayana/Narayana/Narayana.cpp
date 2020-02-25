#include "stdafx.h"
#include <boost/timer.hpp>

using namespace std;

void initVector(vector<size_t> &Val)
{
	int length;
	unordered_set<int> uSet;
	cout << "Укажите размер порядка: ";
	cin >> length;

	default_random_engine dre(time(nullptr));
	uniform_int_distribution<> uid(1, 100);

	while (uSet.size() != length)
		uSet.insert(uid(dre));

	for (int value : uSet)
		Val.push_back(value);
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	int count = 0;
	vector<size_t> v;
	initVector(v);

	boost::timer t;
	sort(v.begin(), v.end());
	t.restart();
	do
	{
		//copy(v.begin(), v.end(), std::ostream_iterator<size_t>(cout, " "));
		//cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	double duration = t.elapsed();
	cout << duration << endl;

	return 0;
}

