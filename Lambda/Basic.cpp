#include<iostream>

using namespace std;
/*
a definition of functionality that can be defined inside statements and expressions
use a lambda as an inline function.
*/

int main()
{
	auto fun1 = []{
		cout << "Lambda" << endl;
	};

	// return type
	auto fun2 = []()->int {
		return 12.5;
	};

	fun1();
	int num = fun2();
	cout << num << endl;
	return 0;
}