#include<iostream>
#include<map>

int main()
{
	std::map<std::string, float> coll;

	if (coll.insert({ "otto1",22.1f }).second)
	{
		std::cout << "OK, could insert otto/22.3" << std::endl;
	}
	else
	{
		std::cout << "OOPS, could not insert otto/22.3 "
			<< "(key otto already exists)" << std::endl;
	}
	return 0;
}