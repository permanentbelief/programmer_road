#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();

		vector<vector<int>> vv(len1, (vector<int>(len2, 0)));
		vv[0][0] = str1[0] == str2[0] ? 1 : 0;
		for (int i = 1; i < len2; i++)
		{
			vv[0][i] = max(vv[0][i - 1], str1[0] == str2[i] ? 1 : 0);
		}
		for (int i = 1; i < len1; i++)
		{
			vv[i][0] = max(vv[i - 1][0], str1[i] == str2[0] ? 1 : 0);
		}
		for (int i = 1; i < len1; i++)
		{
			for (int j = 1; j < len2; j++)
			{
				vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]);
				if (str1[i] == str2[j])
				{
					vv[i][j] = max(vv[i][j], vv[i - 1][j - 1] + 1);
				}
			}
		}
		int mmax = vv[len1 - 1][len2 - 1];
		int m = len1 - 1;
		int n = len2 - 1;
		string str;
		str.resize(mmax);
		int index = mmax - 1;
		while (index >= 0)
		{
			if (n >= 1 && vv[m][n] == vv[m][n-1])
			{
				n--;
			}
			else if (m >= 1 && vv[m][n] == vv[m-1][n])
			{
				m--;
			}
			else
			{
				str[index--] = str1[m];
				m--;
				n--;
			}
		}
		cout << str;
		cout << endl;
	}


}