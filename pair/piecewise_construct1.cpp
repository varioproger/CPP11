#include <iostream>
#include <utility>
#include <tuple>

/*
take two tuple arguments.
The overloads that use std::piecewise_construct_t assume that each tuple argument is used to construct, 
piecewise, a new object of specified type, which will become the element of the pair.
*/
struct Foo {
    Foo(std::tuple<int, double> temp)
    {
        std::cout << "Constructed a Foo from a tuple\n";
        std::cout << std::get<0>(temp) << std::endl;
        std::cout << std::get<1>(temp) << std::endl;
    }
    Foo(int x, double y)
    {
        std::cout << "Constructed a Foo from an int and a float\n";
        std::cout << x << " " << y << std::endl;;
    }
};

int main()
{
    std::tuple<int, double> t(1, 3.14);
    std::pair<Foo, Foo> p1(t, t);
    std::pair<Foo, Foo> p2(std::piecewise_construct, std::make_tuple(1,2.3), std::make_tuple(3, 4.5));
}