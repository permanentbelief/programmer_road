#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>




//using namespace std;
//const int N = 1e5 + 100;
//
//int n, k;
//
//
//bool st[N];
//int a[N];
//int max_ = INT_MIN;
//
//const int mod = 1000000009;
//void dfs(int u, int t)
//{
//	if (u > n)
//		return;
//	if (t == k)
//	{
//		long long sums = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (st[i])
//			{
//				sums += a[i];
//				cout << a[i] << " ";
//			}
//			cout << endl;
//			sums %= mod;
//		}
//		max_ = max((long long)max_, sums);
//
//
//	}
//	st[u] = 1;
//	dfs(u + 1, t + 1);
//
//	st[u] = 0;
//	dfs(u + 1, t);
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	dfs(1, 0);
//	cout << max_ << endl;
//	system("pause");
//}