#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

const int N = 25;

bool books[N];
int index = 0;
void dfs(vector<vector<int>>&s, vector<int>& v, vector<int>& tmp, int m, int cur)
{
	if (v.size() == m)
	{
		s.push_back(v);
		return;
	}
	for (int i = cur; i < tmp.size(); i++)
	{
		if (i > 0 && tmp[i] == tmp[i - 1] && books[i - 1] == false)
			continue;
		if (books[i] == false)
		{
			books[i] = true;
			v.push_back(tmp[i]);
			dfs(s, v, tmp, m, i + 1);
			v.pop_back();
			books[i] = false;
		}
	}
}

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> tmp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp[i];
	}
	sort(tmp.begin(), tmp.end());
	vector<vector<int>> s;
	vector<int> v;
	dfs(s, v, tmp, m, 0);
	for (auto e : s)
	{
		for (auto ee : e)
		{
			cout << ee << " ";
		}
		cout << endl;
	}
	system("pause");
}

