#include <memory> // for shared_ptr
#include <fcntl.h>
#include <cstring> // for strerror()
#include <cerrno> // for errno
#include <string>
#include <iostream>
#include<fstream>

using namespace std;
// You can understand this to specify your own destruction policy
class FileDeleter
{
private:
	std::string filename;
public:
	FileDeleter(const std::string& fn)
		: filename(fn) {
	}
	void operator () (std::ofstream* fp) {
		fp->close(); // close.file
		std::remove(filename.c_str()); // delete file
	}
};


int main()
{
	// create and open temporary file
	std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
									FileDeleter("tmpfile.txt"));
	getchar();
	return 0;

}