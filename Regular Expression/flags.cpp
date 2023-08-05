// regex/regex4.cpp
#include <string>
#include <regex>
#include <iostream>
using namespace std;
int main()
{
	// case-insensitive find LaTeX index entries
	string pat1 = R"(\\.*index\{([^}]*)\})"; // first capture group
	string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})"; // 2nd and 3rd capture group
	regex pat(pat1 + "\n" + pat2,
		regex_constants::egrep | regex_constants::icase);
	// initialize string with characters from standard input:
	string data((istreambuf_iterator<char>(cin)),
		istreambuf_iterator<char>());
	// search and print matching index entries:
	cout << "NONO" << endl;
	smatch m;
	auto pos = data.cbegin();
	auto end = data.cend();
	for (; regex_search(pos, end, m, pat); pos = m.suffix().first) {
		cout << "match: " << m.str() << endl;
		cout << " val: " << m.str(1) + m.str(2) << endl;
		cout << " see: " << m.str(3) << endl;
	}

	/*
	i can't find the way to end. will input do it later

	With the following input:
	\chapter{The Standard Template Library}
	\index{STL}%
	\MAININDEX{standard template library}%
	\SEEINDEX{standard template library}{STL}%
	This is the basic chapter about the STL.
	\section{STL Components}
	\hauptindex{STL, introduction}%
	The \stl{} is based on the cooperation of
	...

	the program has the following output:
	match: \index{STL}
	val: STL
	see:
	match: \MAININDEX{standard template library}
	val: standard template library
	see:
	match: \SEEINDEX{standard template library}{STL}
	val: standard template library
	see: STL
	match: \hauptindex{STL, introduction}
	val: STL, introduction
	see:
	*/
}
