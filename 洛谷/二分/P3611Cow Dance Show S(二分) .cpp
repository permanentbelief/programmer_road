#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>

using namespace std;


const int N = 1e3 + 20;

struct node
{
	int start, end;
	bool operator < (node& a) const
	{
		return end < a.end;
	}
}e[N];


int n, m;

bool check(int mid)
{
	int sum = 0;
	int st = mid;
	int tnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (st + e[i].start <= e[i].end)
		{
			st = e[i].end - e[i].start;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	int r = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> e[i].start >> e[i].end;
		r = max(e[i].start, r);
		r = max(e[i].end, r);
	}
	sort(e + 1, e + 1 + n);
	int l = 0;
	

	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l << endl;
	system("pause");
}