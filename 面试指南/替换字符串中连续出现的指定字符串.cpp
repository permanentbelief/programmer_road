#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string replace(string str, string from, string to)
{
	int match = 0;
	vector<int> v;
	string outcome;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == from[match])
		{
			while (i < str.size() && match < from.size() && str[i] == from[match])
			{
				i++;
				match++;
			}
			if (match == from.size())  // 11abc22  
			{
				for (int j = i - match; j < i; j++)
				{
					str[j] = 0;
				}
				match = 0;
				i -= 1;
			}
			else {
				match = 0;
			}
		}
		else
			continue;

	}
	int k = 0;
	while (k < str.size())
	{
		while (k < str.size() && str[k] != 0)
		{
			outcome += str[k];
			k++;
		}
		if (k < str.size() && str[k] == 0)
			outcome += to;
		while (k < str.size() && str[k] == 0)
		{
			k++;
		}
		

	}
	/*	
	    //我的这种方法只能将一个from转化为对应的一个to
		for (int j = 0; j < v[0] - match; j++)
		{
			outcome += str[j];
		}
		outcome += to;
		for (int j = v[0]; j < str.size(); j++)
		{
			outcome += str[j];
		}
*/
	

	return outcome;
}

int main()
{
	string str = "12abcabc4abca";
	string str1 = replace(str, "abc", "X");
   cout << str1 << endl;
	system("pause");
}