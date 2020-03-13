
#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int main()
{
	string s1;
	string s2;
	int len1 = 0;
	int len2 = 0;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), 'z' + 1);	// 使得 相减为 26
		vector<int> array;
		for (int i = 0; i < len2; i++)
		{
			array.push_back(s2[i] - s1[i]);
		}
		int result = 0;
		for (int i = len1; i <= len2; i++)
		{
			for (int k = 0; k < i; k++)
			{
				result += array[k] * pow(26, i - 1 - k);
			}
		}
		cout << result - 1 << endl;

	}
}