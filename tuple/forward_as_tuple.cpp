// piecewise_construct example
#include <utility>      // std::pair, std::piecewise_construct
#include <iostream>     // std::cout
#include <tuple>        // std::forward_as_tuple
#include <vector>       // std::vector
#include <string>       // std::string

/*
This constant value is passed as the first argument to construct a pair object to select the constructor form that constructs
its members in place by forwarding the elements of two tuple objects to their respective constructor.
*/

int main() {
    std::pair < std::vector<std::string>, std::vector<int> >
        foo(
            std::piecewise_construct,
            std::forward_as_tuple(std::vector<std::string>{"Yes", "MY", "Name", "Is Tom"}),
            std::forward_as_tuple(std::vector<int>{1, 2, 3, 4, 5})
        );
    std::cout << "foo.first:";
    for (auto& x : foo.first) std::cout << ' ' << x;
    std::cout << '\n';
    std::cout << "foo.second:";
    for (int& x : foo.second) std::cout << ' ' << x;
    std::cout << '\n';

    return 0;
}