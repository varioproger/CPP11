#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;
milliseconds ms(86400000); // 24 ½Ã°£

int main()
{
	// split into hours, minutes, seconds, and milliseconds
	hours hh = duration_cast<hours>(ms);
	minutes mm = duration_cast<minutes>(ms % chrono::hours(1));
	seconds ss = duration_cast<seconds>(ms % chrono::minutes(1));
	milliseconds msec = duration_cast<milliseconds>(ms % chrono::seconds(1));
	// and print durations and values:
	cout << "raw: " << hh.count() << "::" << mm.count() << "::"
		<< ss.count() << "::" << msec.count() << endl;
	getchar();
	return 0;
}