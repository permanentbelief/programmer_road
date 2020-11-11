#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


const int N = 1e6 + 100;
int t, n, m, x, y, e;
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
	cin >> t;
	while (t--)
	{
		memset(f, 0, sizeof f);
		bool ff = true;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			f[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> x >> y >> e;
			if (e == 1)
			{
				merge(x, y);
			}
			else
			{
				if (check(x, y))
				{
					ff = false;
					continue;
				}
			}
		}
		if (!ff)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}