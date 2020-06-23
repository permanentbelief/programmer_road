#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 205;

int n, k;           // n 为图中点数，k 为图中边数
int total;          // 存图上所有边的权值总和
int g[N][N];        // prim 存图用的邻接矩阵
vector<int> dcc[N]; // 存所有的连通块
int dcc_cnt;        // 存连通块的数量
int dist[N];        // prim 存到每个点最近的距离用的 dist
bool st[N];         // 一个 st 两用，先用于求连通块，再在 prim 里面每个点是否在生成树中

void dfs(int u)     // dfs 求出所有的连通块
{
	st[u] = true;   // 先将 u 制成 true，表示已经加入已有连通块中了
	dcc[dcc_cnt].push_back(u); // 将点 u 放入该连通块
	for (int i = 1; i <= n; i++) // 从 1 到 n 枚举所有点
	if (g[u][i] < 0x3f3f3f3f && !st[i]) // 如果该点 i 能从 u 走过去，且没加入已有连通块中
		dfs(i); // 那么搜索点 i
}

int prim(int u)     // prim 求连通块 u 中的最小生成树
{
	int res = 0;    // res 记录生成树的大小
	memset(dist, 0x3f, sizeof dist); // 将 dist 制为正无穷
	memset(st, false, sizeof st);    // 由于要多次使用 st，所以每次要先将 st 制成 false
	for (int i = 0; i < dcc[u].size(); i++) // 扩展 dcc[u].size() 次
	{
		int t = -1;
		for (int j = 0; j < dcc[u].size(); j++) // 枚举一下当前连通块 u 中所有点
		{
			int ver = dcc[u][j];                  // 将该点取出
			if (!st[ver] && (t == -1 || dist[t] > dist[ver])) // 如果该点不在生成树中且到该点的距离大于到点 t 的距离
				t = ver;                          // 那么让将 t 改为该点
		}
		if (i) res += dist[t];                    // res 加上到已有生成树中距离最近的点到已有生成树的距离
		st[t] = true;                             // 将该点 t 加入已有生成树
		for (int j = 0; j < dcc[u].size(); j++) // 更新当前连通块中所有点
		{
			int ver = dcc[u][j];                  // 将该点取出
			dist[ver] = min(dist[ver], g[t][ver]);// 更新该点距离
		}
	}
	return res;     // 返回该生成树的大小
}

int main()
{
	scanf("%d%d", &n, &k);
	memset(g, 0x3f, sizeof g); // 将图中所有边的距离初始化为正无穷
	for (int i = 0; i < k; i++) // 读入图
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
		total += c;
	}
	for (int i = 1; i <= n; i++) // 枚举所有点，求连通块
	if (!st[i])                // 如果该点没有加入已有的任何联通块
	{
		dcc_cnt++;           // 那么建立一个新的连通块
		dfs(i);                // 将该点及该点能到的所有点加入新建的连通块
	}
	for (int i = 1; i <= dcc_cnt; i++) // 枚举所有连通块，求出所有连通块的最小生成树
		total -= prim(i);          // 总权值和减去该最小生成树的大小
	printf("%d\n", total);         // 输出剩下的权值和
	return 0;
}
