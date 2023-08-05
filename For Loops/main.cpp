#include<iostream>
#include<vector>
using namespace std;

class A
{
public:
	A()
	{
		cout << "Plane" << endl;
	}
	A(const A&)
	{
		cout << "Copy" << endl;
	}
	void Print()
	{
		cout << "Shout" << endl;
	}
	void Print() const 
	{
		cout << "const Shout" << endl;
	}
};
int main()
{
	vector<A> AVec;
	for (int i = 0; i < 3; i++)
	{
		AVec.emplace_back(A{});
	}

	cout << endl;
	for (auto elem : AVec)
	{
		elem.Print();

	}
	cout << endl;
	/*
	To avoid calling the copy constructor and the destructor for each element,
	you should usually declare the current element to be a reference or constant reference.
	*/
	for (auto& elem : AVec)
	{
		elem.Print();
	}
	cout << endl;
	/*
	To avoid calling the copy constructor and the destructor for each element,
	you should usually declare the current element to be a reference or constant reference.
	*/
	for (const auto& elem : AVec)
	{
		elem.Print();
	}
	return 0;
}