#include<iostream>
#include<type_traits>
using namespace std;

// 설명은 txt 파일에 있으니 그거 읽으면 됩니다.
int main()
{
	cout << is_const<int* const>::value << endl; // true
	cout << is_const<const int*>::value << endl;// false
	cout << is_const<const int&>::value << endl;// false
	cout << is_const<int[3]>::value << endl;// false
	cout << is_const<const int[3]>::value << endl;// true
	cout << is_const<int[]>::value << endl;// false
	cout << is_const<const int[]>::value << endl;// true

	cout << is_assignable<int, int>::value << endl;// false
	cout << is_assignable<int&, int>::value << endl; // true
	cout << is_assignable<int&&, int>::value << endl; // false
	cout << is_assignable<long&, int>::value << endl; // true
	cout << is_assignable<int&, void*>::value << endl; // false
	cout << is_assignable<void*, int>::value << endl; // false
	cout << is_assignable<const char*, std::string>::value << endl; // false
	cout << is_assignable<std::string, const char*>::value << endl; // true
	cout << is_constructible<int>::value << endl; // true
	cout << is_constructible<int, int>::value << endl; // true
	cout << is_constructible<long, int>::value << endl; // true
	cout << is_constructible<int, void*>::value << endl; // false
	cout << is_constructible<void*, int>::value << endl;// false
	cout << is_constructible<const char*, std::string>::value << endl; // false
	cout << is_constructible<std::string, const char*>::value << endl;// true
	cout << is_constructible<std::string, const char*, int, int>::value << endl;// true
	getchar();
	return 0;
}