#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
void incr(int& i)
{
	++i;
}
int main()
{
	int i = 0;
	bind(incr, i)(); // increments a copy of i, no effect for i
	bind(incr, ref(i))(); // increments i
	// Note that bind() internally copies passed arguments
	cout << i << endl;
}
