#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

/*
This simple auxiliary function is provided to swap the values to which two iterators
void iter_swap (ForwardIterator1 pos1, ForwardIterator2 pos2)
• Swaps the values to which iterators pos1 and pos2 refer.
• The iterators don’t need to have the same type. However, the values must be assignable.
*/

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

int main()
{
	list<int> coll;
	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);
	// swap first and second value
	iter_swap(coll.begin(), next(coll.begin()));
	PRINT_ELEMENTS(coll);
	// swap first and last value
	iter_swap(coll.begin(), prev(coll.end()));
	PRINT_ELEMENTS(coll);
}