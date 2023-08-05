#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
// function object that adds the value with which it is initialized

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

class AddValue {
private:
	int theValue; // the value to add
public:
	// constructor initializes the value to add
	AddValue(int v) : theValue(v) {
	}
	// the ¡®¡®function call¡¯¡¯ for the element adds the value
	void operator() (int& elem) const {
		elem += theValue;
	}
};
int main()
{
	list<int> coll;
	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll, "initialized: ");
	// add value 10 to each element
	for_each(coll.begin(), coll.end(), // range
		AddValue(10)); // operation
	PRINT_ELEMENTS(coll, "after adding 10: ");
	// add value of first element to each element
	for_each(coll.begin(), coll.end(), // range
		AddValue(*coll.begin())); // operation
	PRINT_ELEMENTS(coll, "after adding first element: ");
}