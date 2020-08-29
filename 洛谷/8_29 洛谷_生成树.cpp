#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

//using namespace std;
//using namespace std;
//
//const int N = 5e7 + 100;
//
//
//int n, m, cnt, f[N], sum;
//
//double ans = 0.0;
//
//struct Node
//{
//	int from, to;
//	double w;
//}e[N];
//
//
//struct node
//{
//	int x, y;
//}E[N];
//
//void add(int x, int y, double z)
//{
//	e[++cnt].from = x;
//	e[cnt].to = y;
//	e[cnt].w = z;
//}
//
//double juli(int x, int y)
//{
//
//	return (double)(sqrt((double)(E[x].x - E[y].x) * (E[x].x - E[y].x) + (double)
//		(E[x].y - E[y].y) * (E[x].y - E[y].y)));
//}
//
//bool cmp(Node& x, Node& y)
//{
//	if (x.w == y.w) return x.from < y.from;
//	return x.w < y.w;
//}
//
//int find(int x)
//{
//	if (x == f[x])
//		return x;
//	return f[x] = find(f[x]);
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> E[i].x >> E[i].y;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			double ju = juli(i, j);
//			add(i, j, ju);
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = i;
//	}
//	while (m--)
//	{
//		int i, j;
//		cin >> i >> j;
//		add(i, j, 0.0);
//	}
//	sort(e + 1, e + cnt + 1, cmp);
//	int sums = 0;
//	for (int i = 1; i <= cnt; i++)
//	{
//		int from = e[i].from;
//		int to = e[i].to;
//		int ffrom = find(from);
//		int fto = find(to);
//		if (ffrom != fto)
//		{
//			f[ffrom] = fto;
//			sums++;
//			ans += e[i].w;
//		}
//		if (sums == n - 1)
//			break;
//
//	}
//	cout << 11 << endl;
//	cout << ans << endl;
//	system("pause");
//}

//
//
//const int N = 2000 + 100;
//
////#define double int;
//
//int n,m,cnt,f[N],sum;
//
//int ans;
//
//
//struct node
//{
//int x,y;
//}E[N];
//
//struct Node
//{
//int from, to, w;
//}e[N*N];
//
//void add(int x, int y, int z)
//{
//e[++cnt].from = x;
//e[cnt].to = y;
//e[cnt].w = z;
//}
//
//int juli(int x, int y)
//{
//
//return (int)(((int)(E[x].x - E[y].x) * (E[x].x - E[y].x) + (int)
//(E[x].y - E[y].y) * (E[x].y - E[y].y)));
//}
//
//bool cmp(Node& x, Node& y)
//{
//if(x.w == y.w) return x.from < y.from;
//return x.w < y.w;
//}
//
//int find(int x)
//{
//if(x == f[x])
//return x;
//return f[x] = find(f[x]);
//}
//int main()
//{
//cin >> n >> m;
//for(int i = 1; i <= n; i++)
//{
//cin >> E[i].x >> E[i].y;
//}
//for(int i = 1; i <= n; i++)
//{
//for(int j = i + 1; j <= n; j++)
//{
//double ju = juli(i,j);
//if(ju >= m)
//add(i,j,ju);
//else
//add(i, j, 0x3f3f3f3f);
//}
//}
//for(int i = 1; i <= n; i++)
//{
//f[i] = i;
//}
//
//sort(e + 1, e + cnt + 1, cmp);
//
///*
//for(int i = 1; i <= n; i++)
//{
//cout << e[i].w  << " ";
//}
//cout << endl;
//
//*/
//
//int sums = 0;
//for (int i = 1; i <= cnt; i++)
//{
//	if (e[i].w == 0x3f3f3f3f)
//		continue;
//	int from = e[i].from;
//	int to = e[i].to;
//	int ffrom = find(from);
//	int fto = find(to);
//	if (ffrom != fto)
//	{
//		f[ffrom] = fto;
//		sums++;
//		ans += e[i].w;
//		//cout << ans <<endl;
//
//
//	}
//	//cout << sums << endl;
//	// cout << endl;
//	if (sums == n - 1)
//		break;
//
//}
//if (sums < n - 1)
//	printf("-1\n");
//else
//{
//	printf("%d\n", ans);
//}
//
//}
//
//




