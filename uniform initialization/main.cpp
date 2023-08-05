#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int values[]{ 1, 2, 3 };
	vector<int> v{ 2, 3, 5, 7, 11, 13, 17 };

	int i; // i has undefined value
	int j{}; // j is initialized by 0
	int* p; // p has undefined value
	int* q{}; // q is initialized by nullptr
	// guaranteed


	//narrowing initializations are not possible with braces.
	//compile error
	int x1(5.3); // OK, but OUCH: x1 becomes 5
	int x2 = 5.3; // OK, but OUCH: x2 becomes 5
	int x3{ 5.0 }; // ERROR: narrowing
	int x4 = { 5.3 }; // ERROR: narrowing
	char c1{ 7 }; // OK: even though 7 is an int, this is not narrowing
	char c2{ 99999 }; // ERROR: narrowing (if 99999 doesn¡¯t fit into a char)

	getchar();
	return 0;
}