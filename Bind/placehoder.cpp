#include<iostream>
#include<functional>

int multiple(int a, int b, int c)
{
	std::cout << a << " " << b << " " << c << std::endl;
	return a * b  * c;
}
int main()
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;

	auto func1 = std::bind(multiple, std::placeholders::_1,num2 , num3);
	auto func2 = std::bind(multiple, num1, std::placeholders::_1, num3);
	auto func3 = std::bind(multiple, num1, num2, std::placeholders::_1);
	auto func4 = std::bind(multiple, std::placeholders::_2, std::placeholders::_1, num3);
	auto func5 = std::bind(multiple, num1, std::placeholders::_1, std::placeholders::_2);
	auto func6 = std::bind(multiple, std::placeholders::_2, std::placeholders::_1, std::placeholders::_3);

	std::cout << func1(3) << std::endl;
	std::cout << func2(2) << std::endl;
	std::cout << func3(3) << std::endl;
	std::cout << func4(3, 4) << std::endl;
	std::cout << func5(3, 4) << std::endl;
	std::cout << func6(6, 3, 4) << std::endl;

	getchar();
	return 0;
}
