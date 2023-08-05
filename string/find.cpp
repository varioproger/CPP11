#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	std::string s("Hi Bill, I¡¯m ill, so please pay the bill");
	s.find("il"); // returns 4 (first substring "il")
	s.find("il", 10); // returns 13 (first substring "il" starting from s[10])
	s.rfind("il");// returns 37 (last substring "il")
	s.find_first_of("il"); // returns 1 (first char ¡¯i¡¯ or ¡¯l¡¯)
	s.find_last_of("il"); // returns 39 (last char ¡¯i¡¯ or ¡¯l¡¯)
	s.find_first_not_of("il"); // returns 0 (first char neither ¡¯i¡¯ nor ¡¯l¡¯)
	s.find_last_not_of("il"); // returns 36 (last char neither ¡¯i¡¯ nor ¡¯l¡¯)
	s.find("hi"); // returns npos
	return 0;
}