#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	while (cin >> n)
	{

		vector<int> a(n);
		for (long long i = 0; i<n; ++i)
			cin >> a[i];

		if (n == 1)// 直接输出
		{
			cout << a[0] << endl;
			return 0;
		}

		if (n % 2 == 0)// 偶数的话， 先倒序输出奇数位置上的， 再正序输出偶数位置上的
		{
			for (long long i = n - 1; i >= 0; i -= 2)
			{
				cout << a[i] << " ";
			}
			cout << a[0];
			for (long long i = 2; i<n - 1; i += 2)
				cout << " " << a[i];
		}
		else   // 奇数的话，先倒序输出偶数位置上的，再正序输出奇数位置上的。
		{
			for (long long i = n - 1; i >= 0; i -= 2)
			{
				cout << a[i] << " ";
			}
			cout << a[1];
			for (long long i = 1; i<n - 1; i += 2)
				cout << " " << a[i];
		}
		cout << endl;
	}
	return 0;
}