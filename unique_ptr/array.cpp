#include<memory>
#include<string>
#include<iostream>
using namespace std;
/*
the C++ standard library provides a partial specialization of class unique_ptr for
arrays, which calls delete[ ] for the referenced object when the pointer loses the ownership to it.
*/

void a()
{
	std::unique_ptr<std::string[]> up(new std::string[10]); // OK
	//std::cout << *up << std::endl; // ERROR: * not defined for arrays
	std::cout << up[0] << std::endl; // OK

	//Note also that this class does not allow getting initialized by an array of a derived type.
	//This reflects that fact that polymorphism does not work for plain arrays.
}

