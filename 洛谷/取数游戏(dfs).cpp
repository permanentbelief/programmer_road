#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
// 注意这里的 bool vis[]不能用bool判断， 要用int类型判断，会有覆盖
//using namespace std;
//const int N = 10;
//int T, n, m;
//int a[N][N];
//bool vis[N][N];
//int max_ans = 0;
//static int pos[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };
//int ans = 0;
//
//void dfs(int x, int y)
//{
//	if (y == m + 1)
//	{
//		dfs(x + 1, 1);
//		return;
//	}
//	if (x == n + 1)
//	{
//		max_ans = max(max_ans, ans);
//		return;
//	}
//	dfs(x, y + 1);
//
//	if (vis[x][y] == false)
//	{
//		ans += a[x][y];
//		for (int i = 0; i < 8; i++)
//		{
//			vis[x][y] = true;
//			vis[x + pos[i][0]][y + pos[i][1]] = true;
//		}
//		dfs(x, y + 1);
//		for (int i = 0; i < 8; i++)
//		{
//			vis[x][y] = false;
//			vis[x + pos[i][0]][y + pos[i][1]] = false;
//		}
//		ans -= a[x][y];
//	}
//
//	
//}
//int main()
//{
//	cin >> T;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> n >> m;
//		memset(a, 0, sizeof a);
//		memset(vis, false, sizeof vis);
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				cin >> a[i][j];
//			}
//		}
//		max_ans = 0;
//		ans = 0;
//		dfs(1, 1);
//		cout << max_ans << endl;
//	}
//	system("pause");
//}