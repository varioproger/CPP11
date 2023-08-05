#include "../algostuff.hpp"
using namespace std;
int main()
{
	deque<int> coll;
	INSERT_ELEMENTS(coll, 1, 6);
	PRINT_ELEMENTS(coll);

	// a1, a2 - a1, a3 - a2, a4 - a3, ...
	// print all differences between elements
	adjacent_difference(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;

	// a1, a2 op a1, a3 op a2, a4 op a3, ...
	// print all sums with the predecessors
	adjacent_difference(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " "), // destination
		plus<int>()); // operation
	cout << endl;

	// a1, a2 op a1, a3 op a2, a4 op a3, ...
	// print all products between elements
	adjacent_difference(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " "), // destination
		multiplies<int>()); // operation
	cout << endl;
}
