#include<iostream>
#include<utility>

using namespace std;

/*
std::move 는 어떤 객체 t 가 이동 될 수 있음 을 알려준다
다시 한 번 말하지만 std::move 는 이동을 수행하지 않는다.
이동 될 수 있음을 알려줄 뿐이다.
우측값 레퍼런스 타입으로 static_cast 하는 것과 동일하다.
move_if_noexcept : 생성자가 예외를 던지지 않을 경우에만 우측값 레퍼런스를 얻는다.
*/
class MyObj
{
	int* __data = nullptr;

public:
	MyObj() // 일반 생성자
	{
		__data = new int[3000];
		for (int i = 0; i < 3000; i++)
			__data[i] = 0;
	}

	MyObj(const MyObj& obj)// 복사 생성자
	{
		__data = new int[3000];
		for (int i = 0; i < 3000; i++)
			__data[i] = obj.__data[i];
		cout << "복사 생성자" << endl;

	}

	MyObj(MyObj&& obj) // 이동 생성자
	{
		__data = obj.__data; // 주소 복사
		obj.__data = nullptr; // 이전 객체에서 pointer는 삭제, 이동 완료.
		cout << "이동 생성자" << endl;
	}
	/* 다른곳에서 가져온 생성자 방식
	// Move constructor.
	MemoryBlock(MemoryBlock&& other) : _data(NULL), _length(0)
	{
		std::cout << "Move Constructor Length : " << other._length << std::endl;
		*this = std::move(other);
	}
	// Move assignment operator.
	MemoryBlock& operator=(MemoryBlock&& other)
	{
		std::cout << "Move assignment operator Length : " << _length << std::endl;
		if (this != &other)
		{
			// Free the existing resource.
			delete[] _data;

			_data = other._data;
			_length = other._length;

			other._data = NULL;
			other._length = 0;
		}

		return *this;
	}
	https://psychoria.tistory.com/59?category=556279 */

    virtual ~MyObj()
	{
		delete __data;
	}

	void set(int val)
	{
		for (int i = 0; i < 3000; i++)
			__data[i] = val;
	}
};

MyObj getMyObj()
{
	MyObj temp;
	temp.set(10);
	return std::move(temp);
	//사실 자체를 함수의 리턴값 부분에 생성해버리기 때문애  작업 속도를 더 늦추게 할 뿐입니다
}

int main(void)
{
	MyObj a = getMyObj();//(1) MyObj(const MyObj&& obj) 이동 생성자가 호출됨
	MyObj b = a; //(2) MyObj(const MyObj& obj) 복사 생성자가 호출됨.
	getchar();
	return 0;
}

