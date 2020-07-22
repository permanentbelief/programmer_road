#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 4e5 + 100;
const int M = 4e5 + 100;

int n, k;
int a[N];
unordered_map<int, int> m;
bool vis[N];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long sum = 0;
	queue<int> dq;
	for (int i = 1; i <= n; i++)
	{
		m[a[i]]++;
		dq.push(i);
		if (vis[a[i]] == false && m[a[i]] >= k)
		{
			cout << a[i] << endl;
			sum += (n - i + 1);
		}
	}
	cout << sum << endl;
}

#include <unordered_map>
int main()
{
	int n, m;
	int num = 0;
	int pt = -1;
	int ans = 0;
	unordered_map<int, vector<int>> hash;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		hash[num].push_back(i);

		if (hash[num].size() >= m)
		{
			int pre_m = hash[num][hash[num].size() - m];
			pt = max(pt, pre_m);
		}
		ans += pt + 1;
	}
	cout << ans << endl;
	return 0;
}