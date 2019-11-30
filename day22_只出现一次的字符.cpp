#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main()
{

	string str;
	int flag = 0;
	while (cin >> str)
	{
		vector<int> count(256, 0);
		for (int i = 0; i < str.size(); i++)
		{
			count[str[i]]++;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (count[str[i]] == 1)
			{
				cout << str[i] << endl;
				flag = 1;
				break;
			}

		}
		if (flag == 0)
			cout << -1 << endl;
	}
	system("pause");
}