#include<iostream>
#include<utility>
using namespace std;

// ���� ǥ���� ���Ӽ��� ���� �� LValue��� �ϸ� ����(Scope) ���� �ٸ� �κп��� �ٽ� ����� ������ ���Դϴ�.
// RValue�� �̷� ���Ӽ��� ������ �ʴ� �ӽ����� ������ �ǹ��մϴ�.
// 3 + 4�� �ӽ÷� �����Ǵ� ��ü���� �ǹ��մϴ�.
// �� �� ���� ���ķδ� �ٽ� ������ �Ұ����մϴ�.
// RValue Reference�� ���ʿ��� ���縦 �����ؼ� ���� ��� ������ �ִ� ���ο� �����Դϴ�.
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