#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>

#include<sstream>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> P;///first表示到顶点的距离,second表示顶点的编号 
struct edge{
	int to, cost;
};
int vis[maxn], dis[maxn];
vector<edge>g[maxn];
int m, n;
void dijkstra()
{
	int s = 1;///起点为1
	fill(dis, dis + n + 10, INF); fill(vis, vis + n + 10, 0);
	dis[s] = 0;
	priority_queue< P, vector<P>, greater<P> > que;
	que.push({ 0, s });
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = 0; i<g[v].size(); i++)
		{
			edge e = g[v][i];//A->B,edge e={B,cost(A->B)} 
			if (dis[e.to]>dis[v] + e.cost)
			{
				dis[e.to] = dis[v] + e.cost;
				que.push({ dis[e.to], e.to });
			}
		}
	}
	if (dis[n] == 0x3f3f3f3f) cout << "NO" << endl;
	else cout << dis[n] - 1 << endl;
}

int main(void)
{
	cin >> m >> n;///如果要去的车站>n,肯定是到不了的 
	string line;
	getline(cin, line); int lines[maxn];
	while (m--)
	{
		getline(cin, line);
		stringstream ssin(line); ///创建一个流
		int cnt = 0, p;
		while (ssin >> p) lines[cnt++] = p;
		for (int i = 0; i<cnt; i++)
		for (int j = i + 1; j<cnt; j++)
			g[lines[i]].push_back({ lines[j], 1 });
	}
	dijkstra();
	system("pause");
	return 0;
}