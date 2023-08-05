#include "../algostuff.hpp"
using namespace std;
int main()
{
	// print ten times 7.7
	fill_n(ostream_iterator<float>(cout, " "), // beginning of destination
		10, // count
		7.7); // new value
	cout << endl;
	list<string> coll;
	// insert "hello" nine times
	fill_n(back_inserter(coll), // beginning of destination
		9, // count
		"hello"); // new value
	PRINT_ELEMENTS(coll, "coll: ");
	// overwrite all elements with "again"
	fill(coll.begin(), coll.end(), // destination
		"again"); // new value
	PRINT_ELEMENTS(coll, "coll: ");
	// replace all but two elements with "hi"
	fill_n(coll.begin(), // beginning of destination
		coll.size() - 2, // count
		"hi"); // new value
	PRINT_ELEMENTS(coll, "coll: ");
	// replace the second and up to the last element but one with "hmmm"
	list<string>::iterator pos1, pos2;
	pos1 = coll.begin();
	pos2 = coll.end();
	fill(++pos1, --pos2, // destination
		"hmmm"); // new value
	PRINT_ELEMENTS(coll, "coll: ");
}