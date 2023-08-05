#include<iostream>
#include<functional>

int multiple(int a, int b)
{
	return a * b;
}
int main()
{
	int num1 = 3;
	int num2 = 4;
	auto func1 = std::bind(multiple, num1, num2);
	auto func2 = std::bind(multiple, 5, 6);
	auto func3 = std::bind(multiple, std::cref(num1), std::cref(num2));

	std::cout << func1() << " " << func2() << " " << func3() << std::endl;

	num1 = 6;
	num2 = 7;

	std::cout << func1() << " " << func2() << " " << func3() << std::endl;

	getchar();
	return 0;
}
