#include "stdafx.h"
#include "Initialization.h"
#include <boost/timer.hpp>

using namespace std;
using namespace boost;

int main()
{
	setlocale(LC_CTYPE, "rus");
	vector<size_t> p, r;
	vector<int> d;
	int m, n;
	timer t;

	cout << "Укажите размер порядка: ";
	cin >> n;

	initVectors(p, r, d, n);
	m = n + 1;

	t.restart();
	while (m != 1)
	{
		copy(p.begin() + 1, p.end() - 1, ostream_iterator<size_t>(cout, " "));
		cout << endl;
		m = n;

		while (p.at(r.at(m) + d.at(m)) > m)
		{
			d.at(m) = -d.at(m);
			m = m - 1;
		}

		swap(p.at(r.at(m)), p.at(r.at(m) + d.at(m)));
		swap(r.at(p.at(r.at(m))), r.at(m));
	}

	double duration = t.elapsed();
	cout << duration << endl;

	return 0;
}