#include<iostream>
#include<functional>
#include<vector>

class MyClass
{

};

template<typename T>
void foo(T val)
{
	val = 10;
}
int main()
{
	int num = 0;
	foo(std::ref(num));
	std::cout << num << std::endl; //T&
	const int num2 = 0;
	//compile error
	foo(std::cref(num2)); // const T&
	std::cout << num2 << std::endl;

	//class wrapper
	std::vector<MyClass&> coll; // Error
	std::vector<std::reference_wrapper<MyClass>> coll; // OK
}