// header files for file I/O
#include <fstream>
#include <iostream>
using namespace std;
// for all filenames passed as command-line arguments
// - open, print contents, and close file
int main(int argc, char* argv[])
{
	ifstream file;
	// for all command-line arguments
	for (int i = 1; i < argc; ++i) {
		// open file
		file.open(argv[i]);
		// write file contents to cout
		char c;
		while (file.get(c)) {
			cout.put(c);
		}
		// clear eofbit and failbit set due to end-of-file
		file.clear();
		// close file
		file.close();
	}
}