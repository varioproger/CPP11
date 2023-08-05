#include<iostream>
#include<initializer_list>

using namespace std;

class P
{
public:
	P(int, int)
	{
		cout << "Just Called" << endl;
	}
	//�����ڿ� expilict Ű���带 ����Ѵٸ� �����Ϸ��� �˾Ƽ� ����ȯ �ϴ°��� ���� �� �ִ�.
	explicit P(int a, int b, int c) {
		cout << "explicit Called" << endl;
	}
	P(std::initializer_list<int>)
	{
		cout << "Initializer Called" << endl;
	}

	void Print()
	{
		cout << "Print" << endl;
	}
};

void print(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p) // process a list of values
	{
		std::cout << *p << "\n";
	}
}
void fp(P p)
{
	p.Print();
}

class A {
public:
	int num;
	explicit A(int n) : num(n) {};
};
void printA(A a) {
	std::cout << a.num << std::endl;
}


int main()
{
	print({ 12,3,5,7,11,13,17 }); // pass a list of values to print()

	P p		(77,5); // calls P::P(int,int)
	P q		{77,5}; // calls P::P(initializer_list)
	P r		{77,5,42}; // calls P::P(initializer_list)
	P s =	{77,5}; // calls P::P(initializer_list)
	cout << endl;
	fp({ 47,11 }); // OK, implicit conversion of {47,11} into P
	fp({ 47,11,3 }); // expllicit�� �Ǿ� �ִ��� initializer_list�� ������ �װ� ȣ�� �Ѵ�.
	fp(P{ 47,11 }); // OK, explicit conversion of {47,11} into P
	fp(P{ 47,11,3 }); // OK, explicit conversion of {47,11,3} into P

	int num = 10;
	printA({ num }); //Error!
	return 0;
}