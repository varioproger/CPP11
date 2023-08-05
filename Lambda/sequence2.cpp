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
	std::cout << optstr;
	for (const auto& elem : coll) {
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}

/*
There are three ways to get a ¡°result¡± or ¡°feedback¡± from function objects passed to algorithms
1. You can keep the state externally and let the function object refer to it.
2. You can pass the function objects by reference.
3. You can use the return value of the for_each() algorithm.
*/
class IntSequence {
private:
	int value;
public:
	// constructor
	IntSequence(int initialValue)
		: value(initialValue) {
	}
	// ¡®¡®function call¡¯¡¯
	int operator() () {
		return ++value;
	}
};
int main()
{
	list<int> coll;
	IntSequence seq(1); // integral sequence starting with 1
	// insert values from 1 to 4
	// - pass function object by reference
	// so that it will continue with 5
	generate_n<back_insert_iterator<list<int>>,
		int, IntSequence&>(back_inserter(coll), // start
			4, // number of elements
			seq); // generates values
	PRINT_ELEMENTS(coll);
	// insert values from 42 to 45
	generate_n(back_inserter(coll), // start
		4, // number of elements
		IntSequence(42)); // generates values
	PRINT_ELEMENTS(coll);
	// continue with first sequence
	// - pass function object by value
	// so that it will continue with 5 again
	generate_n(back_inserter(coll), // start
		4, // number of elements
		seq); // generates values
	PRINT_ELEMENTS(coll);
	// continue with first sequence again
	generate_n(back_inserter(coll), // start
		4, // number of elements
		seq); // generates values
	PRINT_ELEMENTS(coll);
}