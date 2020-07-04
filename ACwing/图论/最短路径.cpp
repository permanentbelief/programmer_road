#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <functional>
using namespace std;

typedef pair <int, int> PII;

const int N = 110;
const int M = 1100;
int n, m;

int h[N], ne[M], e[M], idx;
bool st[N];
int dis[N];
int w[M];
void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void heapdijkstra()
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	memset(dis, 0x3f, sizeof dis);
	memset(st, false, sizeof st);
	dis[0] = 0;
	heap.push({ 0, 0 });
	while (heap.size())
	{
		auto tmp = heap.top();
		heap.pop();
		int ver = tmp.second;
		int distance = tmp.first;
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dis[j] > distance + w[i])
			{
				dis[j] = distance + w[i];
				heap.push({ dis[j], j });
			}
		}
	}
}
const int MOD = 100000;
int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	int k = 0;
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		add(a, b, pow(2, k));
		add(b, a, pow(2, k));
		k++;
	}
	heapdijkstra();
	for (int i = 1; i < n; i++)
	{
		cout << dis[i] % MOD << endl;
	}
	system("pause");
}