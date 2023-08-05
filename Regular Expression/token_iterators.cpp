
/*
if you want to split a string into separate tokens, 
separated by something, which might even be specified as a regular expression

Class regex_token_iterator<> having the usual instantiations for strings
and character sequences with prefixes s, c, ws, or wc provides this functionality.

• -1 means that you are interested in all the subsequences between matched regular expressions (token separators).

• 0 means that you are interested in all the matched regular expressions (token separators).

• Any other value n means that you are interested in the matched nth subexpression inside the regular expressions
*/
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Note that the interface of regex_token_iterator allows you to specify the tokens of interest in various ways:
• You can pass a single integral value.
• You can pass an initializer list of integral values (see Section 3.1.3, page 15).
• You can pass a vector of integral values.
• You can pass an array of integral values.
*/
int main()
{
	string data = "<person>\n"
		" <first>Nico</first>\n"
		" <last>Josuttis</last>\n"
		"</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");
	// iterate over all matches (using a regex_token_iterator):
	sregex_token_iterator pos(data.cbegin(), data.cend(), // sequence
		reg, // token separator
		{ 0,2}); // 0: full match, 2: second substring

	sregex_token_iterator end;
	for (; pos != end; ++pos) {
		cout << "match: " << pos->str() << endl;
	}
	cout << endl;

	string names = "nico, jim, helmut, paul, tim, john paul, rita";
	regex sep("[ \t\n]*[,;.][ \t\n]*"); // separated by , ; or . and spaces
	sregex_token_iterator p(names.cbegin(), names.cend(), // sequence
		sep, // separator
		-1); // -1: values between separators
	sregex_token_iterator e;
	for (; p != e; ++p) {
		cout << "name: " << *p << endl;
	}
}