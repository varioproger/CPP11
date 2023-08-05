/*
structor taking another shared pointer and an additional raw pointer is the so-called aliasing constructor, 
which allows you to capture the fact that one object owns another.
*/

struct X
{
	int a;
};
shared_ptr<X> px(new X);
shared_ptr<int> pi(px, &px->a);
/*
to create a shared pointer to a, you need to keep the
surrounding object alive by attaching to its reference count by means of the aliasing constructor.
*/

/*
referring to a container element or to a shared library symbol.
the programmer has to ensure that the lifetimes of both objects
match.Otherwise, dangling pointers or resource leaks might occur.
*/

shared_ptr<X> sp1(new X);
shared_ptr<X> sp2(sp1, new X); // ERROR: delete for this X will never be called
sp1.reset(); // deletes first X; makes sp1 empty
shared_ptr<X> sp3(sp1, new X); // use_count()==0, but get()!=nullptr

/*
Both make_shared() and allocate_shared() are provided to optimize the creation of a shared object
Using make_shared<X> instead is considerably faster, performing only one allocation, and 
safer because a situation where the allocation of X succeeds but the allocation of the control block fails cannot occur.
*/

// The cast operators allow casting a pointer to a different type.
// Note that using the ordinary cast operators is not possible, because it results in undefined behavior
shared_ptr<void> sp(new int); // shared pointer holds a void* internally
shared_ptr<int>(static_cast<int*>(sp.get())) // ERROR: undefined behavior
static_pointer_cast<int*>(sp) // OK