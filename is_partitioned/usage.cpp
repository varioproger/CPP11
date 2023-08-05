#include "../algostuff.hpp"
using namespace std;
/*
partition_point (ForwardIterator beg, ForwardIterator end, BinaryPredicate op)
• is_partitioned() returns whether the elements in the range [beg,end) are partitions, 
  so all the elements fulfilling the predicate op() are positioned before all elements that do not fulfill it.
• partition_point() returns the position of the first element in the partitioned range [beg,end).
  Thus, for [beg,end), is_partitioned() has to yield true on entry.
• The algorithms use the binary predicate op(elem1,elem2) which should return true if elem1 is “less than” elem2.
• If the range is empty, partition_point() returns end
*/
int main()
{
	vector<int> coll = { 5, 3, 9, 1, 3, 4, 8, 2, 6 };
	PRINT_ELEMENTS(coll, "coll: ");
	// define predicate: check whether element is odd:
	auto isOdd = [](int elem) {
		return elem % 2 == 1;
	};
	// check whether coll is partitioned in odd and even elements
	if (is_partitioned(coll.cbegin(), coll.cend(), // range
		isOdd)) { // predicate
		cout << "coll is partitioned" << endl;
		// find first even element:
		auto pos = partition_point(coll.cbegin(), coll.cend(),
			isOdd);
		cout << "first even element: " << *pos << endl;
	}
	else {
		cout << "coll is not partitioned" << endl;
	}
}