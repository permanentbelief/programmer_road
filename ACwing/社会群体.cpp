#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <set>
//using namespace std;
//
//
//const int N = 1e3 + 3;
//
//int f[N];
//int ch[N];
//
//int find(int x)
//{
//	if (f[x] != x)
//		f[x] = find(f[x]);
//	return f[x];
//}
//
//void Union(int x, int y)
//{
//	int fx = find(x);
//	int fy = find(y);
//	if (fx != fy)
//	{
//		f[fy] = fx;
//		ch[fx] += ch[fy];
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int h = 0;
//	scanf("%d", &n);
//	vector<set<int>> vec(N);
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = i;
//		ch[i] = 1;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d:", &k);
//		while (k--)
//		{
//			scanf("%d", &h);
//			vec[i].insert(h);
//			for (int j = 1; j < i; j++)
//			{
//				if (vec[j].count(h))
//				{
//					Union(i, j);
//					break;
//				}
//			}
//		}
//	}
//	int cnt = 0;
//	int ans[N];
//	for (int i = 1; i <= n; i++)
//	{
//		if (find(i) == i)
//		{
//			ans[cnt] = ch[i];
//			cnt++;
//		}
//	}
//	sort(ans, ans + cnt);
//	printf("%d\n", cnt);
//	for (int i = cnt - 1; i >= 0; i--)
//	{
//		printf("%d", ans[i]);
//		if (i > 0)
//			printf(" ");
//	}
//	system("pause");
//	return 0;
//}