#include"../algostuff.hpp"
using namespace std;
int main()
{
	vector<int> coll;
	int num;
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "coll: ");
	// count elements with value 4
	num = count(coll.cbegin(), coll.cend(), // range
		4); // value
	cout << "number of elements equal to 4: " << num << endl;


	/*
	• Note that op should not change its state during a function call
	• op should not modify the passed arguments.
	• Complexity: linear
	*/
	// count elements with even value
	num = count_if(coll.cbegin(), coll.cend(), // range
		[](int elem) { // criterion
			return elem % 2 == 0;
		});
	// or 
	// Instead of using a lambda, which checks whether the element is even, you could use binders
	//std::bind(std::logical_not<bool>(),
	//	std::bind(std::modulus<int>(), std::placeholders::_1, 2));


	cout << "number of elements with even value: " << num << endl;
	// count elements that are greater than value 4
	num = count_if(coll.cbegin(), coll.cend(), // range
		[](int elem) { // criterion
			return elem > 4;
		});

	cout << "number of elements greater than 4: " << num << endl;
}
