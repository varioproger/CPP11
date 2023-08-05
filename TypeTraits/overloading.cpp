#include<iostream>
#include<type_traits>
using namespace std;

// foo() implementation for pointer types:
template <typename T>
void foo_impl(const T& val, std::true_type)
{
	std::cout << "foo() called for pointer to " << *val
		<< std::endl;
}
// foo() implementation for non-pointer types:
template <typename T>
void foo_impl(const T& val, std::false_type)
{
	std::cout << "foo() called for value to " << val
		<< std::endl;
}

/*
Why is that better than providing two overloads of foo(): one for ordinary types and one for pointer types?
One answer is that sometimes, too many overloads are necessary.
*/
template <typename T>
void foo(const T& val)
{
	foo_impl(val, std::is_pointer<T>());
}
int main()
{
	int test = 10;
	int* num = &test;
	foo(num);
	foo(1);
	getchar();
	return 0;
}