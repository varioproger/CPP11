#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
int main()
{
	// two shared pointers representing two persons by their name
	shared_ptr<string> pNico(new string("nico"),
		[](string* p) {
			cout << "delete " << *p << endl;
			delete p;
		});
	shared_ptr<string> pJutta(new string("jutta"), [](string* p) {
		cout << "delete " << *p << endl;
		delete p;
		});
	getchar();
	return 0;
}