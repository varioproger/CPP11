#include<iostream>

/*
Class shared_ptr for a pointer that implements the concept of shared ownership.
Multiple smart pointers can refer to the same object so that 
the object and its associated resources get released whenever the last reference to it gets destroyed. 
To perform this task in more complicated scenarios, helper classes, 
such as weak_ptr, bad_weak_ptr, and enable_shared_from_this, are provided.
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

void Test(shared_ptr<string> temp)
{
	cout << temp.use_count() << endl;
}
int main()
{
	// two shared pointers representing two persons by their name
	shared_ptr<string> pOne(new string("one")); 
	shared_ptr<string> pTwo{ new string("two") };
	shared_ptr<string>pThree = make_shared<string>("three");
	// capitalize person names
	(*pOne)[0] = 'O';
	pTwo->replace(0, 1, "T");
	
	//you can declare the shared pointer first and assign a new pointer later on.
	pThree.reset(new string("Three")); // OK

	cout << pOne.use_count() << endl;
	Test(pOne);
	cout << pOne.use_count() << endl;
	getchar();
	return 0;
}