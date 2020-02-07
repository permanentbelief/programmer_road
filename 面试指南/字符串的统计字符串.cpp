#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string GetCountString(string str)
{
	vector<int> v;
	int count = 0;
	int i = 0;
	while (i < str.size())
	{
		count = 1;
		while (i < str.size() && str[i] == str[i + 1])
		{
			i++;
			count++;
		}
		v.push_back(count);
		i++;
	}
	i = 0;
	while (i < str.size() && str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			for (int j = i; j < str.size(); j++)
			{
				str[j] = str[j + 1];
			}
			str.erase(--str.end());
			i -= 1;
		}
		i++;
	}
	string str1;
	for (int i = 0; i < v.size(); i++)
	{
		str1 += str[i];
		str1 += '_';
		str1 += to_string(v[i]);
		if (i < v.size() - 1)
		str1 += '_';
	}
	
	return str1;
}
int main()
{
	string str;
	str = GetCountString("aabbddddDDDDDDDDDDDDDDD");
	cout << str << endl;
	system("pause");
}