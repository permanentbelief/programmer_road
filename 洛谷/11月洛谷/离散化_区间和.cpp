#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


typedef pair<int, int> PII;
const int N = 300010;
int a[N], s[N]; //s前缀和
int n, m;

vector<int> alls; //离散化后的值
vector<PII> add, query; //add 插入操作

int find(int x)
{
	int l = 0;
	int r = alls.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}
vector<int>::iterator unique(vector<int> &a)
{
	int j = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i] != a[i + 1])
			a[j++] = a[i];
	}
	return a.begin() + j;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c }); //x 位置上 加上c

		alls.push_back(x); // x加入 待 加入 离散化的数组中
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({ l, r });

		alls.push_back(l);
		alls.push_back(r); // 所有的可用下标 全部加入 待离散化的数组中
	}


	// 去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());


	//预处理 
	for (auto item : add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}

	// 预处理
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	//处理询问
	for (auto item : query)
	{
		int l = find(item.first);
		int r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
