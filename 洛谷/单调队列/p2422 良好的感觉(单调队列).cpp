#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include<iostream>
#include<algorithm>
#include<deque>
#include<cstdio>
using namespace std;






using namespace std;


const int N = 1e5 + 200;


long long a[N];
long long lefts[N];
long long rights[N];
long long sums[N];
int n;
int m;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sums[i] = sums[i - 1] + a[i];

	}
	stack<long long> s1;
	for (int i = 1; i <= n; i++)
	{
		while (s1.size() && a[s1.top()] > a[i])
		{
			rights[s1.top()] = i - 1;
			int t = s1.top();
			s1.pop();

		}
		s1.push(i);
	}
	while (s1.size())
	{
		rights[s1.top()] = s1.top();
		int t = s1.top();
		s1.pop();
		while (s1.size())
		{
			rights[s1.top()] = t;
			s1.pop();
		}
	}

	stack<long long>s2;
	for (int i = n; i >= 1; i--)
	{
		while (s2.size() && a[s2.top()] > a[i])
		{
			lefts[s2.top()] = i + 1;
			int t = s2.top();
			s2.pop();
		}
		s2.push(i);
	}
	while (s2.size())
	{
		lefts[s2.top()] = s2.top();
		int t = s2.top();
		s2.pop();
		while (s2.size())
		{
			lefts[s2.top()] = t;
			s2.pop();
		}
	}


	for (int i = 1; i <= n; i++)
	{
		cout << sums[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << lefts[i] << " ";

	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << rights[i] << " ";
	cout << endl;


	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, (sums[rights[i]] - sums[lefts[i] - 1]) * a[i]);
	cout << ans << endl;
	system("pause");


}