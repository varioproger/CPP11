#include<iostream>
#include<type_traits>

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type sum(const T1& x, const T2& y)
{
	/*
	what if one is int and the other is long, or std::string or one is a string and the other is a string literal (type const char*).
	common_type simply uses the rules implemented for operator ?:, which has to yield one result type based on the types of both operands.
	*/
	return x+y;
}
int main()
{
	std::string A{ "Who" };
	std::string B{ "You" };

	std::cout << sum(10, 11) << std::endl;
	std::cout << sum(10, 11.22) << std::endl;
	std::cout << sum(10, 'a') << std::endl;
	std::cout << sum('a', 10) << std::endl;
	std::cout << sum(A, B) << std::endl;
	getchar();
	return 0;
}