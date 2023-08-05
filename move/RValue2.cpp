#include <iostream>
using namespace std;

// Named RValue Reference�� LValue��, Unnamed RValue Reference�� RValue�� ó���Ѵ�.
// RValue�� RValue Reference�� ���ؼ� �����Ǹ� �ش� ���� LValue�� ó���ȴٴ� �ǹ��Դϴ�.
// A class that contains a memory resource.
class MemoryBlock
{
};

void g(const MemoryBlock&)
{
	cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
	cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block)
{
	g(block);// f() �Լ��� RValue�� ������������, f() �Լ� ���� block�� ���ο��� LValueó�� �ٷ�����.
	// LValue�� RValue Reference�� ĳ���� �����ϴ�
	// std::move()�� �̿��ؼ� LValue�� �ٷ����� block�� RValue Reference�� ��������ϴ�.
	return std::move(block);
}

int main()
{
	g(f(MemoryBlock()));// std::move�� �����ϰ� �Ǹ� RValue�� ó���Ǹ鼭 g(MemoryBlock&&)�� ����˴ϴ�.
	getchar();
	return 0;
}