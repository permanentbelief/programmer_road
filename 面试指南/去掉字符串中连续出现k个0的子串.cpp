#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string removeKzeros(string str, int k)
{
	int count = 0;
	int flag = 0;
	for (int i = 0; i < str.size(); i++) // a00e
	{
		count = 0;
		while (i < str.size() && str[i] == '0')
		{
			count++;
			i++;
			if (count == k)
			{
				break;
			}
		}
		if (count == k)
		{
			flag = i;
			break;
		}
	}
	for (int i = flag - count; i + k < str.size(); i++)
	{
		str[i] = str[i + k];
	}
	for (int i = 0; i < k; i++)
	{
		str.erase(--str.end());
	}
	return str;
}
int main()
{
	string str = "A00B000CCC";
	cout << removeKzeros(str, 3) << endl;
	system("pause");
}