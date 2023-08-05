#include<iostream>
#include<map>
#include<numeric>
#include<functional>
using namespace std;
using namespace std::placeholders;

int main()
{
	map<string, int> coll; // map of int values associated to strings
	// accumulate all values (member second of the elements)
	int sum
		= accumulate(coll.begin(), coll.end(),
			0,
			bind(plus<int>(),
				_1,
				bind(&map<string, int>::value_type::second,
					_2)));
	return 0;
}