#include "../algostuff.hpp"
using namespace std;
int main()
{
	list<int> coll;
	INSERT_ELEMENTS(coll, 1, 6);
	PRINT_ELEMENTS(coll);
	// initValue = initValue + elem1 * elem
	// process sum of all products
	// (0 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6)
	cout << "inner product: "
		<< inner_product(coll.cbegin(), coll.cend(), // first range
			coll.cbegin(), // second range
			0) // initial value
		<< endl;
	// process sum of 1*6 ... 6*1
	// (0 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1)
	cout << "inner reverse product: "
		<< inner_product(coll.cbegin(), coll.cend(), // first range
			coll.crbegin(), // second range
			0) // initial value
		<< endl;

	// initValue op1 (a1 op2 b1) op1 (a2 op2 b2) op1 (a3 op2 b3) op1
	// process product of all sums
	// (1 * 1+1 * 2+2 * 3+3 * 4+4 * 5+5 * 6+6)
	cout << "product of sums: "
		<< inner_product(coll.cbegin(), coll.cend(), // first range
			coll.cbegin(), // second range
			1, // initial value
			multiplies<int>(), // outer operation
			plus<int>()) // inner operation
		<< endl;

	// If the first range is empty (beg1==end1), both forms return initValue.
}