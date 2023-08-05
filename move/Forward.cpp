#include<iostream>
#include<utility>

using namespace std;

struct W
{
	W(int&, int&){}
};

struct X
{
	X(const int&, int&){}
};

struct Y
{
	Y(int&, const int&){}
};

struct Z
{
	Z(const int&, const int&){}
};


template <class T, class A1, class A2>
T* factory(A1&& a1, A2&& a2)//  lvalue �� T �� ���� lvalue Ȥ�� rvalue �� �����Ѵ�.
{
	// std::foward�� static_cast�� ���ؼ� T&& Ÿ������ ��ȯ���ִ� ���ø� �Լ��Դϴ�.
	// Reference Collapsing Rules�� ����ϱ� ����
	return new T(std::forward<A1>(a1), std::forward<A2>(a2)); // Forward as lvalue or as rvalue, depending on T
}
int main()
{
	int a = 4, b = 5;
	W* pw = factory<W>(a, b);

	// error C2664: 'factory' : cannot convert parameter 1 from 'int' to 'int &'
	// Z* pz = factory<Z>(2, 2);// RValue�� �����ϱ� ����
	// �ذ��ϱ� ���ؼ� const T&�� T& Ÿ���� ��� �������� factory�� �ۼ��ؾ� �߽��ϴ�.
	delete pw;

	getchar();
	return 0;
}