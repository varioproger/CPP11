#include<iostream>
#include<map>

int main()
{
	std::map<std::string, float> coll;

	coll.insert({ "otto1",22.1 });

	// To avoid implicit type conversion
	coll.insert(std::map<std::string, float>::value_type("otto2",22.2));
	// or
	coll.insert(decltype(coll)::value_type("otto3", 22.3));

	// use implicit conversion:
	coll.insert(std::pair<std::string, float>("otto4", 22.4));
	
	// use no implicit conversion:
	coll.insert(std::pair<const std::string, float>("otto5", 22.5));


	float value = 0.0f;
	// wrong way to do
	for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
	if (pos->second == value) {
		// if you use pos after removing its element without any reinitialization, all bets are	off.
		coll.erase(pos); // RUNTIME ERROR !!!
	}
}
	// correct way to do
	for (auto pos = coll.begin(); pos != coll.end(); ) {
		if (pos->second == value) {
			pos = coll.erase(pos); // possible only since C++11
		}
		else {
			++pos;
		}
	}

	return 0;
}