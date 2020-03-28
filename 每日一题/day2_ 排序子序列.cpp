#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	vector<int> v;
	int sum = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);   // 将输入的数字放在数组里
	}
	for (int i = 1; i<n - 1; i++)
	{
		if ((v[i] > v[i - 1] && v[i]>v[i + 1]) ||
			(v[i] < v[i - 1] && v[i] <v[i + 1]))    //找到波峰或波谷
		{
			++sum;
			if (i != n - 3)
				++i;
			else
				break;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
