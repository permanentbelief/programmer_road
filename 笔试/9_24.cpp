#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#include <bits/stdc++.h>

using namespace std;


int n;


vector<int> v;
vector<vector<int>> vv;
int t;

void dfs(vector<int> tmp, int target, int cur)
{
	if (target == 0)
	{
		vv.push_back(tmp);
		return;
	}
	if (target < 0)
	{
		return;
	}
	for (int i = cur; i < v.size(); i++)
	{
		if (target - v[i] >= 0)
		{
			target -= v[i];
			tmp.push_back(v[i]);
			dfs(tmp, target, i);
			target += v[i];
			tmp.pop_back();
		}
		else
		{
			return;
		}

	}
}
void init()
{
	int j = 0;
	for (int i = 2; i <= n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
		{
			v.push_back(i);
		}
	}
}


int main()
{
	cin >> n;
	cin >> t;
	init();
	dfs(vector<int>(), t, 0);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}