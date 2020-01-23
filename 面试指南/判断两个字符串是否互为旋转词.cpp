#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isRotation(string& a, string& b)
{
	if (a.size() != b.size())
		return false;
	for (int k = 0; k < a.size() - 1; k++)
	{
		string str = a;
		for (int i = 0; i < a.size(); i++) // abcd
		{
			str[i] = a[(i + k) % a.size()];
		}
		if (str == b)
			return true;
	}
	return false;

}
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		cout << isRotation(str1, str2) << endl;
	}
	system("pause");
}