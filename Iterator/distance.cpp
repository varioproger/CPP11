#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/*
Dist distance (InputIterator pos1, InputIterator pos2)
• Returns the distance between the input iterators pos1 and pos2.
• Both iterators have to refer to elements of the same container.
• If the iterators are not random-access iterators, pos2 must be reachable from pos1; that is, it must
have the same position or a later position.
• The return type, Dist, is the difference type according to the iterator type:
iterator_traits<InputIterator>::difference_type
*/
int main()
{
	list<int> coll;
	// insert elements from -3 to 9
	for (int i = -3; i <= 9; ++i) {
		coll.push_back(i);
	}
	// search element with value 5
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), // range
		5); // value
	if (pos != coll.end()) {
		// process and print difference from the beginning
		cout << "difference between beginning and 5: "
			<< distance(coll.begin(), pos) << endl;
	}
	else {
		cout << "5 not found" << endl;
	}

	/*
	After find() assigns the position of the element with value 5 to pos, distance() uses this position
	to process the difference between this position and the beginning.
	*/
}
