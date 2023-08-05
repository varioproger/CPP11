#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<float> collf; // deque container front
	deque<float> collb; // deque container back

	// insert elements from 1.1 to 6.6 each at the front
	for (int i = 1; i <= 6; ++i) {
		collf.push_front(i * 1.1f); // insert at the front
		collb.push_back(i * 1.1f); // insert at the back
	}
	cout << "size " << collf.size() << endl;

	// print all elements followed by a space
	for (int i = 0; i < collf.size(); ++i) {
		cout << collf[i] << ' ';
	}
	cout << endl;

	// print all elements followed by a space
	for (int i = 0; i < collb.size(); ++i) {
		cout << collb[i] << ' ';
	}
	cout << endl;

	size_t size = collf.size();
	// print all elements followed by a space
	for (int i = 0; i < size; ++i) {
		float temp = collf.front();
		collf.pop_front();
		cout << temp << endl;
	}
	cout << endl;

	size = collb.size();
	// print all elements followed by a space
	for (int i = 0; i < size; ++i) {
		float temp = collb.back();
		collb.pop_back();
		cout << temp << endl;
	}
	cout << endl;
}