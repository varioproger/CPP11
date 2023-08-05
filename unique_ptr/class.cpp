#include<iostream>
#include<memory>
using namespace std;

class ClassB {
private:
	std::unique_ptr<ClassA> ptr1; // unique_ptr members
	std::unique_ptr<ClassA> ptr2;
public:
	// constructor that initializes the unique_ptrs
	// - no resource leak possible
	ClassB(int val1, int val2)
		: ptr1(new ClassA(val1)), ptr2(new ClassA(val2)) {
	}
	// copy constructor
	// - no resource leak possible
	ClassB(const ClassB& x)
		: ptr1(new ClassA(*x.ptr1)), ptr2(new ClassA(*x.ptr2)) {
	}
	// assignment operator
	const ClassB& operator= (const ClassB& x) {
		*ptr1 = *x.ptr1;
		*ptr2 = *x.ptr2;
		return *this;
	}
	// no destructor necessary
	// (default destructor lets ptr1 and ptr2 delete their objects)
};