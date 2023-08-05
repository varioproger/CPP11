#include<iostream>
using namespace std;


int main()
{
	pair<int, int> temp1(1, 2);
	pair<int, int> temp2{1, 2 };
	pair<int, int> temp3 = make_pair(1, 2);// Using make_pair() should cost no runtime. The compiler should always optimize any implied overhead.

	cout << temp1.first << " " << temp1.second << endl;
	cout << temp2.first << " " << temp2.second << endl;
	cout << temp3.first << " " << temp3.second << endl;

	return 0;
}