#include <string>
#include <regex>
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
	string data = "<person>\n"
		" <first>Nico</first>\n"
		" <last>Josuttis</last>\n"
		"</person>\n";
	regex reg("<(.*)>(.*)</(\\1)>");
	// print data with replacement for matched patterns
	cout << regex_replace(data, // data
		reg, // regular expression
		"<$1 value=\"$2\"/>") // replacement using default syntax
		<< endl;

	// or we can avoid having to escape the quotes by using a raw string:
	// print data with replacement for matched patterns
	cout << regex_replace(data, // data
		reg, // regular expression
		R"(<$1 value="$2"/>)") // replacement using default syntax
		<< endl;

	// same using sed syntax
	//By passing a regex constant regex_constants::format_sed, you can instead use the replacement syntax of the UNIX command sed
	cout << regex_replace(data, // data
		reg, // regular expression
		"<\\1 value=\"\\2\"/>", // replacement using sed syntax
		regex_constants::format_sed) // format flag
		<< endl;

	// Again, by using a raw string, we can avoid escaping backslashes:
	cout << regex_replace(data, // data
		reg, // regular expression
		R"(<\1 value="\2"/>)", // replacement using sed syntax
		regex_constants::format_sed) // format flag
		<< endl;

	// use iterator interface, and
	// - format_no_copy: don¡¯t copy characters that don¡¯t match
	// - format_first_only: replace only the first match found
	string res2;
	regex_replace(back_inserter(res2), // destination
		data.begin(), data.end(), // source range
		reg, // regular expression
		"<$1 value=\"$2\"/>", // replacement
		regex_constants::format_no_copy // format flags
		| regex_constants::format_first_only);
	cout << res2 << endl;
}