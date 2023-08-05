#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;
void doSomething(char c)
{
	// random-number generator (use c as seed to get different sequences)
	default_random_engine dre(c);
	uniform_int_distribution<int> id(10, 1000);
	// loop to print character after a random period of time
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
}
int main()
{
	cout << "starting 2 operations asynchronously" << endl;
	// start two loops in the background printing characters . or +
	auto f1 = async([] { doSomething('.'); });
	
	//there are three ways to pass parameter to the functionality
	// 1. auto f2 = async([] { doSomething('+'); });
	// 2.
	char c = '+';
	auto f2 = std::async([=] { // =: can access objects in scope by value
		doSomething(c); // pass copy of c to doSomething()
		});

	// 3. auto f = std::async(doSomething, c); // call doSomething(c) asynchronously
	/*
	You can also pass arguments by reference, 
	but the risk of doing so is that the values passed become invalid before the background task even starts.
	So, let me make clear: If you start to use async(), you should pass all objects necessary to process the passed functionality 
	by value so that async() uses only local copies.
	*/
	// if at least one of the background tasks is running
	if (f1.wait_for(chrono::seconds(0)) != future_status::deferred ||
		f2.wait_for(chrono::seconds(0)) != future_status::deferred) {
		// poll until at least one of the loops finished
		while (f1.wait_for(chrono::seconds(0)) != future_status::ready &&
			f2.wait_for(chrono::seconds(0)) != future_status::ready) {
			this_thread::yield(); // hint to reschedule to the next thread
		}
	}
	cout.put('\n').flush();
	// wait for all loops to be finished and process any exception
	try {
		f1.get();
		f2.get();
	}
	catch (const exception& e) {
		cout << "\nEXCEPTION: " << e.what() << endl;
	}
	cout << "\ndone" << endl;
}
