#include <iostream>
#include <string>
using namespace std;


template<typename T> struct S;

// The following structures specialize S by
// lvalue reference (T&), const lvalue reference (const T&),
// rvalue reference (T&&), and const rvalue reference (const T&&).
// Each structure provides a print method that prints the type of
// the structure and its parameter.

// 함수 템플릿은 템플릿 인자 타입을 추론하고, Reference Collapsing Rules 를 사용한다.
// 이것은 Perfect Fowarding의 구현이 가능하게 되는 중요한 내용입니다.

/*  
Reference Collapsing Rules

Expanded Type		Collapsed Type

T& &				T&

T&  &&				T&

T&& &				T&

T&& &&				T&&

RValue Reference를 전달받는 함수 템플릿은 RValue가 전달될 때는 T&&타입으로,

LValue가 전달될 때는 T& 타입으로 자연스럽게 Collapsing 되어 Perfect Fowarding이 가능한 것입니다

*/
template<typename T> struct S < T& > {
	static void print(T& t)
	{
		cout << "print<T&>: " << t << endl;
	}
};

template<typename T> struct S < const T& > {
	static void print(const T& t)
	{
		cout << "print<const T&>: " << t << endl;
	}
};

template<typename T> struct S < T&& > {
	static void print(T&& t)
	{
		cout << "print<T&&>: " << t << endl;
	}
};

template<typename T> struct S < const T&& > {
	static void print(const T&& t)
	{
		cout << "print<const T&&>: " << t << endl;
	}
};

// This function forwards its parameter to a specialized
// version of the S type.
template <typename T> void print_type_and_value(T&& t)
{
	S<T&&>::print(std::forward<T>(t));
}

// This function returns the constant string "fourth".
const string fourth() { return string("fourth"); }

int main()
{
	// The following call resolves to:
	// print_type_and_value<string&>(string& && t)
	// Which collapses to:
	// print_type_and_value<string&>(string& t)
	string s1("first");
	print_type_and_value(s1);

	// The following call resolves to:
	// print_type_and_value<const string&>(const string& && t)
	// Which collapses to:
	// print_type_and_value<const string&>(const string& t)
	const string s2("second");
	print_type_and_value(s2);

	// The following call resolves to:
	// print_type_and_value<string&&>(string&& t)
	print_type_and_value(string("third"));

	// The following call resolves to:
	// print_type_and_value<const string&&>(const string&& t)
	print_type_and_value(fourth());

	getchar();
	return 0;
}