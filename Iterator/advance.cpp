#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>

/*
void advance (InputIterator& pos, Dist n)
• Lets the input iterator pos step n elements forward (or backward).
• For bidirectional and random-access iterators, n may be negative to step backward.
• Dist is a template type. Normally, it must be an integral type because operations such as <, ++,
--, and comparisons with 0 are called.
• Note that advance() does not check whether it crosses the end() of a sequence (it can’t check
because iterators in general do not know the containers on which they operate). Thus, calling this
function might result in undefined behavior because calling operator ++ for the end of a sequence
is not defined.
*/

using namespace std;
int main()
{
	list<int> coll;
	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	list<int>::iterator pos = coll.begin();
	// print actual element
	cout << *pos << endl;
	// step three elements forward
	advance(pos, 3);
	// print actual element
	cout << *pos << endl;
	// step one element backward
	advance(pos, -1);
	// print actual element
	cout << *pos << endl;
}
