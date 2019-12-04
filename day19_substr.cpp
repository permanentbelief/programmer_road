#define _CRT_SECURE_NO_WARNINGS 1 
// string::substr
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string str = "We think in generalities, but we live in details.";
	
	std::string str2 = str.substr(3, 5);     // "think"

	std::size_t pos = str.find("we");      // position of "live" in str

	std::string str3 = str.substr(pos);     // get from "live" to the end

	cout << str2 << endl;
	cout << str3 << endl;
	system("pause");
	return 0;
}