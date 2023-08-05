#include<iostream>
using namespace std;
/*
used to specify that a function cannot throw or is not prepared to throw
noexcept targets a lot of problems exception specifications have
1) Runtime checking
2) Runtime overhead
3) Unusable in generic code
it is merely a method for a programmer to inform the compiler whether or not a function should throw exceptions.


noexcept was introduced inside the library with the following conservative approach
• Each library function ... that ... cannot throw and does not specify any undefined behavior
	— forexample, caused by a broken precondition — should be marked as unconditionally noexcept.
• If a library swap function, move constructor, or move assignment operator ... can be proven not to throw
	by applying the noexcept operator, it should be marked as conditionally noexcept.
	No other function should use a conditional noexcept specification.
• No library destructor should throw. It must use the implicitly supplied (nonthrowing) exception specification.
• Library functions designed for compatibility with C code ... may be marked as unconditionally noexcept.
*/

void ThrowTemp()
{

}
void Temp() noexcept
{
	cout << "Test Throw" << endl;
}
//specify a condition under which a function throws no exception.
void Temp2() noexcept(noexcept(Temp2()))
{
	cout << "Test Throw" << endl;
}
void Temp3() noexcept(noexcept(Temp2()))
{
	cout << "Test Throw" << endl;
}

int main()
{
	//Check method is noexcept
	int val1 = noexcept(Temp());
	int val2 = noexcept(ThrowTemp());
	cout << val1 << " " << val2 << endl;
	return 0;
}