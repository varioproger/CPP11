#include "../algostuff.hpp"
using namespace std;
int main()
{
	list<int> coll;
	// insert two sorted sequences
	INSERT_ELEMENTS(coll, 1, 7);
	INSERT_ELEMENTS(coll, 1, 8);
	PRINT_ELEMENTS(coll);
	// find beginning of second part (element after 7)
	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), // range
		7); // value
	++pos;
	// merge into one sorted range
	inplace_merge(coll.begin(), pos, coll.end());
	PRINT_ELEMENTS(coll);
}