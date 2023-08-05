#include "../algostuff.hpp"
using namespace std;
/*
Unlike the previous example of rotate() , here a set is used instead of a vector.
This has two consequences :
1. You must use advance() or next()  to change the value of the iterator,
   because bidirectional iterators do not provide operator +.

2. You should use the find() member function instead of the find() algorithm, because the former has better performance.
*/
int main()
{
	set<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll);
	// print elements rotated one element to the left
	set<int>::const_iterator pos = next(coll.cbegin());
	rotate_copy(coll.cbegin(), // beginning of source
		pos, // new first element
		coll.cend(), // end of source
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;
	// print elements rotated two elements to the right
	pos = coll.cend();
	advance(pos, -2);
	rotate_copy(coll.cbegin(), // beginning of source
		pos, // new first element
		coll.cend(), // end of source
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;
	// print elements rotated so that element with value 4 is the beginning
	rotate_copy(coll.cbegin(), // beginning of source
		coll.find(4), // new first element
		coll.cend(), // end of source
		ostream_iterator<int>(cout, " ")); // destination
	cout << endl;
}
