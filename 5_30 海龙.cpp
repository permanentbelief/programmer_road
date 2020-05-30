#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



class String
{
public:
	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
	{

		delete[] _str;
		_str = (char*)malloc(strlen(s._str) + 1);
		strcpy(_str, s._str);
	}
	~String()
	{
		delete[] _str;
	}
private:
	char* _str;
};
void test()
{
	String s("str");
	String ss(s);
}
int main()
{
	test();

	system("pause");
}