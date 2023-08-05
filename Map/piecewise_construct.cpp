#include<iostream>
#include<map>
#include<string>
#include<complex>
/*
The specializations 

std::complex<float>, 
std::complex<double>,
std::complex<long double> 

are LiteralTypes for representing and manipulating complex numbers
*/
int main()
{
	std::map<std::string, std::complex<float>> m;

	m.emplace(std::piecewise_construct, // pass tuple elements as arguments
		std::make_tuple("hello"), // elements for the key
		std::make_tuple(3.4, 7.8)); // elements for the value
	return 0;
}