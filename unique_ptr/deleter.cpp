#include<memory>
#include<string>
#include<iostream>
#include<functional>
using namespace std;


class IntDeleter
{
public:
	void operator () (int* p) {
		std::cout << "call delete for int object" << std::endl;
		delete p;
	}
};

void a()
{
	std::unique_ptr<int, IntDeleter> up(new int);
}

auto b_1 = [](int* p) {
		delete[] p;
};

template <typename T>
using uniquePtr = std::unique_ptr<T, void(*)(T*)>; // alias template

void b()
{
	// To specify a function or a lambda, you have to either declare the type of the deleter as void(*)(T*)
	// or std::function<void(T*)> or use decltype

	//std::unique_ptr<int, void(*)(int*)> up(new int[10],
	std::unique_ptr<int, std::function<void(int*)>> up(new int[10],
											[](int* p) {
													delete[] p;
											});

	std::unique_ptr<int, decltype(b_1)> up(new int[10], b_1);

	uniquePtr<int> up(new int[10], [](int* p) { // used here
													delete[] p;
												});
}

class D
{

};
void c()
{
	D d; // instance of the deleter type
	unique_ptr<int, D> p1(new int, D());	// D must be MoveConstructible
	unique_ptr<int, D> p2(new int, d);		// D must be CopyConstructible
	unique_ptr<int, D&> p3(new int, d);		// p3 holds a reference to d
	//unique_ptr<int, const D&> p4(new int, D()); // Error: rvalue deleter object
												  // can¡¯t have reference deleter type

	// For single objects, the move constructorand the assignment operator are member templates, 
	// so a type conversion is possible.
}