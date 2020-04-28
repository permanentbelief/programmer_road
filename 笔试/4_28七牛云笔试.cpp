#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
//const int maxn = 1005;
//bool vis[maxn];
//vector<int> G[maxn];
//
//int n = 0;
//int m = 0;
//int number = 0;
//
//void dfs(int tmp)
//{
//	vis[tmp] = 1;
//	number++;
//	for (int i = 0; i < G[tmp].size(); i++)
//	{
//		if (!vis[G[tmp][i]])
//		{
//			dfs(G[tmp][i]);
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> n >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//	dfs(1);
//	if (number == n)
//		cout << "YES" << endl;
//	else
//		cout << "No" << endl;
//	system("pause");
//}
/*



*/
// ÅÐ¶ÏÁ¬Í¨Í¼
//struct Node
//{
//	int x;
//	int y;
//};
//int main()
//{
//	int m = 0;
//	int n = 0;
//	while (cin >> m >> n)
//	{
//		vector<vector<bool>> v(m, vector<bool>(m));
//		vector<Node> vN;
//		for (int i = 0; i < m; i++)
//		{
//			v[i][i] = true;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			int a = 0;
//			int b = 0;
//			cin >> a >> b;
//			vN.push_back({a,b});
//			v[a - 1][b - 1] = true;
//			v[b - 1][a - 1] = true;
//		}
//		sort(vN.begin(), vN.end(), [](Node& n1, Node& n2)
//		{
//			if (n1.x == n2.x)
//				return n1.x < n2.x;
//			else
//				return n1.x < n2.x;
//		});
//
//		for (int i = 0; i < n; i++)
//		{
//			int tmpx = vN[i].x;
//			int tmpy = vN[i].y;
//			for (int j = i + 1; j < n; j++)
//			{
//				if (t == vN[j].x)
//				{
//					v[tmpx - 1][vN[j].y - 1] = true;
//					v[vN[j].y - 1][tmpx - 1] = true;
//				}
//			}
//		}
//		bool flag = false;
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (v[i][j] == false)
//				{
//					flag = true;
//					break;
//				}
//			}
//			if (flag)
//				break;
//		}
//		if (flag)
//			cout << "NO" << endl;
//		else
//			cout << "YES" << endl;
//	}
//}