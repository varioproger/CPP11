#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
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


using namespace std;
int main()
{
	deque<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
	PRINT_ELEMENTS(coll, "initialized: ");
	// negate all values in coll
	transform(coll.cbegin(), coll.cend(), // source
		coll.begin(), // destination
		negate<int>()); // predefined class template
	PRINT_ELEMENTS(coll, "negated: ");
	// square all values in coll
	transform(coll.cbegin(), coll.cend(), // first source
		coll.cbegin(), // second source
		coll.begin(), // destination
		multiplies<int>()); // predefined class template
	PRINT_ELEMENTS(coll, "squared: ");
}