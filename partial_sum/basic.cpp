#include "../algostuff.hpp"
using namespace std;
int main()
{
	vector<int> coll;
	INSERT_ELEMENTS(coll, 1, 6);
	PRINT_ELEMENTS(coll);
	// a1, a1 + a2, a1 + a2 + a3, ...
	// print all partial sums
	// partial sum for each element in the source range
	partial_sum(coll.cbegin(), coll.cend(), // source range
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;

	// a1, a1 op a2, a1 op a2 op a3, ...
	// print all partial products
	// calls op for each element in the source range
	partial_sum(coll.cbegin(), coll.cend(), // source range
		ostream_iterator<int>(cout, " "), // destination
		multiplies<int>()); // operation
	cout << endl;

/*
Both forms return the position after the last written value in the destination range (the first element that is not overwritten).
*/
}