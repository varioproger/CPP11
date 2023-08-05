#include<iostream>
using namespace std;

// Sometimes, the return type of a function depends on an expression processed with the arguments.
// ÈÄÇà
template <typename T1, typename T2>
auto add1(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

int main()
{
    int num = add1(1, 2);
    cout << num << endl;

    return 0;
}