//#include <bits/stdc++.h>
//using namespace std;
//
//
//const int MAXN = 100100;
//
//int sums[MAXN];
//int n;
//bool check(double x)
//{
//	double minv = sums[1] - x * 1;
//	for (int i = 2; i < n; i++)
//	{
//		if (sums[n] - x * n - (sums[i] - x * i) + minv <= 0)
//			return true;
//		minv = min(minv, sums[i] - x * i);
//	}
//	return false;
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int a, i = 1; i <= n; i++)
//	{
//		scanf("%d", &a);
//		sums[i] = sums[i - 1] + a;
//	}
//
//	double l = 0;
//	double r = 10000;
//	while (r - l > 1e-5)
//	{
//		double mid = (r + l) / 2.0;
//		if (check(mid))
//			r = mid;
//		else
//			l = mid;
//	}
//	printf("%.3lf", r);
//	return 0;
//}



// P2573 滑雪 为什么要先bfs重新建图 之后 在调用krusal算法
//
//using namespace std;
//const int N = 2500;
//
//int n, m;
//int a[N];
//
//
//struct node
//{
//	int x, y;
//
//}e[N];
//
//struct Node
//{
//	int x, y;
//	double w;
//	bool operator<(const Node& a)
//	{
//		return w < a.w;
//	}
//}E[N];
//
//int f[N];
//int find(int x)
//{
//	return x == f[x] ? x : f[x] = find(f[x]);
//}
//int cnt;
//double sums;
//
//void add(int i, int j, double w)
//{
//	E[++cnt].x = i;
//	E[cnt].y = j;
//	E[cnt].w = w;
//}
//
//double juli(int i, int j)
//{
//	return (double)sqrt((double)(e[i].x - e[j].x)*(e[i].x - e[j].x) + (double)
//		(e[i].y - e[j].y)*(e[i].y - e[j].y));
//
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		f[i] = 1;
//	}
//
//	int k = 0;
//	cin >> k;
//
//	for (int i = 1; i <= k; i++)
//	{
//		
//		cin >> e[i].x >> e[i].y;
//	}
//	for (int i = 1; i <= k; i++)
//	{
//		for (int j = i + 1; j <= k; j++){
//			double e = juli(i, j);
//			add(i, j, e);
//		}
//	}
//	for (int i = 1; i <= cnt; i++)
//	{
//		cout << E[i].w << " ";
//	}
//	cout << endl;
//	cout << k << endl;
//	double temp = 0.0;
//	sort(E + 1, E + 1 + cnt);
//	// cout << "cnt : " << cnt << endl;
//	for (int i = 1; i <= cnt; i++)
//	{
//		int u = find(E[i].x);
//		int v = find(E[i].y);
//		if (u == v)
//			continue;
//		f[u] = v;
//		cnt++;
//		cout << "cnt : " << cnt << endl;
//		if (cnt == k - 1)
//		{
//			temp = E[i].w;
//			break;
//		}
//
//	}
//	cout << "temp:  " << temp << endl;
//	cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (1ll * a[i] >= temp)
//			cnt++;
//	}
//	cout << cnt << endl;
//}

#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 210
#define maxm 50010
using namespace std;
int n, m, dis[maxn][maxn], t[maxm], q, k;
int main()
{
	scanf("%d%d", &n, &m);
	memset(dis, 0x3f, sizeof(dis));
	memset(t, 0x3f, sizeof(t));
	for (int i = 0; i<n; i++)
		scanf("%d", &t[i]),
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dis[a][b] = dis[b][a] = c;
	}
	scanf("%d", &q);
	for (int o = 1; o <= q; o++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		while (t[k] <= c)
		{
			for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			k++;
		}
		if (dis[a][b] == 0x3f3f3f3f || t[a]>c || t[b]>c) printf("-1\n");
		else printf("%d\n", dis[a][b]);
	}
	return 0;
}