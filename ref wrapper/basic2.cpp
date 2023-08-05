#include<iostream>
#include<functional>
#include<vector>

class C {
public:
	void memfunc(int x, int y) const
	{
		std::cout << x << " class Function " << y << std::endl;
	}
};


void func(int x, int y)
{
	std::cout << x << " Function " << y << std::endl;
}

int main()
{
	// initialize collections of tasks:
	std::vector<std::function<void(int, int)>> tasks;

	// if you have a function implement
	tasks.push_back(func);
	
	// if you are not
	tasks.push_back([](int x, int y) {
				std::cout << x << " Lambda " << y << std::endl;
		});
	// call each task:
	for (std::function<void(int, int)> f : tasks) {
		f(33, 66);
	}

	for (int i = 0; i < tasks.size(); i++)
	{
		tasks.at(i)(i, i);
	}


	// class function wrapper
	std::function<void(const C&, int, int)> mf;
	mf = &C::memfunc;
	mf(C(), 42, 77);
}