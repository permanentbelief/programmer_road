#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//using namespace std;
//
//#define MOD 19650827
//int f[1100][1100][2];
//
//int n;
//int a[1100];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		f[i][i][0] = 1;
//	}
//
//
//	for (int l = 2; l <= n; l++)
//	{
//		for (int i = 1; i + l - 1 <= n; i++)
//		{
//			int j = i + l - 1;
//			if (a[j] > a[j - 1])
//				f[i][j][1] += f[i][j - 1][1];
//			if (a[j] > a[i])
//				f[i][j][1] += f[i][j - 1][0];
//			if (a[i] < a[i + 1])
//				f[i][j][0] += f[i + 1][j][0];
//			if (a[i] < a[j])
//				f[i][j][0] += f[i + 1][j][1];
//
//			f[i][j][0] %= MOD;
//			f[i][j][1] %= MOD;
//		}
//	}
//	cout << (f[1][n][0] + f[1][n][1]) % MOD;
//}


// ×Ö·û´®ÕÛµþ

//#include <bits/stdc++.h>
//
//using namespace std;
//
//string st;
//int n, m[110], f[110][110];
//
//bool check(int l, int r, int len)
//{
//	for (int i = l; i <= r; i++)
//	{
//		if (st[i] != st[(i - l) % len + l]) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	cin >> st;
//	int n = st.size();
//	st = ' ' + st;
//	for (int i = 1; i <= 9; i++) m[i] = 1;
//	for (int i = 10; i <= 99; i++) m[i] = 2;
//	m[100] = 3;
//	memset(f, 0x3f, sizeof f);
//	for (int i = 1; i <= n; i++) f[i][i] = 1;
//	for (int l = 2; l <= n; l++)
//	{
//		for (int i = 1; i + l - 1 <= n; i++)
//		{
//			int j = i + l - 1;
//			for (int k = i; k < j; k++)
//			{
//				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
//			}
//			for (int k = i; k < j; k++)
//			{
//				int len = k - i + 1;
//				if (l % len) continue;
//				if (check(i, j, len)) f[i][j] = min(f[i][j], f[i][k] + 2 + m[l / len]);
//			}
//		}
//	}
//	cout << f[1][n] << endl;
//}

const int N = 10;
int a[N];
int num = 0;
int count1 = 0;
int counts[N];
int main()
{
	vector<int>v  = { 1, 1, 1, 2, 3, 4, 5, 2, 2, 2 };
	a[num] = v[0];
	
	count1 = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == a[num]) count1++;
		else
		{
			counts[num] = count1;
			
			num++;
			a[num] = v[i];
			count1 = 1;
		}
	}
	counts[num] = count1;

	for (int i = 0; i <= num; i++)
		cout << a[i] << " ";

	cout << endl;
	
	for (int i = 0; i <= num; i++)
		cout << counts[i] << " ";
	system("pause");
	
}