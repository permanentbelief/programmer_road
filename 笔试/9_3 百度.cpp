#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//string s;
//int x, y;
//
//const int N = 1e5;
//int w[N];
//int p[N];
//int v[N];
//int f[N][N][10000];
//
//int n, m, k;
//int main()
//{
//	cin >> n >> m >> k; // ���� ������� Ԥ��k
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> p[i] >> w[i] >> v[i];
//	}
//
//	// f[i][j][k] = 1 : ѡ��i����Ʒ ʱ �۸�Ϊ j����Ʒ��Ŀ ��ǰ��Ԥ��Ϊk��ʱ�� k M
//
//	f[0][0][0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; w[i] <= m; j++)
//		{
//			for (int kk = 1; kk <= k; kk++)
//			{
//				f[i][j][kk] = f[i - 1][j][kk];
//				if (j >= w[i] && p[i] <= kk)
//					f[i][j][kk] = max(f[i][j][kk], f[i][j - w[i]][kk - p[i]] + v[i]);
//			}
//
//		}
//	}
//
//	cout << f[n][m][k] << endl;
//
//	system("pause");
//
//}