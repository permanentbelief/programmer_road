//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int a[1005];
//int HalfSet(int n)
//{
//	if (a[n] > 0)
//		return a[n];
//	else
//	{
//		a[n] = 1;
//		for (int i = 1; i <= n / 2; i++)
//		{
//			a[n] += HalfSet(i);
//			if (i>10 && (i / 10 <= ((i % 10) / 2)))
//			{
//				a[n] -= a[i / 10];
//			}
//		}
//		return a[n];
//	}
//}
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		memset(a, 0, sizeof(a));
//		printf("%d\n", HalfSet(n));
//	}
//	return 0;
//}
