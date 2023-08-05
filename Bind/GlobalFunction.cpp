#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>
#include <string>
using namespace std;
using namespace std::placeholders;
char myToupper(char c)
{
	std::locale loc;
	return std::use_facet<std::ctype<char> >(loc).toupper(c);
}
int main()
{
	string s("Internationalization");
	string sub("Nation");
	// check whether sub is a substring in s, when case insensitivity 
	string::iterator pos;
	pos = search(s.begin(), s.end(), // string to search in
		sub.begin(), sub.end(), // substring to search
		bind(equal_to<char>(), // compar. criterion
			bind(myToupper, _1),
			bind(myToupper, _2)));
	if (pos != s.end()) {
		cout << "\"" << sub << "\" is part of \"" << s << "\""
			<< endl;
	}
}
