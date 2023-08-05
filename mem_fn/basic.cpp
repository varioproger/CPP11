#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// you can also use the mem_fn() adapter, whereby you can skip the placeholder for the object the member function is called for
class Person {
private:
	string name;
public:
	Person(const string& n) : name(n) {
	}
	void print() const {
		cout << name << endl;
	}
	void print2(const string& prefix) const {
		cout << prefix << name << endl;
	}
};
int main()
{
	// 1)
	vector<Person> coll
		= { Person("Tick"), Person("Trick"), Person("Track") };
	// call member function print() for each person
	for_each(coll.begin(), coll.end(),
		std::mem_fn(&Person::print));
	cout << endl;
	// call print2() for temporary Person
	Person n("MEMEMEM");
	std::mem_fn(&Person::print)(n); // calls n.print()
	std::mem_fn(&Person::print2)(n, "Person: "); // calls n.print2("Person: ")
}