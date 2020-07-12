//#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <iostream>
#include <cstring>
#include <functional>
using namespace std;
const int N = 3e4 + 20;
#include <set>

typedef long long ll;

//unsigned long long a[N];
int n;
int l[N];
int r[N];
long long c[N];
long long va[N];


struct node
{
	long long val;
	int order;
}a[N];

bool cmp(node& a, node& b)
{
	return a.val < b.val;
}
int lowbit(ll x)
{
	return x&(-x);
}

void add(ll x, ll y)
{
	while (x <= n)
	{
		c[x] += y;
		x += lowbit(x);
	}
}
long long get_sum(ll x)
{

	ll ans = 0;
	while (x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].val;
		a[i].order = i;
	}

	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1; i <= n; i++)
	{
		if (a[i].val != a[i - 1].val)
			va[a[i].order] = i; //��ɢ��
		else
			va[a[i].order] = va[a[i - 1].order];
	}
	memset(c, 0, sizeof c);

	for (int i = 1; i <= n; i++) // ������ж��ٸ�������С
	{
		l[i] = get_sum(va[i] - 1);
		add(va[i], 1);

	}
	memset(c, 0, sizeof c);
	for (int i = n; i >= 1; i--) //���ұ��ж�����������
	{
		r[i] = get_sum(n) - get_sum(va[i]);
		add(va[i], 1);
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (l[i] * r[i]);
	}
	cout << ans << endl;
	system("pause");
}

/*
10
2 5 3 4 3 2 1 3 4 1

10
2	5	3	4	3	2	1	3	4	1

3  10   5   8   5   3   1   6    8  1

6

*/


//
//typedef long long ll;
//
//ll c[N], r[N], l[N];
//int a[N];
//int n;
//
//int lowbit(int x)
//{
//	return x&-x;
//}
//
//int ask(int x)
//{
//	int ans = 0;
//	while (x)
//	{
//		ans += c[x];
//		x -= lowbit(x);
//	}
//	return ans;
//}
//void add(int x, int y)
//{
//	while (x <= n)
//	{
//		c[x] += y;
//		x += lowbit(x);
//	}
//}
//
//int main()
//{
//	ll sum1 = 0;
//	ll sum2 = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = n; i >= 1; i--) //ͳ���Ҳ�a[i]��a[i]�����Ŀ�ж���
//	{
//		r[i] = ask(n) - ask(a[i]); // ��nС���� - ��a[i]С����
//		add(a[i], 1);
//	}
//
//	memset(c, 0, sizeof c);
//	for (int i = 1; i <= n; i++) // ͳ��a[i]������a[i]�����Ŀ�ж���
//	{
//		l[i] = ask(n) - ask(a[i]);
//		add(a[i], 1);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		sum1 += l[i] * r[i];
//	}
//
//	memset(c, 0, sizeof c);
//	memset(l, 0, sizeof l);
//	memset(r, 0, sizeof r);
//
//	for (int i = n; i >= 1; i--)//ͳ��a[i]�Ҳ� ��a[i]С�����ж��ٸ�
//	{
//		r[i] = ask(a[i] - 1);
//		add(a[i], 1);
//	}
//	memset(c, 0, sizeof c);
//	for (int i = 1; i <= n; i++) // ͳ��a[i]��� ��a[i]С�����ж��ٸ�
//	{
//		l[i] = ask(a[i]);
//		add(a[i], 1);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		sum2 += l[i] * r[i];
//	}
//	cout << sum1 << " ";
//	cout << sum2 << endl;
//	system("pause");
//}
//

