#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
using namespace std::placeholders;

template <typename T1, typename T2>
struct fopow
{
	T1 operator() (T1 base, T2 exp) const {
		return std::pow(base, exp);
	}
};

int main()
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// print 3 raised to the power of all elements
	transform(coll.begin(), coll.end(), // source
		ostream_iterator<float>(cout, " "),// destination
		bind(fopow<float, int>(), 3, _1)); // operation
	cout << endl;
	// print all elements raised to the power of 3
	transform(coll.begin(), coll.end(), // source
		ostream_iterator<float>(cout, " "), // destination
		bind(fopow<float, int>(), _1, 3)); // operation
	cout << endl;
}