#include<iostream>
using namespace std;

constexpr int N1 = 10;
constexpr int N2 = 10;
constexpr int N3 = N1 + N2;

/*
constexpr 함수는 코드를 사용할 때 필요한 경우 컴파일 시간에 반환 값을 계산할 수 있는 함수입니다. 
코드를 사용하려면 컴파일 시 반환 값이 변수를 constexpr 초기화하거나 형식이 아닌 템플릿 인수를 제공해야 합니다. 
인수가 값이면 constexpr 함수는 constexpr 컴파일 시간 constant를 생성합니다.
인수constexpr 가 아닌 인수를 사용하여 호출되거나 컴파일 시간에 해당 값이 필요하지 않은 경우 런타임에 일반 함수와 같은 값을 생성합니다.

함수에는 constexpr 다음 규칙이 적용됩니다.

함수는 constexpr리터럴 형식만 수락하고 반환해야 합니다.

함수는 constexpr 재귀적일 수 있습니다.

가상일 수 없습니다. const바깥쪽 클래스에 가상 기본 클래스가 있는 경우처럼 constexpr 벡터를 정의할 수 없습니다.

본문은 = default 또는 = delete로 정의할 수 있습니다.

본문에는 문이나 try 블록이 포함될 수 없습니다goto.

비 템플릿constexpr 의 명시적 특수화는 다음과 같이 constexpr선언할 수 있습니다.

템플릿의 constexpr 명시적 특수화는 다음일 필요가 constexpr없습니다.
*/


/*
Extern constexpr
/Zc:externConstexpr 컴파일러 옵션을 사용하면 컴파일러가 externconstexpr을 사용하여 선언된 변수에 외부 연결을 적용합니다.
이전 버전의 Visual Studio 기본적으로 또는 /Zc:externConstexpr-가 지정if되면 Visual Studio 키워드를 사용하는 경우에도 extern 변수에 constexpr 내부 연결을 적용합니다. 
/Zc:externConstexpr 옵션은 Visual Studio 2017 업데이트 15.6부터 사용할 수 있으며 기본적으로 꺼져 있습니다. 
/permissive- 옵션은 /Zc:externConstexpr을 사용하도록 설정하지 않습니다.
*/
constexpr int GetNum(int num)
{
	return num;
}
int main()
{
	constexpr int temp = GetNum(2);
	
	return 0;
}