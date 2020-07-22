#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

 // 奶牛[USACO04NOV]Apple Catching G 记忆化搜索
const int N = 1e3 + 100;
const int M = 35;
int w;
int f[N][M];
int n, m;
int a[N];


int dfs(int u, int last, int w1)// 当前的时间， 上次的位置 w用移动了多少次
{
	if (f[u][w] != 0)
		return f[u][w];
	if (u > n) return 0;
	if (w1 > w) return 0;

	int res = 0; // 其实就是 f[u][w1] 当前的时间 移动的凑数
	if (a[u] == last) // 此时的a[u] == last
	{
		res = dfs(u + 1, a[u], w1) + 1;  // 不用移动
	}
	else //此时的a[u] != last   上次位置与这次位置不同
	{
		// 上次与这次位置不同 不移动
		res = dfs(u + 1, last, w1);
		// 这次接苹果了 移动了
		if (w1 < w)
			res = max(res, dfs(u + 1, a[u], w1 + 1) + 1);
	}
	f[u][w1] = res;
	return res;

}
int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << dfs(1, 1, 0) << endl;



}

