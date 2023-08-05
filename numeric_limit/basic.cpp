#include<iostream>
#include<limits>

using namespace std;
int main()
{
    std::cout
        << "type\t¦¢ lowest()\t¦¢ min()\t\t¦¢ min()\t\t¦¢ digits\n"
        << "bool\t¦¢ "
        << std::numeric_limits<bool>::lowest() << "\t\t¦¢ "
        << std::numeric_limits<bool>::min() << "\t\t¦¢ "
        << std::numeric_limits<bool>::max() << "\t\t¦¢ "
        << std::numeric_limits<bool>::digits << '\n'
        << "uchar\t¦¢ "
        << +std::numeric_limits<unsigned char>::lowest() << "\t\t¦¢ "
        << +std::numeric_limits<unsigned char>::min() << "\t\t¦¢ "
        << std::numeric_limits<unsigned>::max() << "\t¦¢ "
        << std::numeric_limits<unsigned>::digits << '\n'
        << "int\t¦¢ "
        << std::numeric_limits<int>::lowest() << "\t¦¢ "
        << std::numeric_limits<int>::min() << "\t¦¢ "
        << std::numeric_limits<int>::max() << "\t¦¢ "
        << std::numeric_limits<int>::digits << '\n'
        << "float\t¦¢ "
        << std::numeric_limits<float>::lowest() << "\t¦¢ "
        << std::numeric_limits<float>::min() << "\t¦¢ "
        << std::numeric_limits<float>::max() << "\t¦¢ "
        << std::numeric_limits<float>::digits << '\n'
        << "double\t¦¢ "
        << std::numeric_limits<double>::lowest() << "\t¦¢ "
        << std::numeric_limits<double>::min() << "\t¦¢ "
        << std::numeric_limits<double>::max() << "\t¦¢ "
        << std::numeric_limits<double>::digits << '\n';

    getchar();
    return 0;

}