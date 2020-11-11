#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

const int N = 2000;
int a[N], b[N];
int f[N];
int n, m;

int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}

void add(int a, int b)
{
	f[find(a)] = find(b);
}

bool check(int a, int b)
{
	if (find(a) == find(b))
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		char cp = ' ';
		int l = 0;
		int r = 0;
		// scanf("%c %d %d",&cp, &l, &r);
		cin >> cp >> l >> r;
		//cout << cp << " " << l << " " << r <<endl;
		if (cp == 'F')
		{
			add(l, r);
		}
		else
		{
			if (!b[l])  b[l] = find(r);
			else
				add(b[l], r);
			if (!b[r])  b[r] = find(l);
			else
				add(b[r], l);
		}

	}
	//cout << "!!!!!!!!!!!" << endl;
	int cnt = 0;


	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
			cnt++;
	}

	cout << cnt << endl;
}