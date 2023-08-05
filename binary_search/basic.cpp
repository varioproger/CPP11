#include "../algostuff.hpp"
using namespace std;
/*
To obtain the position of an element for which you are searching, 
use lower_bound(), upper_bound(), or equal_range()
*/
int main()
{
	list<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll);
	// check existence of element with value 5
	if (binary_search(coll.cbegin(), coll.cend(), 5)) {
		cout << "5 is present" << endl;
	}
	else {
		cout << "5 is not present" << endl;
	}
	// check existence of element with value 42
	if (binary_search(coll.cbegin(), coll.cend(), 42)) {
		cout << "42 is present" << endl;
	}
	else {
		cout << "42 is not present" << endl;
	}
}