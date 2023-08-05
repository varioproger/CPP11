#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include<memory>
using namespace std;
using namespace std::placeholders;
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
	//vector<Person> coll
	//	= { Person("Tick"), Person("Trick"), Person("Track") };
	//// call member function print() for each person
	//for_each(coll.begin(), coll.end(),
	//	bind(&Person::print, _1));
	//cout << endl;
	//// call member function print2() with additional argument for each person
	//for_each(coll.begin(), coll.end(),
	//	bind(&Person::print2, _1, "Person: "));
	//cout << endl;
	//// call print2() for temporary Person
	//bind(&Person::print2, _1, "This is: ")(Person("nico"));

	// 2)
	//Note that you can also pass pointers to objects
	//vector<Person*> coll
	//	= { new Person("Tick"), new Person("Trick"), new Person("Track") };
	//// call member function print() for each person
	//for_each(coll.begin(), coll.end(),
	//	bind(&Person::print, _1));
	//cout << endl;
	//// call member function print2() with additional argument for each person
	//for_each(coll.begin(), coll.end(),
	//	bind(&Person::print2, _1, "Person: "));
	//cout << endl;
	//// call print2() for temporary Person
	//bind(&Person::print2, _1, "This is: ")(Person("nico"));

	// 3)
	// and even smart pointers to bind()
	vector<shared_ptr<Person>> coll
		= { make_shared<Person>("Tick"), make_shared<Person>("Trick"), make_shared<Person>("Track") };
	// call member function print() for each person
	for_each(coll.begin(), coll.end(),
		bind(&Person::print, _1));
	cout << endl;
	// call member function print2() with additional argument for each person
	for_each(coll.begin(), coll.end(),
		bind(&Person::print2, _1, "Person: "));
	cout << endl;
	// call print2() for temporary Person
	bind(&Person::print2, _1, "This is: ")(Person("nico"));
}