#include<iostream>

using namespace std;

/*
u8 defines a UTF-8 encoding : const char
u defines a string literal with characters of type char16_t.
U defines a string literal with characters of type char32_t.
L defines a wide string literal with characters of type wchar_t.
*/
int main()
{
	auto s1 = u8R"("How old are you?")";
	auto s2 = uR"("How old are you?")";//  unsigned integer type used for 16-bit wide characters
	auto s3 = R"("How old are you?")";
	const char* s5 =
		R"(<cmd action=CMD_InsertCharacterInfo version=2.0>
   <param>
       <uid v=123 />
       <gameCodeId v=18204 />
       <serverId v=2 />
       <charName v="°¡°¼°Å°Ü" />
   </param>
</cmd> 
)";
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s5 << endl;
	return 0;
}