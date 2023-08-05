#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
int square(int value)
{
	return value * value;
}
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

int main()
{
	std::set<int> coll1;
	std::vector<int> coll2;
	// insert elements from 1 to 9 into coll1
	for (int i = 1; i <= 9; ++i) {
		coll1.insert(i);
	}
	PRINT_ELEMENTS(coll1, "initialized: ");
	// transform each element from coll1 to coll2
	// - square transformed values
	// 이렇게 함수를 추가해서 사전 작업 함수를 추가할 수 있다.
	std::transform(coll1.cbegin(), coll1.cend(), // source
		std::back_inserter(coll2), // destination
		square); // operation
	PRINT_ELEMENTS(coll2, "squared: ");
	return 0;
}