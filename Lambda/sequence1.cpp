#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
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

class IntSequence {
private:
	int value;
public:
	IntSequence(int initialValue) // constructor
		: value(initialValue) {
	}
	int operator() () { // ����function call����
		return ++value;
	}
};
int main()
{
	list<int> coll;
	// insert values from 1 to 9
	generate_n(back_inserter(coll), // start
		9, // number of elements
		IntSequence(1)); // generates values, starting with 1
	PRINT_ELEMENTS(coll);

	// replace second to last element but one with values starting at 42
	generate(next(coll.begin()), // start
		prev(coll.end()), // end
		IntSequence(42)); // generates values, starting with 42
	PRINT_ELEMENTS(coll);
}
