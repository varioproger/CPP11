#include "../algostuff.hpp"
using namespace std;
/*
• Rotates elements in the range [beg,end) so that *newBeg is the new first element after the call.

• Since C++11, returns beg+(end-newbeg), which is the new position of the first element. Before C++11, the return type was void.

• The caller must ensure that newBeg is a valid position in the range [beg,end); 
  otherwise, the call results in undefined behavior
*/
int main()
{
	vector<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");
	// rotate one element to the left
	rotate(coll.begin(), // beginning of range
		coll.begin() + 1, // new first element
		coll.end()); // end of range
	PRINT_ELEMENTS(coll, "one left: ");
	// rotate two elements to the right
	rotate(coll.begin(), // beginning of range
		coll.end() - 2, // new first element
		coll.end()); // end of range
	PRINT_ELEMENTS(coll, "two right: ");
	// rotate so that element with value 4 is the beginning
	rotate(coll.begin(), // beginning of range
		find(coll.begin(), coll.end(), 4), // new first element
		coll.end()); // end of range
	PRINT_ELEMENTS(coll, "4 first: ");
}