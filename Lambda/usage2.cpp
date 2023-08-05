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


int main()
{
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	PRINT_ELEMENTS(coll, "coll: ");
	// remove third element
	list<int>::iterator pos;
	int count = 0; // call counter
	pos = remove_if(coll.begin(), coll.end(), // range
		/*
			[count](int) mutable { // remove criterion
			return ++count == 3;
		});
		*/
		//If you pass the argument by reference and don¡¯t use mutable, the behavior is as expected
		[&count](int) { // remove criterion
			return ++count == 3;
		});

	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll, "3rd removed: ");
}