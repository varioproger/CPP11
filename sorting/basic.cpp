#include "../algostuff.hpp"
using namespace std;
int main()
{
	deque<int> coll;
	INSERT_ELEMENTS(coll, 1, 9);
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "on entry: ");
	// sort elements
	sort(coll.begin(), coll.end());
	PRINT_ELEMENTS(coll, "sorted: ");
	// sorted reverse
	sort(coll.begin(), coll.end(), // range
		greater<int>()); // sorting criterion
	PRINT_ELEMENTS(coll, "sorted >: ");
}