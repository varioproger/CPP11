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
T* factory(A1&& a1, A2&& a2)//  lvalue 를 T 에 따라 lvalue 혹은 rvalue 로 전달한다.
{
	// std::foward는 static_cast를 통해서 T&& 타입으로 변환해주는 템플릿 함수입니다.
	// Reference Collapsing Rules을 사용하기 때문
	return new T(std::forward<A1>(a1), std::forward<A2>(a2)); // Forward as lvalue or as rvalue, depending on T
}
int main()
{
	int a = 4, b = 5;
	W* pw = factory<W>(a, b);

	// error C2664: 'factory' : cannot convert parameter 1 from 'int' to 'int &'
	// Z* pz = factory<Z>(2, 2);// RValue를 전달하기 때문
	// 해결하기 위해서 const T&와 T& 타입의 모든 조합으로 factory를 작성해야 했습니다.
	delete pw;

	getchar();
	return 0;
}