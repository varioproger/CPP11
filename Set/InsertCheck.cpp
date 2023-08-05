#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> c;
	if (c.insert(1).second)
	{
		std::cout << "1 inserted" << std::endl;
	}
	else
	{
		std::cout << "1 already exists" << std::endl;
	}
	int value = 3;
	auto status = c.insert(value);
	if (status.second) 
	{
		std::cout << value << " inserted as element ";
	}
	else 
	{
		std::cout << value << " already exists as element ";
	}
	std::cout << std::distance(c.begin(), status.first) + 1 << std::endl;
	getchar();
	return 0;
}