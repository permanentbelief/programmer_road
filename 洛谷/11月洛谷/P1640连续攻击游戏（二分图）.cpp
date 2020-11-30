#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 10;
//
//struct edge
//{
//	int v, nx;
//}s[ N];
//
//int head[N], chk[N], match[N];
//
//int n, id, x, now;
//
//
//void add(int u, int v)
//{
//	id++;
//	s[id].v = v;
//	s[id].nx = head[u];
//	head[u] = id;
//}
//
//void init()
//{
//
//	memset(head, -1, sizeof(head));
//
//	memset(match, -1, sizeof match);
//	int a, b, n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a >> b;
//		add(a, i);
//		add(b, i);
//	}
//}
//
//
//bool dfs(int u)
//{
//	int v;
//	for (int i = head[u]; i != -1; i = s[i].nx)
//	{
//		v = s[i].v;
//		if (chk[v] != now)
//		{
//			chk[v] = now;
//			if (match[v] == -1 || dfs(match[v]))
//			{
//				match[v] = u;
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
//int main()
//{
//	init();
//	int ans = 0;
//	for (int i = 1; i <= 10000; i++)
//	{
//		now++;
//		if (dfs(i)) ans++;
//		else
//			break;
//	}
//	printf("%d\n", ans);
//
//	system("pause");
//	return 0;
//}
