#include<iostream>
using namespace std;

template <typename T, size_t M>
class Test
{
public:
	Test(T t)
	{
		cout << t << endl;
	}
};

template <typename T>
using TestClass = Test<T, 1>;
int main()
{
	TestClass<int> test(1);

	return 0;
}