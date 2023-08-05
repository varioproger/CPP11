#include <iostream>
#include <utility>
#include <tuple>
using namespace std;
class Foo {
public:
	Foo(tuple<int, double> temp) {
		cout << "Foo::Foo(tuple)" << endl;
		Test = temp;
	}
	template <typename... Args>
	Foo(Args... args) {
		cout << "Foo::Foo(args...)" << endl;
		tuple<Args...> t1 = {args... };
		cout << get<0>(t1) << endl;
		cout << get<1>(t1) << endl;
		cout << get<2>(t1) << endl;
		
	}
	tuple<int, double> Test;
};
int main()
{
	// create tuple t:
	tuple<int, double> t(1, 2.22);
	// pass the tuple as a whole to the constructor of Foo:
	pair<int, Foo> p1(42, t);

	cout << p1.first << endl;
	cout << get<0>(p1.second.Test) << endl;
	cout << get<1>(p1.second.Test) << endl;

	// pass the elements of the tuple to the constructor of Foo:
	pair<int, Foo> p2(piecewise_construct, make_tuple(42), make_tuple(1,2.22,"Yes"));
	cout << p2.first << endl;
}