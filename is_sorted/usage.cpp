#include "../algostuff.hpp"
using namespace std;

/*
is_sorted_until (ForwardIterator beg, ForwardIterator end, BinaryPredicate op)
• is_sorted() returns whether the elements in the range [beg,end) are sorted.
• is_sorted()_until returns the position of the first element in the range [beg,end), 
  which breaks the sorting of this range, or end if none.
• The first and third forms use operator < to compare elements. 
  The second and fourth forms use the binary predicate op(elem1,elem2)
  which should return true if elem1 is “less than” elem2.
• If the range is empty or has only one element, the algorithms return true or end, respectively.

*/
int main()
{
	vector<int> coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	PRINT_ELEMENTS(coll1, "coll1: ");
	// check whether coll1 is sorted
	if (is_sorted(coll1.begin(), coll1.end())) {
		cout << "coll1 is sorted" << endl;
	}
	else {
		cout << "coll1 is not sorted" << endl;
	}
	map<int, string> coll2;
	coll2 = { {1,"Bill"}, {2,"Jim"}, {3,"Nico"}, {4,"Liu"}, {5,"Ai"} };
	PRINT_MAPPED_ELEMENTS(coll2, "coll2: ");
	// define predicate to compare names
	auto compareName = [](const pair<int, string>& e1,
		const pair<int, string>& e2) {
			return e1.second < e2.second;
	};
	// check whether the names in coll2 are sorted
	if (is_sorted(coll2.cbegin(), coll2.cend(),
		compareName)) {
		cout << "names in coll2 are sorted" << endl;
	}
	else {
		cout << "names in coll2 are not sorted" << endl;
	}
	// print first unsorted name
	auto pos = is_sorted_until(coll2.cbegin(), coll2.cend(),
		compareName);
	if (pos != coll2.end()) {
		cout << "first unsorted name: " << pos->second << endl;
	}
}