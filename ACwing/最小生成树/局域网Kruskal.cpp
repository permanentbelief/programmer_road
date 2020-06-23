#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include<bits/stdc++.h>
#define N 110
using namespace std;
struct node{
	int from, to, dis;
}e[N * 2];
int n, k, fa[N], ans, cnt, tot;
int find(int x)//并查集基本操作
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int x, int y)//并查集基本操作
{
	fa[find(y)] = find(x);
}
bool rule(const node &x, const node &y)//按边权从小到大排序
{
	return x.dis<y.dis;
}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)//并查集初始化
		fa[i] = i;
	for (int i = 1; i <= k; i++){
		scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].dis);
		if (!e[i].dis)//注意:这是这道题的坑点,边权为0的边不能加入生成树
			i--, k--;
		ans += e[i].dis;
	}
	sort(e + 1, e + 1 + k, rule);
	for (int i = 1; i <= k; i++){//克鲁斯卡尔算法求最小生成树
		if (cnt == n - 1)
			break;
		int u = e[i].from, v = e[i].to;
		if (find(u) != find(v)){
			merge(u, v);
			tot += e[i].dis;
			cnt++;
		}
	}
	printf("%d\n", ans - tot);//输出最终答案
	return 0;
}

