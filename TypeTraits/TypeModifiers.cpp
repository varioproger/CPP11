#include<iostream>
#include<type_traits>
using namespace std;

// 설명은 txt 파일에 있으니 그거 읽으면 됩니다.
int main()
{
	cout << is_const<int* const>::value << endl; // true
	
	cout << rank<int>::value << endl;// 0
	cout << rank<int[]>::value << endl;// 1
	cout << rank<int[5]>::value << endl;// 1
	cout << rank<int[][7]>::value << endl;// 2
	cout << rank<int[5][7]>::value << endl;// 2

	cout << extent<int>::value << endl;// 0
	cout << extent<int[]>::value << endl;// 0
	cout << extent<int[5]>::value << endl;// 5
	cout << extent<int[][7]>::value << endl;// 0
	cout << extent<int[5][7]>::value << endl;// 5
	cout << extent<int[][7], 1>::value << endl;// 7
	cout << extent<int[5][7], 1>::value << endl;// 7
	cout << extent<int[5][7], 2>::value << endl;// 0


	remove_extent<int>::type;
	remove_extent<int[]>::type; // int
	remove_extent<int[5]>::type; // int
	remove_extent<int[][7]>::type; // int[7]
	remove_extent<int[5][7]>::type; // int[7]
	remove_all_extents<int>::type; // int
	remove_all_extents<int[]>::type; // int
	remove_all_extents<int[5]>::type; // int
	remove_all_extents<int[][7]>::type; // int
	remove_all_extents<int[5][7]>::type; // int
	getchar();
	return 0;
}