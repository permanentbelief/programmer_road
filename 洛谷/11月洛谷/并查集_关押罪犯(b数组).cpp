#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct dat
{
	int x, y, z;
};

dat f[100005];
int n, m, a[20005], b[20005], i;

bool cmp(dat a, dat b)
{
	return a.z > b.z;
}
int find(int x)
{
	if (a[x] == x) return x;
	a[x] = find(a[x]);
	return a[x];
}

void add(int x, int y)
{
	x = find(a[x]);
	y = find(a[y]);
	a[x] = y;
}
bool check(int x, int y)
{
	if (find(x) == find(y))
		return true;
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) a[i] = i;
	for (i = 1; i <= m; i++)
		scanf("%d%d%d", &f[i].x, &f[i].y, &f[i].z);
	sort(f + 1, f + m + 1, cmp);
	for (i = 1; i <= m + 1; i++)
	{
		if (check(f[i].x, f[i].y))
		{
			printf("%d\n", f[i].z);
			break;
		}
		else
		{  // b �����Ǵ� ���˵ģ� ��������� f[i].x �ĵ��ˣ� f[i].x�ĵ��˾��� f[i].y;
			// ���� �ϲ� b[ f[i].x ] �� f[i].y;
			if (!b[f[i].x]) b[f[i].x] = f[i].y;
			else
				add(b[f[i].x], f[i].y);

			if (!b[f[i].y]) b[f[i].y] = f[i].x;
			else
				add(b[f[i].y], f[i].x);
		}
	}
	return 0;
}