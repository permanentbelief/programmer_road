#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void transform(vector<int>& v1, string& str1)
{
	for (int i = 0; i < str1.size(); i++)
	{
		int temp = 0;
		while (i < str1.size() && str1[i] != ',')
		{
			temp = temp * 10 + (str1[i] - '0');
			i++;
		}
		v1.push_back(temp);
	}
}
int main()
{
	string str1;
	string str2;
	while (getline(cin,str1) && getline(cin,str2))
	{
		if (str1.empty())
		{
			cout << str2 << endl;
			continue;
		}
		if (str2.empty())
		{
			cout << str1 << endl;
			continue;
		}
		vector<int> v1;
		vector<int> v2;

		transform(v1, str1);
		transform(v2, str2);
		vector<int> v3(v1.size() + v2.size());
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < str1.size() && j < str2.size())
		{
			if (str1[i] < str2[j])
			{
				v3[k++] = v1[i++];
			}
			else
			{
				v3[k++] = v2[j++];
			}
		}
		if (i <str1.size())
		{
			for (int num = i; num < v1.size(); num++)
			{
				v3[k++] = v1[num];
			}
		}
		else
		{
			for (int num = j; num < v2.size(); num++)
			{
				v3[k++] = v2[num];
			}
		}
		for (int i = 0; i < v3.size(); i++)
		{
			cout << v3[i];
			if (i != v3.size() - 1)
				cout << ",";
		}
	}
}