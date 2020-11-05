#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


const int N = 150;

int a[N];

int cnt = 0;
void func(int n, int last)
{
	for (int i = 1; i <= last / 2; i++)
	{
		// cout << n * 10 + i << endl;
		func(n * 10 + i, i);
		cnt++;
	}
}

//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i / 2; j++)
//		{
//			f[i] += f[j];
//		}
//		f[i]++;
//	}
//	cout << f[n] << endl;
//
//	return 0;
//}

int main()
{
	int n = 0;
	cin >> n;
	func(n, n);

	cout << cnt + 1 << endl;

}

