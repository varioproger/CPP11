#include<iostream>
#include<chrono>

int main()
{
	std::chrono::seconds twentySeconds(20);
	std::chrono::hours aDay(24);
	std::chrono::milliseconds oneMillisecond(1);

	std::chrono::seconds sec(55);
	//std::chrono::minutes m1 = sec; // ERROR
	std::chrono::minutes m2 = std::chrono::duration_cast<std::chrono::minutes>(sec); // OK

	std::chrono::duration<double, std::ratio<60>> halfMin(0.5);
	//std::chrono::seconds s1 = halfMin; // ERROR
	std::chrono::seconds s2 = std::chrono::duration_cast<std::chrono::seconds>(halfMin); // OK


	getchar();
	return 0;
}