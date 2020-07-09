#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
using namespace std;


const int N = 1005;
int f[N];

struct Edge
{
	int u, v, w;
	bool operator<(Edge& a) const
	{
		return w < a.w;
	}
}edge[N];
int n, m, k, sum, ans;

int find(int x)
{
	if (x == f[x])
	{
		return x;
	}
	return  f[x] = find(f[x]);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> edge[i].u;
		cin >> edge[i].v;
		cin >> edge[i].w;
	}
	sort(edge + 1, edge + 1 + m);

	for (int i = 1; i <= m; i++)
	{
		int fx = find(edge[i].u);
		int fy = find(edge[i].v);	
		if (fx != fy)
		{
			f[fx] = fy;
			sum++;
			ans += edge[i].w;
		}
		if (sum == n - k)
		{
			printf("%d", ans);
			return 0;
		}
	}
	printf("No Answer\n");
	return 0;
}