#include <iostream>
using namespace std;

// Named RValue Reference를 LValue로, Unnamed RValue Reference를 RValue로 처리한다.
// RValue가 RValue Reference를 통해서 참조되면 해당 값은 LValue로 처리된다는 의미입니다.
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
	g(block);// f() 함수에 RValue를 전달해줬으나, f() 함수 내의 block은 내부에서 LValue처럼 다뤄진다.
	// LValue를 RValue Reference로 캐스팅 가능하다
	// std::move()를 이용해서 LValue로 다뤄지는 block을 RValue Reference로 만들었습니다.
	return std::move(block);
}

int main()
{
	g(f(MemoryBlock()));// std::move로 리턴하게 되면 RValue로 처리되면서 g(MemoryBlock&&)이 실행됩니다.
	getchar();
	return 0;
}