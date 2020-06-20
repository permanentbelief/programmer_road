#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//const int N = 20;
//
//char g[N][N]; //存储棋盘
//int ans = 0; // 存储答案
//
//int k = 0; 
//int m = 0; // 存储当前已放入棋盘上的棋子数
//
//
//bool line[N];
//
//void dfs(int x)
//{
//	if (m == k)
//	{
//		// 当棋子放光的时候
//		ans++;
//		return;
//	}
//	if (x == n)
//		return;
//	for (int i = 0; i < n; i++)
//	{
//		if (!line[i] && g[x][i] == '#')
//		{
//			line[i] = true;
//			m++; // 放入一枚棋子
//			dfs(x + 1); //下一行遍历
//			line[i] = false;
//			m--;
//		}
//	}
//	dfs(x + 1); //直接进行入下一行
//
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d %d",&n ,&k) && n != -1 && k != -1)
//	{
//		ans = m = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> g[i][j];
//			}
//		}
//		dfs(0);
//		cout << ans << endl;
//	}
//	system("pause");
//}