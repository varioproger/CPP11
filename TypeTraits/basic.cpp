#include<iostream>
#include<type_traits>
using namespace std;

template <typename T>
void foo(const T& val)
{
	if (std::is_pointer<T>::value) {
		std::cout << "foo() called for a pointer" << std::endl;
	}
	else {
		std::cout << "foo() called for a value" << std::endl;
	}
}
int main()
{
	int* num = nullptr;
	foo(num);
	foo(1);
	getchar();
	return 0;
}