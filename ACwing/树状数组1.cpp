#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#include <functional>
//using namespace std;
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
//const int N = 1e5 + 20;
//const int M = 1e5 + 20;
//
//int n, m;
//int a[N];
//int c[N];
//
//int lowbit(int  x)
//{
//	return x&(-x);
//}
//void add(int x, int y)
//{
//	while (x <= n)
//	{
//		c[x] += y;
//		x += lowbit(x);
//	}
//}
//int ask(int x)
//{
//	int ans = a[x];
//	while (x)
//	{
//		ans += c[x];
//		x -= lowbit(x);
//	}
//
//	return ans;
//}
//
//int main()
//{
//
//
//
//	scanf("%d%d\n", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//		
//	}
//
//	getchar();
//	while (m--)
//	{
//		char temp = getchar();
//
//		if (temp == 'Q')
//		{
//			int k = 0;
//			scanf("%d\n", &k);
//			printf("%d\n", ask(k));
//		}
//		else
//		{
//			int k1, k2, k3;
//			scanf("%d%d%d\n", &k1, &k2, &k3);
//			add(k1, k3);
//			add(k2 + 1, -k3);
//
//		}
//	}
//
//}
//




