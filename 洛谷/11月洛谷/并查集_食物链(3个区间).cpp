#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 食物链  并查集 3个 区间的 并查集


using namespace std;

const int N = 1e6;
int n, m, x, y, op;

int f[N];

int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}
void merge(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	f[aa] = bb;
}
bool check(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	cin >> n >> m;

	int cnt = 0;
	for (int i = 1; i <= 3 * n; i++)
	{
		f[i] = i;
	}
	while (m--)
	{
		cin >> op >> x >> y;
		if (x > n || y > n)
		{
			cnt++;
			continue;
		}

		if (op == 1) // 伙伴
		{
			if (find(x) == find(y + n) || find(y) == find(x + n))
			{
				cnt++;
			}
			else
			{
				f[find(x)] = find(y);
				f[find(x + n)] = find(y + n);
				f[find(x + 2 * n)] = find(y + 2 * n);
			}
		}
		else if (op == 2)
		{                           //A的2  如果和 B的 4是同类
			if (find(x) == find(y) || find(x) == find(y + n))
				//B的2    和A的4 同类
				cnt++;
			else
			{
				//B的2 吃 A的 4
				f[find(x + n)] = find(y);
				//C的2 吃 A的 4
				f[find(x + n + n)] = find(y + n);
				//A的2 池 B的4
				f[find(x)] = find(y + n + n);
			}
		}

	}
	cout << cnt << endl;
}