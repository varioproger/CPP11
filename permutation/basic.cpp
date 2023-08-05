#include "../algostuff.hpp"
using namespace std;
/*
• next_permutation() changes the order of the elements in [beg,end) according to the next permutation.

• prev_permutation() changes the order of the elements in [beg,end) according to the previous permutation.

• The first forms compare the elements by using operator <.

• The second forms compare the elements by using the binary predicate op(elem1,elem2)
  which should return true if elem1 is “less than” elem2.

• Both algorithms return false if the elements got the “normal” (lexicographical) order: 
  that is, ascending order for next_permutation() and descending order for prev_permutation().
  So, to run through all permutations, you have to sort all elements (ascending or descending),
  and start a loop that calls next_permutation() or prev_permutation() as long as these algorithms return true.
*/
int main()
{
	vector<int> coll;
	INSERT_ELEMENTS(coll, 1, 3);
	PRINT_ELEMENTS(coll, "on entry: ");
	// permute elements until they are sorted
	// - runs through all permutations because the elements are sorted now
	while (next_permutation(coll.begin(), coll.end())) {
		PRINT_ELEMENTS(coll, " ");
	}
	PRINT_ELEMENTS(coll, "afterward: ");
	// permute until descending sorted
	// - this is the next permutation after ascending sorting
	// - so the loop ends immediately
	while (prev_permutation(coll.begin(), coll.end())) {
		PRINT_ELEMENTS(coll, " ");
	}
	PRINT_ELEMENTS(coll, "now: ");
	// permute elements until they are sorted in descending order
	// - runs through all permutations because the elements are sorted in descending order now
	while (prev_permutation(coll.begin(), coll.end())) {
		PRINT_ELEMENTS(coll, " ");
	}
	PRINT_ELEMENTS(coll, "afterward: ");
}