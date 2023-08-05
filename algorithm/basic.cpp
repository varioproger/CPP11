#include<iostream>
#include<algorithm>
/*
min(a,b) Returns the minimum of a and b, comparing with <
min(a,b,cmp) Returns the minimum of a and b, comparing with cmp
min(initlist) Returns the minimum in initlist, comparing with <
min(initlist,cmp) Returns the minimum in initlist, comparing with cmp
max(a,b) Returns the maximum of a and b, comparing with <
max(a,b,cmp) Returns the maximum of a and b, comparing with cmp
max(initlist) Returns the maximum in initlist, comparing with <
max(initlist,cmp) Returns the maximum in initlist, comparing with cmp
minmax(a,b) Returns the minimum and maximum of a and b, comparing with <
minmax(a,b,cmp) Returns the minimum and maximum of a and b, comparing with cmp
minmax(initlist) Returns the minimum and maximum of initlist comparing with <
minmax(initlist,cmp) Returns the minimum and maximum of initlist comparing with cmp

The function minmax() returns a pair<>, where the first value is the minimum, and the second value is the maximum.
For initializer lists, minmax() returns the pair of a and b for two equal arguments and the first minimum but the last element for an initializer list.
*/
// function that compares two pointers by comparing the values to which they point
bool int_ptr_less(int* a, int* b)
{
	// return true Max °ª
	// return false min °ª
	return *a < *b;
}
int main()
{
	int a = 1;
	int b = 5;
	int c = 4;
	int d = 3;
	int e = 2;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* pd = &d;
	int* pe = &e;
	// call max() with special comparison function
	int* pmax1 = std::max(pa, pd);
	std::cout << *pmax1 << std::endl;

	int* pmax2 = std::max(pa, pd, int_ptr_less);
	std::cout << *pmax2 << std::endl;

	std::pair<int*, int*> extremes1 = std::minmax({ pa, pb, pc, pd, pe }); 
	std::cout << *(extremes1.first) << " " << *(extremes1.second) << std::endl;

	// call minmax() for initializer list with special comparison function
	std::pair<int*, int*> extremes2 = std::minmax({ pa, pb, pc, pd, pe }, int_ptr_less);
	std::cout << *(extremes2.first)<< " "<< *(extremes2.second) << std::endl;
	return 0;
}
