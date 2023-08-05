#include "../algostuff.hpp"
using namespace std;
/*
is_heap_until (RandomAccessIterator beg, RandomAccessIterator end, BinaryPredicate op)
• is_heap() returns whether the elements in the range [beg,end) are a heap which means that beg is (one of) the maximum element(s).
• is_heap()_until returns the position of the first element in the range [beg,end) that breaks the
  sorting as a heap (is larger than the first element) or end if none.
• The first and third forms use operator < to compare elements. The second and fourth forms use
  the binary predicate op(elem1,elem2) which should return true if elem1 is “less than” elem2.
• If the range is empty or has only one element, the algorithms return true or end, respectively.
*/
int main()
{
	vector<int> coll1 = { 9, 8, 7, 7, 7, 5, 4, 2, 1 };
	vector<int> coll2 = { 5, 3, 2, 1, 4, 7, 9, 8, 6 };
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");
	// check whether the collections are heaps
	cout << boolalpha << "coll1 is heap: "
		<< is_heap(coll1.cbegin(), coll1.cend()) << endl;
	cout << "coll2 is heap: "
		<< is_heap(coll2.cbegin(), coll2.cend()) << endl;
	// print the first element that is not a heap in coll2
	auto pos = is_heap_until(coll2.cbegin(), coll2.cend());
	if (pos != coll2.end()) {
		cout << "first non-heap element: " << *pos << endl;
	}
}