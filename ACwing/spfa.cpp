//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//using namespace std;
//
//
//
////const int N = 120;
////static int pos[5][2] = { { -1, -1 },{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
////
////int n;
////
////
////typedef pair<int, int> PII;
////char g[N][N];
////
////int dis[N][N];
////
////struct node
////{
////	int x, y, way,count;
////
////}nodes[N];
////
////
////bool vis[N][N];
////bool flag = false;
////node start;
////node send;
////int ans = INT_MAX;
////int max_ = INT_MAX;
////void bfs()
////{
////
////	memset(dis, 0, sizeof dis);
////	memset(vis, false, sizeof vis);
////	ans = INT_MAX;
////	queue<node> q;
////	q.push(start);
////	vis[start.x][start.y] = true;
////
////	while (q.size())
////	{
////		auto tmp = q.front();
////		q.pop();
////		if (tmp.count >= ans)
////			continue;
////		if (tmp.x == send.x && tmp.y == send.y)
////		{
////			ans = min(ans, tmp.count);
////		}
////
////		int x = tmp.x;
////		int y = tmp.y;
////		for (int i = 1; i <= 4; i++)
////		{
////			int nx = x + pos[i][0];
////			int ny = y + pos[i][1];
////			if (nx < 1 || nx > n || ny < 0 || ny > n
////				|| g[nx][ny] == 'x' || vis[nx][ny] == true)
////				continue;
////			vis[nx][ny] = true;
////			if (tmp.way != i)
////			{
////				q.push({ nx, ny, i, tmp.count + 1 });
////				
////			}
////			else
////			{
////				q.push({ nx, ny, i, tmp.count });
////			}
////		}
////	}
////	if (ans == INT_MAX)
////	{
////		flag = true;
////	}
////
////
////}
////int main()
////{
////	cin >> n;
////
////	
////	for (int i = 1; i <= n; i++)
////	{
////		for (int j = 1; j <= n; j++)
////		{
////			cin >> g[i][j];
////			if (g[i][j] == 'A')
////			{
////				start = { i, j };
////			}
////			if (g[i][j] == 'B')
////			{
////				send = { i, j };
////			}
////		}
////	}
////	for (int i = 1; i <= 4; i++)
////	{
////		start.way = i;
////		start.count = 0;
////		bfs();
////		if (flag)
////			break;
////		max_ = min(max_, ans);
////	}
////	if (flag == true)
////		cout << -1 << endl;
////	else
////	cout << max_ << endl;
////	system("pause");
////}
//
//const int N = 210;
//const int M = 2e3 + 20;
//
//
//
//typedef pair<int, int> PII;
//int h[N], ne[M], e[M];
//double  w[M];
//int n, m;
//int idx;
//bool st[N];
//double dis1[N];
//PII c[N];
//int A, B;
//
//void add(int a, int b, double c)
//{
//	e[idx] = b;
//	ne[idx] = h[a];
//	w[idx] = c;
//	h[a] = idx++;
//}
//
//double dis(pair<int, int>& p1, pair<int, int>& p2)
//{
//	int ans1 = p2.first - p1.first;
//	int ans2 = p2.second - p1.second;
//
//	return sqrt(pow(ans1, 2) + pow(ans2, 2));
//}
//void spfa()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		dis1[i] = 1000000000.0;
//	}
//	queue<int> q;
//	q.push(A);
//
//	st[A] = true;
//	dis1[A] = 0;
//	
//	while (q.size())
//	{
//		int t = q.front();
//		q.pop();
//
//		st[t] = false;
//		for (int i = h[t]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (dis1[j] > dis1[t] + w[i])
//			{
//				dis1[j] = dis1[t] + w[i];
//				if (st[j] == false)
//				{
//					q.push(j);
//					st[j] = true;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//
//	memset(h, -1, sizeof h);
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int a = 0;
//		int b = 0;
//		cin >> a >> b;
//		c[i] = { a, b };
//	}
//	cin >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		int a, b = 0;
//		cin >> a >> b;
//		add(a, b, dis(c[a], c[b]));
//		add(b, a, dis(c[a], c[b]));
//	}
//	cin >> A >> B;
//	spfa();
//
//	printf("%.2lf", dis1[B]);
//	system("pause");
//	
//
//}