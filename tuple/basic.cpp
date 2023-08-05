// tuple example
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

int main()
{
	std::tuple<int, char> foo(10, 'x');
	auto bar = std::make_tuple("test", 3.1, 14, 'y');

	std::cout << std::get<0>(foo) << ' ';
	std::cout << std::get<1>(foo) << '\n';


	std::cout << std::get<0>(bar) << ' ';
	std::cout << std::get<1>(bar) << ' ';
	std::cout << std::get<2>(bar) << ' ';
	std::cout << std::get<3>(bar) << '\n';

	std::get<2>(bar) = 100;                                    // access element
	std::cout << std::get<2>(bar) << std::endl;


	int myint; char mychar;

	std::tie(myint, mychar) = foo;                            // unpack elements
	std::cout << myint << " " << mychar << std::endl;

	std::tie(std::ignore, std::ignore, myint, mychar) = bar;  // unpack (with ignore)
	std::cout << myint << " " << mychar << std::endl;

	mychar = std::get<3>(bar);
	std::cout << myint << std::endl;


	std::get<0>(foo) = std::get<2>(bar);
	std::get<1>(foo) = mychar;

	std::cout << std::get<0>(foo) << ' ';
	std::cout << std::get<1>(foo) << '\n';

	return 0;
}