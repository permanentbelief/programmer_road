#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>


typedef unsigned long long ll;

using namespace std;
//
//const int N = 1e6 + 100;
//
//int n, m;
//int a[N];
//
//bool check(ll mid)
//{
//	ll sum = 0;
//
//}
//
//int main()
//{
//	cin >> n >> m;
//	ll l = 1;
//	ll r = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	r = n;
//
//	while (l < r)
//	{
//		ll mid = (l + r) / 2;
//		if (check(mid))
//		{
//			r = mid;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//
//}
//


//
//const int N = 2e5 + 300;
//ll a[N];
//ll b[N];
//
//ll n, S, L;
//
//ll l = 0;
//ll r = 1e18;
//ll ans = 0;
//bool check(ll mid)
//{
//	ll cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		ll sum = b[i] + a[i] * mid;
//		if (sum >= L)
//		{
//			cnt+= sum;
//		}
//	}
//
//	return cnt >= S;
//}
//
//
//
//void sort1()
//{
//	while (l <= r)
//	{
//		ll mid = (l + r) / 2;
//		if (check(mid))
//		{
//			ans = mid;
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	cout << ans << endl;
//}
//
//void sort2()
//{
//	// 写法二 两个数据没过去 1 16
//	while (l <= r)
//	{
//		ll mid = (l + r) / 2;
//		if (check(mid))
//		{
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	cout << l ;
//	
//}
//
//void sort3()
//{
//	//写法一 两个数据没过去。	  90%
//
//	while (l < r)
//	{
//		ll mid = (l + r) / 2;
//		if (check(mid))
//		{
//			r = mid;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//
//	cout << r << endl;
//	
//}
//int main()
//{
//	cin >> n >> S >> L;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> b[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//
//	
//
//	if (check(0))
//	{
//		cout << 0;
//		return 0;
//	}
//	srand(time(nullptr));
//	int t = rand() % 3 + 1;
//	if (t == 1)
//	{
//		sort1();
//	}
//	else if (t == 2)
//	{
//		sort2();
//	}
//	else
//	{
//		sort3();
//	}
//
//
//	return 0;
//	system("pause");
//}