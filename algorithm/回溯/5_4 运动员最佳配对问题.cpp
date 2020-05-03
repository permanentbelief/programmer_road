#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 20;



void dfs(vector<vector<int>>& v1, vector<vector<int>>& v2,vector<int> v, int cur, int n, int& max_)
{
	if (cur == n)
	{
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += v1[i][v[i]]*v2[v[i]][i];
			cout << i << " " << v[i] << "," << v[i] << " " << i << endl;
		}
		cout << endl;
		if (temp > max_)
		{
			max_ = temp;
		}
	}
	for (int i = cur; i < n; i++)
	{
		swap(v[i],v[cur]);
		dfs(v1,v2,v,i + 1,n,max_);
		swap(v[i],v[cur]);

	}
}
int main()
{
	int n = 0;
	cin >> n;

	int max_ = 0;
	vector<int> v(n);
	vector<vector<int>> v1(n, vector<int>(n, 0));
	vector<vector<int>> v2(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v1[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v2[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		v[i] = i;
	}
	dfs(v1,v2,v,0,n, max_);
	cout << max_ << endl;

	system("pause");
}

/*
3    
10 2 3
2 3 4
3 4 5
2 2 2
3 5 3
4 5 1

*/