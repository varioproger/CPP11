#include "../algostuff.hpp"
using namespace std;
using namespace std::placeholders;

/*
• replace_copy() is a combination of copy() and replace(). 
  It replaces each element in the source range [sourceBeg,sourceEnd) that is equal to oldValue with newValue while the elements
  are copied into the destination range starting with destBeg.

• replace_copy_if() is a combination of copy() and replace_if(). 
  It replaces each element in the source range [sourceBeg,sourceEnd) for which the unary predicate op(elem)
  yields true with newValue while the elements are copied into the destination range starting with destBeg.

• Both algorithms return the position after the last copied element in the destination range 
  (the first element that is not overwritten).
*/
int main()
{
	list<int> coll;
	INSERT_ELEMENTS(coll, 2, 6);
	INSERT_ELEMENTS(coll, 4, 9);
	PRINT_ELEMENTS(coll);
	// print all elements with value 5 replaced with 55
	replace_copy(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " "), // destination
		5, // old value
		55); // new value
	cout << endl;
	// print all elements with a value less than 5 replaced with 42
	replace_copy_if(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " "), // destination
		bind(less<int>(), _1, 5), // replacement criterion
		42); // new value
	cout << endl;
	// print each element while each odd element is replaced with 0
	replace_copy_if(coll.cbegin(), coll.cend(), // source
		ostream_iterator<int>(cout, " "), // destination
		[](int elem) { // replacement criterion
			return elem % 2 == 1;
		},
		0); // new value
	cout << endl;
}