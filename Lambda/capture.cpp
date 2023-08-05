#include<iostream>
using namespace std;

int main()
{
	int x = 0;
	int y = 42;
	auto qqq = [x, &y] {
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		++y; // OK
	};

	int x1 = 0;
	int y1 = 42;
	auto ppp = [=, &y1] {
		std::cout << "x1: " << x1 << std::endl;
		std::cout << "y1: " << y1 << std::endl;
		++y1; // OK
	};

	x = y = 77;
	x1 = y1 = 30;

	qqq();
	qqq();
	ppp();
	ppp();
	std::cout << "final y: " << y << std::endl;
	std::cout << "final y1: " << y1 << std::endl;

	return 0;
}