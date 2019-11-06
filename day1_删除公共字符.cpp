#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;

int main()  // O(n^3) 时间复杂度太大
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				str1[i] = '*';
			}
		}
	}
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i];
	}
	cout << endl;

	int m = str1.size();
	for (int i = 0; i < str1.size(); i++)
	{

		while(str1[i] == '*')
		{
			for (int j = i; j < str1.size() ; j++)
			{
				str1[j] = str1[j + 1];
			}
			
		}
		m--;
	
	}
	cout << str1 << endl;
	system("pause");
}