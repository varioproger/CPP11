#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void print(int elem)
{
	cout << elem << ' ';
}
int main()
{
	/*
	The rbegin() and rend() member functions return a reverse iterator
	• rbegin() returns the position of the first element of a reverse iteration. Thus, 
	  it returns the position of the last element.
	• rend() returns the position after the last element of a reverse iteration. Thus, 
	  it returns the position before the first element.
	*/

	// create list with elements from 1 to 9
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// print all elements in normal order
	for_each(coll.begin(), coll.end(), // range
		print); // operation
	cout << endl;
	// print all elements in reverse order
	for_each(coll.rbegin(), coll.rend(), // range
		print); // operations
	cout << endl;
}