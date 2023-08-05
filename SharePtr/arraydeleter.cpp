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

	//11에서는 안되지만 14 이상에서는 컴파일 됩니다.
	std::shared_ptr<int[]> p(new int[10],
							[](int* p) {
								delete[] p;
								cout << "P" << endl;
							}); 
	
	getchar();
	return 0;
}