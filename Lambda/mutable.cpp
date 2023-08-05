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
		// 위에 id 와 여기서의 id 와는 다른 변수이다.
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