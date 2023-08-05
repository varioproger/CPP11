#include <set>
#include<list>
#include<deque>
#include<vector>
#include <iostream>
using namespace std;

/*
back_inserter(container) Appends in the same order by using push_back(val)
front_inserter(container) Inserts at the front in reverse order by using push_front(val)
inserter(container,pos) Inserts at pos (in the same order) by using insert(pos,val)

*/
int main()
{
	list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(), // source
		back_inserter(coll2)); // destination

	for (auto& elem : coll2)
	{
		cout << elem<< " ";
	}
	cout << endl;
	
	// copy the elements of coll1 into coll3 by inserting them at the front
	// - reverses the order of the elements
	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(), // source
		front_inserter(coll3)); // destination

	for (auto& elem : coll3)
	{
		cout << elem << " ";
	}
	cout << endl;

	// copy elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(), // source
		inserter(coll4, coll4.begin())); // destination

	for (auto& elem : coll4)
	{
		cout << elem << " ";
	}
	cout << endl;
}