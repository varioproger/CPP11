#include<iostream>
#include<memory>
using namespace std;

/*
because the last owner of the object released the object in the meantime — lock() yields an empty shared_ptr.
In that case, calling operator * or -> would cause undefined behavior.

If you are not sure that the object behind a weak pointer still exists, you have several options:

1. You can call expired(), which returns true if the weak_ptr doesn’t share an object any longer.
This option is equivalent to checking whether use_count() is equal to 0 but might be faster.

2. You can explicitly convert a weak_ptr into a shared_ptr by using a corresponding shared_ptr constructor.
If there is no valid referenced object, this constructor will throw a bad_weak_ptr exception.
This is an exception of a class derived from std::exception, where what() yields "bad_weak_ptr".

3. You can call use_count() to ask for the number of owners the associated object has. 
If the return value is 0, there is no valid object any longer. Note, however,
that you should usually call use_count() only for debugging purposes; 
the C++ standard library explicitly states:“use_count() is not necessarily efficient.”
*/
int main()
{
	try {
		shared_ptr<string> sp(new string("hi")); // create shared pointer
		weak_ptr<string> wp = sp; // create weak pointer out of it
		sp.reset(); // release object of shared pointer
		cout << wp.use_count() << endl; // prints: 0
		cout << boolalpha << wp.expired() << endl; // prints: true
		shared_ptr<string> p(wp); // throws std::bad_weak_ptr
	}
	catch (const std::exception& e) {
		cerr << "exception: " << e.what() << endl; // prints: bad_weak_ptr
	}
	getchar();
	return 0;
}