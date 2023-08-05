#include<iostream>
#include<memory>

using namespace std;
/*
shared_ptrs are provided to automatically release resources associated with objects no longer needed.
However, under certain circumstances, this behavior doesn’t work or is not what is intended

If two objects refer to each other using shared_ptrs, and you want to release the objects 
and their associated resource if no other references to these objects exist, shared_ptr won’t release the data, because the use_count() of each object is still 1.

occurs when you explicitly want to share but not own an object.

weak_ptr is provided, which allows sharing but not owning an object.

Whenever the last shared pointer owning the object loses its ownership, 
any weak pointer automatically becomes empty.
Thus, besides default and copy constructors, class weak_ptr provides only a constructor taking a shared_ptr.

You can’t use operators * and -> to access a referenced object of a weak_ptr directly.

you have to create a shared pointer out of it. This makes sense for two reasons:

1. Creating a shared pointer out of a weak pointer checks whether there is (still) an associated object. 
If not, this operation will throw an exception or create an empty shared pointer 
(what exactly happens depends on the operation used).

2. While dealing with the referenced object, the shared pointer can’t get released.

*/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Person {
public:
	string name;
	shared_ptr<Person> mother;
	shared_ptr<Person> father;
	//vector<shared_ptr<Person>> kids;
	vector<weak_ptr<Person>> kids;

	Person(const string& n,
		shared_ptr<Person> m = nullptr,
		shared_ptr<Person> f = nullptr)
		: name(n), mother(m), father(f) {
	}
	~Person() {
		cout << "delete " << name << endl;
	}
};

shared_ptr<Person> initFamily(const string& name)
{
	shared_ptr<Person> mom(new Person(name + "’s mom"));
	shared_ptr<Person> dad(new Person(name + "’s dad"));
	shared_ptr<Person> kid(new Person(name, mom, dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}
int main()
{
	{
		shared_ptr<Person> p = initFamily("nico");
		cout << "nico’s family exists" << endl;
		cout << "- nico is shared " << p.use_count() << " times" << endl;
		cout << "- name of 1st kid of nico’s mom: "
			//<< p->mother->kids[0]->name << endl;
			<< p->mother->kids[0].lock()->name << endl;
		p = initFamily("jim");
		cout << "jim’s family exists" << endl;
		//each object has references from the kid to each parent and backwards
		// nico was shared three times 	before p gets a new value.Now, if we release our last handle to the family 
		// either by assigning a new person or nullptr to p or by leaving the scope of p at the end of main() 
		// none of the Persons gets released,“delete name,” never gets called
		getchar();
	}
	getchar();
	/*
	As soon as we lose our handle into a family created either by assigning a new value to p or	by leaving main() 
	the kid’s object of the family loses its last owner (use_count() yielded 1	before), 
	which has the effect that both parents lose their last owner. 
	So all objects, initially created by new, are deleted now so that their destructors get called.
	*/

	return 0;
}