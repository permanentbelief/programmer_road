#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist); //!!!!!!!!!!!!!!所有距离初始化为正无穷

	int res = 0;  //最小生成树所有边的距离之和
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)  //找到当前集合外的所有点当中距离最小的点
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))// j点还在集合外，或者还没有找到，dist[t]>dist[j]
			{
				t = j; // t此时就是距离最小的点了。
			}
		}
		if (i && dist[t] == INF) //说明不是第一个点，且当前距离我集合最近的点 都是为正无穷，不连通的
			return INF;


		if (i) res += dist[t]; //只要不是第一条边，就把边加到集合中去

		//有自环，先累加，在更新。

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]);
		}


		st[t] = true;
	}
	return res;
}


int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int t = prim();
	if (t == INF)
		puts("impossible");
	else
		printf("%d\n", t);
	system("pause");
	return 0;
}