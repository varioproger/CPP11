#include<iostream>
#include<utility>
using namespace std;

// 식이 표현이 지속성을 가질 때 LValue라고 하며 범위(Scope) 내의 다른 부분에서 다시 사용이 가능한 값입니다.
// RValue는 이런 지속성을 가지지 않는 임시적인 값들을 의미합니다.
// 3 + 4나 임시로 생성되는 객체들을 의미합니다.
// 한 번 사용된 이후로는 다시 참조가 불가능합니다.
// RValue Reference는 불필요한 복사를 제거해서 성능 향상에 도움을 주는 새로운 개념입니다.
void Test(int& num)
{
	cout << "L Value" << endl;
}
void Test(int&& num)
{
	cout << "R Value" << endl;
}
int main()
{
	int nVal = 10;
	Test(nVal);
	Test(10);
	getchar();
	return 0;
}