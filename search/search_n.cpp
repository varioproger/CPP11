#include "../algostuff.hpp"
using namespace std;
int main()
{
	deque<int> coll;
	coll = { 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	PRINT_ELEMENTS(coll);
	// find three consecutive elements with value 7
	deque<int>::iterator pos;
	pos = search_n(coll.begin(), coll.end(), // range
		3, // count
		7); // value
	// print result
	if (pos != coll.end()) {
		cout << "three consecutive elements with value 7 "
			<< "start with " << distance(coll.begin(), pos) + 1
			<< ". element" << endl;
	}
	else {
		cout << "no four consecutive elements with value 7 found"
			<< endl;
	}
	// There is a nasty problem with the second form of search_n()
	// this kind of searching for elements that match a special criterion does not conform to the rest of the STL.
	// find four consecutive odd elements
	pos = search_n(coll.begin(), coll.end(), // range
		4, // count
		0, // value
		[](int elem, int value) { // criterion
			return elem % 2 == 1;
		});

	// Following the usual concepts of the STL,
	pos = search_n(coll.begin(), coll.end(), // range
		4, // count
		[](int elem) { // criterion
			return elem % 2 == 1;
		});

	// print result
	if (pos != coll.end()) {
		cout << "first four consecutive odd elements are: ";
		for (int i = 0; i < 4; ++i, ++pos) {
			cout << *pos << ' ';
		}
	}
	else {
		cout << "no four consecutive elements with value > 3 found";
	}
	cout << endl;
}