#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int a[1000];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector<int> prev(n + 1, -1);
	vector<int> next(n + 1, -1);
	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() && a[s.top()] >= a[i])
		{
			s.pop();
		}
		if (!s.empty()) prev[i] = s.top() - 1;
		s.push(i);
	}

	while (!s.empty())
	{
		s.pop();
	}
	for (int i = n; i >= 1; i--)
	{
		while (!s.empty() && a[s.top()] >= a[i])
		{
			s.pop();
		}
		if (!s.empty()) next[i] = s.top() - 1;
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
	
		cout << prev[i] << " " << next[i] << endl;
	}
	system("pause");
}