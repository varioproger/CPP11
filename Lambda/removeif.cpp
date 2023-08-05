#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
template <typename T>
inline void PRINT_ELEMENTS(const T& coll,
	const std::string& optstr = "")
{
	std::cout << optstr;
	for (const auto& elem : coll) {
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}

class Nth { // function object that returns true for the nth call
private:
	int nth; // call for which to return true
	int count; // call counter
public:
	Nth(int n) : nth(n), count(0) {
	}
	bool operator() (int) {
		return ++count == nth;
	}
};

/* remove_if ±¸ÇöºÎ

template <typename ForwIter, typename Predicate>
ForwIter std::remove_if(ForwIter beg, ForwIter end,
	Predicate op)
{
	while (beg != end && !op(*beg)) {
		++beg;
	}
	if (beg == end) {
		return beg;
	}
	else {
		ForwIter next = beg;
		return remove_copy_if(++next, end, beg, op);
	}
}

A predicate should always be stateless
*/



int main()
{
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	PRINT_ELEMENTS(coll, "coll: ");
	// remove third element
	list<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(), // range
		Nth(3)); // remove criterion
	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "3rd removed: ");
}