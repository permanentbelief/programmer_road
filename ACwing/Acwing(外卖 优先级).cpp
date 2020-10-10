#define _CRT_SECURE_NO_WARNINGS 1 

//外卖 优先级
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;
const int N = 1e8;

// map<int,int> m;
int n, ts, td;
int m, t;
pair<int, int> a[N];
int last[N];
vector<int> v;

int score[N];
bool st[N];
int cnt;

int main()
{
	cin >> n >> m >> t;
	int i = 1;
	while (i <= m)
	{
		cin >> ts >> td;
		a[i] = { ts, td };
		i++;
	}
	sort(a + 1, a + m + 1);
	// int last[N];




	for (int i = 1; i <= m;)
	{
		int j = i;
		while (j <= m && a[i].first == a[j].first && a[i].second == a[j].second)
			j++;
		int id = a[i].second;
		int t = a[i].first;
		cnt = j - i;
		i = j;

		score[id] -= (t - last[id] - 1);
		if (score[id] < 0) score[id] = 0;
		if (score[id] <= 3) st[id] = false;

		score[id] += cnt * 2;
		if (score[id] > 5) st[id] = true;

	}
	for (int i = 1; i <= n; i++)
	{
		if (last[i] < t)
		{
			score[i] -= t - last[i];
			if (score[i] <= 3) st[i] = false;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += st[i];
	}
	cout << res << endl;
}
//
//const int N = 25;
//int a[N];
//int st[N];
//int m, n;
//
//int cnt;
//
//void dfs(int u, int t, int sums) //枚举到u
//{
//
//	if (u > m + 1 || sums > m)
//		return;
//	if (sums == m)
//	{
//		for (int i = 1; i <= n + 1; i++)
//		{
//			cout << st[i] << " ";
//		}
//		cout << endl;
//		cnt++;
//		return;
//	}
//	if (t >= n)
//		return;
//	
//	// 继续取a[u]这个数
//	
//	st[u]++;
//	dfs(u, t + 1, sums + a[u]);
//
//	// dfs(u + 1, t + 1, sums + a[u]);
//
//	st[u]--;
//	// 不取a[u]这个数
//	dfs(u + 1, t, sums);
//}
//int main()
//{
//
//		cin >> m >> n;
//		for (int i = 1; i <= m + 1; i++)
//		{
//			a[i] = i - 1;
//		}
//		dfs(1, 0, 0);
//		if (m == 1)
//			cout << 1 << endl;
//		else
//			cout << cnt << endl;
//	
//	system("pause");
//}