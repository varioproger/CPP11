#include "../algostuff.hpp"
using namespace std;
bool bothEvenOrOdd(int elem1, int elem2)
{
	return elem1 % 2 == elem2 % 2;
}
int main()
{
	vector<int> coll1;
	list<int> coll2;
	INSERT_ELEMENTS(coll1, 1, 7);
	INSERT_ELEMENTS(coll2, 3, 9);
	PRINT_ELEMENTS(coll1, "coll1: ");
	PRINT_ELEMENTS(coll2, "coll2: ");
	// check whether both collections are equal
	if (equal(coll1.begin(), coll1.end(), // first range
		coll2.begin())) { // second range
		cout << "coll1 == coll2" << endl;
	}
	else {
		cout << "coll1 != coll2" << endl;
	}
	// check for corresponding even and odd elements
	if (equal(coll1.begin(), coll1.end(), // first range
		coll2.begin(), // second range
		bothEvenOrOdd)) { // comparison criterion
		cout << "even and odd elements correspond" << endl;
	}
	else {
		cout << "even and odd elements do not correspond" << endl;
	}
}
