#include<functional>
#include<iostream>

/*
The type of a lambda is an anonymous function object
to declare objects of that type, you need templates or auto.
If you need the type, you can use decltype().Alternatively, you can use the std::function<> class template

Callable function pointer
*/
			//���� ����<�Ķ����>
std::function<int(int, int)> returnLambda()
{
	return [](int x, int y) {
		return 12.5;
	};
}
int main()
{
	auto lf = returnLambda();
	std::cout << lf(6, 7) << std::endl;
}