#include<iostream>
#include<map>
#include<algorithm> //std::for_each
int main()
{
	std::map<std::string, float> coll;

	std::for_each(coll.begin(), coll.end(),
		[](std::pair<const std::string, float>& elem) {
			elem.second += 10;
		});
	return 0;
}