#include<memory>
using namespace std;
class Person;

// you have to ensure that only one group of shared pointers owns an object
int* p = new int;
shared_ptr<int> sp1(p);
shared_ptr<int> sp2(p); // ERROR: two shared pointers manage allocated int

// but

shared_ptr<int> sp1(new int);
shared_ptr<int> sp2(sp1); // OK


void Temp()
{
	//The problem is the creation of a shared pointer out of this
	shared_ptr<Person> mom(new Person(name + "¡¯s mom"));
	shared_ptr<Person> dad(new Person(name + "¡¯s dad"));
	shared_ptr<Person> kid(new Person(name));
	kid->setParentsAndTheirKids(mom, dad);
}

class Person
{
public:
	// We do that because we want to set the kids of members motherand father.																							\
	we need a shared pointer to the kid,																																\
	which we don¡¯t have at hand.However, creating a new shared pointer out of this doesn¡¯t solve the issue,															\
	because we then open a new group of owners.																															\
	One way to deal with this problem is to pass the shared pointer to the kid as a third argument.																		\
	std::enable_shared_from_this<> to derive your class, representing objects managed by shared pointers, with your class name passed as template argument.				\
	Note that you can¡¯t call shared_from_this() inside the constructor otherwise runtime error occurs

	void setParentsAndTheirKids(shared_ptr<Person> m = nullptr,
		shared_ptr<Person> f = nullptr) {
		mother = m;
		father = f;
		if (m != nullptr) {
			m->kids.push_back(shared_ptr<Person>(this)); // ERROR
			m->kids.push_back(shared_from_this()); // OK
		}
		if (f != nullptr) {
			f->kids.push_back(shared_ptr<Person>(this)); // ERROR
			f->kids.push_back(shared_from_this()); // OK
		}
	}

	//The problem is that shared_ptr stores itself in a private member of Person¡¯s base class,																		\
	enable_shared_from_this<>, at the end of the construction of the Person.																						\
	there is absolutely no way to create cyclic references of shared pointers during the construction of the object that initializes the shared pointer.
};


// get_deleter() yields a pointer to the function defined as a deleter,																								\
To get the deleter, you have to pass its type as a template argument.
auto del = [](int* p) {
	delete p;
};
std::shared_ptr<int> p(new int, del);
decltype(del)* pd = std::get_deleter<decltype(del)>(p);