#include<iostream>
#include<memory>
#include<string>
using namespace std;

void a()
{
	// create and initialize an unique_ptr
	//std::unique_ptr<int> up = new int; // ERROR
	std::unique_ptr<int> up(new int); // OK
}
void b()
{
	// create and initialize (pointer to) string:
	std::unique_ptr<std::string> up(new std::string("nico"));
	(*up)[0] = 'N'; // replace first character
	up->append("lai"); // append some characters
	std::cout << *up << std::endl; // print whole string

	// no pointer arithmetic, such as ++, is defined
}
void c()
{
	// A unique_ptr does not have to own an object, so it can be empty.
	std::unique_ptr<std::string> up;

	// or
	up = nullptr;
	up.reset();
}
void d()
{
	std::unique_ptr<std::string> up(new std::string("nico"));
	std::string* sp = up.release(); // up loses ownership
	if (up) { // if up is not empty
		std::cout << *up << std::endl;
	}

	if (up != nullptr) // if up is not empty
	{
	}
	if (up.get() != nullptr) // if up is not empty
	{
	}
}

void e()
{
	// how the copy constructor and the assignment operator of unique_ptrs operate.
	// You can’t copy or assign a unique pointer if you use the ordinary copy semantics.

	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2; // create another unique_ptr
	// up2 = up1; // ERROR: not possible
	up2 = std::move(up1); // assign the unique_ptr
	// transfers ownership from up1 to up2
}
void f()
{
	// initialize a unique_ptr with a new object
	std::unique_ptr<int> up1(new int);
	// initialize another unique_ptr with a new object
	std::unique_ptr<int> up2(new int);
	up2 = std::move(up1); // move assign the unique_ptr
						  // - delete object owned by up2
						  // - transfer ownership from up1 to up2
}
void g()
{
	std::unique_ptr<int> ptr; // create a unique_ptr

	ptr = std::unique_ptr<int>(new int); // OK, delete old object
										 // and own new

	ptr = nullptr; // deletes the associated object, if any
				   // same effect as calling reset();
}

// 설명은 2022-07-07 txt 파일에 넣었으니 함께 보도록
void sink(std::unique_ptr<int> up) //gets ownership
{
}
void SinkData()
{
	std::unique_ptr<int> up(new int);
	sink(std::move(up)); // loses ownership
}

std::unique_ptr<int> source()
{
	std::unique_ptr<int> ptr(new int); // ptr owns the new object
	return ptr; // transfer ownership to calling function
	/*
	no std::move() is necessary in the return statement of source() is that according to the language rules of C++11, 
	the compiler will try a move automatically
	*/
}
void g()
{
	std::unique_ptr<int> p;
	for (int i = 0; i < 10; ++i) 
	{
		p = source(); // p gets ownership of the returned object
		// (previously returned object of f() gets deleted)
	}
} // last-owned object of p gets deleted