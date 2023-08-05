#include "../algostuff.hpp"
using namespace std;
/*
return the range of elements that is equal to value

The range comprises the first and the last position an element with value could get inserted without breaking the sorting of the range[beg, end).

This is equivalent to: make_pair(lower_bound(...),upper_bound(...))
*/
int main()
{
	list<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	INSERT_ELEMENTS(coll, 1, 9);
	coll.sort();
	PRINT_ELEMENTS(coll);
	// print first and last position 5 could get inserted
	pair<list<int>::const_iterator, list<int>::const_iterator> range;
	range = equal_range(coll.cbegin(), coll.cend(),
		5);
	cout << "5 could get position "
		<< distance(coll.cbegin(), range.first) + 1
		<< " up to "
		<< distance(coll.cbegin(), range.second) + 1
		<< " without breaking the sorting" << endl;
}