#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
int main()
{
	std::shared_ptr<int> pOne(new int[10],
					std::default_delete<int[]>());

	std::shared_ptr<int> pTwo(new int[10],
							  [](int* p) {
							  	delete[] p;
							  });

	//11������ �ȵ����� 14 �̻󿡼��� ������ �˴ϴ�.
	std::shared_ptr<int[]> p(new int[10],
							[](int* p) {
								delete[] p;
								cout << "P" << endl;
							}); 
	
	getchar();
	return 0;
}