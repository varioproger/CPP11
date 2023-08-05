#include<iostream>
using namespace std;

class c {
public:
	float a;
};

int main()
{

    int x = 0;
    const int&& fx();

    decltype(x) test1 = 2.2;        //int
    cout << test1 << endl;
    decltype((x));        //int&
    decltype(fx());        //const int&&

    c cc;
    decltype(cc.a) test2 = 1.2;        //float
    cout << test2 << endl;
    const c ccc;
    decltype((ccc.a));// const float&

	return 0;
}