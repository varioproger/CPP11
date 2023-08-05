#include "../algostuff.hpp"
using namespace std;
/*
• These algorithms return whether for all, any(at least one), or none of the elements in the range
  [beg, end), the unary predicate op(elem) yields true.
• If the range is empty, all_of() and none_of() return true, whereas any_of() returns false.
*/

int main()
{
	vector<int> coll;
	vector<int>::iterator pos;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");
	// define an object for the predicate (using a lambda)
	auto isEven = [](int elem) {
		return elem % 2 == 0;
	};
	// print whether all, any, or none of the elements are/is even
	cout << boolalpha << "all even?: "
		<< all_of(coll.cbegin(), coll.cend(), isEven) << endl;
	cout << "any even?: "
		<< any_of(coll.cbegin(), coll.cend(), isEven) << endl;
	cout << "none even?: "
		<< none_of(coll.cbegin(), coll.cend(), isEven) << endl;
}