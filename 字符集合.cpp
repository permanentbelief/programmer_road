#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;

	while (cin >> str)
	{
		string char_str;
		for (int i = 0; i < str.size(); i++)
		{
			int flag = 0;
			for (int j = 0; j < char_str.size(); j++)
			{
				if (str[i] == char_str[j])
				{
					flag = 1;
				}
			}
			if (flag != 1)
			{
				char_str.push_back(str[i]);
			}
		}
		cout << char_str << endl;
	}
	system("pause");


}