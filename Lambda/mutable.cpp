#include<iostream>
using namespace std;

/*
To have a mixture of passing by value and passing by reference,
you can declare the lambda as mutable
*/
int main()
{
	int id = 1; // A

	auto f = [id]() mutable {
		// ���� id �� ���⼭�� id �ʹ� �ٸ� �����̴�.
		std::cout << "id: " << id << std::endl;
		++id; // OK
	};
	id = 42;
	f();
	f();
	f();
	std::cout << id << std::endl;
	return 0;
}