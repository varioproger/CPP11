#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

/*
• async() provides an interface to let a piece of functionality, a callable object, run in the background as a separate thread, if possible.
• Class future<> allows you to wait for the thread to be finished and provides access to its outcome: return value or exception, if any.
*/

int doSomething(char c)
{
	// random-number generator (use c as seed to get different sequences)
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10, 1000);
	// loop to print character after a random period of time
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	return c;
}
int func1()
{
	return doSomething('.');
}
int func2()
{
	return doSomething('+');
}
int main()
{
	std::cout << "starting func1() in background"
		<< " and func2() in foreground:" << std::endl;
	// start func1() asynchronously (now or later or never):
	// A call of async() does not guarantee that the passed functionality gets started and finished
	std::future<int> result1(std::async(func1)); // std::async([]{ ... }) // try to perform ... asynchronously

	int result2 = func2(); // call func2() synchronously (here and now)

	//we process the sum. This is the moment when we need the result of func1(). 
	//To get it, we call get() for the returned future 
	// print result (wait for func1() to finish and add its result to result2
	int result = result1.get() + result2;
	/*
	with the call of get(), one of three things might happen:
	1. If func1() was started with async() in a separate thread and has already finished, you immediately get its result.
	2. If func1() was started but has not finished yet, get() blocks and waits for its end and yields the result.
	3. If func1() was not started yet, it will be forced to start now and, like a synchronous function call, get() will block until it yields the result.
	*/
	
	std::cout << "\nresult of func1()+func2(): " << result
		<< std::endl;

	/*
	The returned future object is necessary for two reasons
	1. It allows access to the “future” outcome of the functionality passed to async().
	   If just a background task was started that returns nothing it has to be std::future<void>.

	2. It is necessary to ensure that sooner or later, the passed functionality gets called. 
	   Note that I wrote that async() tries to start the passed functionality. 
	   If this didn’t happen we need the future object to force a start when we need the result or want to ensure 
	   that the functionality was performed. 
	   Thus, you need the future object even if you are not interested in the outcome of a functionality started in the background.
	*/
}