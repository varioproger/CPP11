#include<iostream>
using namespace std;

constexpr int N1 = 10;
constexpr int N2 = 10;
constexpr int N3 = N1 + N2;

/*
constexpr �Լ��� �ڵ带 ����� �� �ʿ��� ��� ������ �ð��� ��ȯ ���� ����� �� �ִ� �Լ��Դϴ�. 
�ڵ带 ����Ϸ��� ������ �� ��ȯ ���� ������ constexpr �ʱ�ȭ�ϰų� ������ �ƴ� ���ø� �μ��� �����ؾ� �մϴ�. 
�μ��� ���̸� constexpr �Լ��� constexpr ������ �ð� constant�� �����մϴ�.
�μ�constexpr �� �ƴ� �μ��� ����Ͽ� ȣ��ǰų� ������ �ð��� �ش� ���� �ʿ����� ���� ��� ��Ÿ�ӿ� �Ϲ� �Լ��� ���� ���� �����մϴ�.

�Լ����� constexpr ���� ��Ģ�� ����˴ϴ�.

�Լ��� constexpr���ͷ� ���ĸ� �����ϰ� ��ȯ�ؾ� �մϴ�.

�Լ��� constexpr ������� �� �ֽ��ϴ�.

������ �� �����ϴ�. const�ٱ��� Ŭ������ ���� �⺻ Ŭ������ �ִ� ���ó�� constexpr ���͸� ������ �� �����ϴ�.

������ = default �Ǵ� = delete�� ������ �� �ֽ��ϴ�.

�������� ���̳� try ����� ���Ե� �� �����ϴ�goto.

�� ���ø�constexpr �� ����� Ư��ȭ�� ������ ���� constexpr������ �� �ֽ��ϴ�.

���ø��� constexpr ����� Ư��ȭ�� ������ �ʿ䰡 constexpr�����ϴ�.
*/


/*
Extern constexpr
/Zc:externConstexpr �����Ϸ� �ɼ��� ����ϸ� �����Ϸ��� externconstexpr�� ����Ͽ� ����� ������ �ܺ� ������ �����մϴ�.
���� ������ Visual Studio �⺻������ �Ǵ� /Zc:externConstexpr-�� ����if�Ǹ� Visual Studio Ű���带 ����ϴ� ��쿡�� extern ������ constexpr ���� ������ �����մϴ�. 
/Zc:externConstexpr �ɼ��� Visual Studio 2017 ������Ʈ 15.6���� ����� �� ������ �⺻������ ���� �ֽ��ϴ�. 
/permissive- �ɼ��� /Zc:externConstexpr�� ����ϵ��� �������� �ʽ��ϴ�.
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