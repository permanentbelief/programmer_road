#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
using namespace std;

const int N = 5e7 + 100;


int n, m, cnt, f[N], sum;

double ans = 0.0;

struct Node
{
	int from, to;
	double w;
}e[N];


struct node
{
	int x, y;
}E[N];

void add(int x, int y, double z)
{
	e[++cnt].from = x;
	e[cnt].to = y;
	e[cnt].w = z;
}

double juli(int x, int y)
{

	return (double)(sqrt((double)(E[x].x - E[y].x) * (E[x].x - E[y].x) + (double)
		(E[x].y - E[y].y) * (E[x].y - E[y].y)));
}

bool cmp(Node& x, Node& y)
{
	if (x.w == y.w) return x.from < y.from;
	return x.w < y.w;
}

int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> E[i].x >> E[i].y;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double ju = juli(i, j);
			add(i, j, ju);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		add(i, j, 0.0);
	}
	sort(e + 1, e + cnt + 1, cmp);
	int sums = 0;
	for (int i = 1; i <= cnt; i++)
	{
		int from = e[i].from;
		int to = e[i].to;
		int ffrom = find(from);
		int fto = find(to);
		if (ffrom != fto)
		{
			f[ffrom] = fto;
			sums++;
			ans += e[i].w;
		}
		if (sums == n - 1)
			break;

	}
	cout << 11 << endl;
	cout << ans << endl;
	system("pause");
}