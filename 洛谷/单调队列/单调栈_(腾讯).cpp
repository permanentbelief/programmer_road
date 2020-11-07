#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



/*
腾讯 面经 中的 一题

给一段序列,a[i] 为当前人的身高, 能向左看右看比他高的人 和 第一个比他矮的(递减序列看不到),
问每个人都能最大看到的人数是几个?

*/

int a[10] = { 9, 3, 1, 4, 5, 7, 2, 9, 4, 2 };

int l[10];
int r[10];

void f()
{
	stack<int> s;
	stack<int> sm;

	for (int i = 0; i < 10; i++)
	{
		while (s.size() && a[s.top()] < a[i])
		{
			int t = s.top();
			s.pop();
			l[t] = s.size();
			if (t > 0 && a[t] > a[t - 1]) l[t] += 1;
		}
		s.push(i);
	}
	while (s.size())
	{
		int t = s.top();
		s.pop();
		l[t] = s.size();
		if (t && a[t] > a[t - 1]) l[t] += 1;
	}

	cout << "数组 l[] : ";
	for (int i = 0; i < 10; i++)
	{
		cout << l[i] << " ";
	}
	cout << endl;

}
//int main()
//{
//
//	f();
//	reverse(a, a + 10);
//
//	memcpy(r, l, sizeof l);
//
//	f();
//
//	cout << "total :";
//	for (int i = 0; i < 10; i++)
//	{
//		cout << l[i] + r[i] << " ";
//	}
//	cout << endl;
//
//}
