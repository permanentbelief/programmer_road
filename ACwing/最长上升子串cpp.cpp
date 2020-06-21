#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 100010;
//
//int n;
//int a[N], f[N], g[N];
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//
//	int c[10];
//	int d[10];
//	for (int i = 1; i <= n; i++)
//	{
//		int j = i;
//		while (j + 1 <= n && a[j] < a[j + 1])
//		{
//			j++;
//		}
//		c[i] = j - i + 1; 
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		int j = i;
//		while (j - 1 >= 1 && a[j - 1] < a[j])
//		{
//			j--;
//		}
//		d[i] = i - j + 1; 
//	}
//	for (int i = 1; i <= n; i++) // c[] 以个元素为开始的上升子串长度
//	{
//		cout << c[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++) //d[]以个元素为结尾的上升子串长度
//	{
//		cout << d[i] << " ";
//	}
//	cout << endl;
//
//	int res = 0;
//	//枚举删除哪个数
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i - 1] >= a[i + 1])
//			res = max(res, max(d[i - 1], c[i + 1]));
//		else
//			res = max(res, d[i - 1] + g[i + 1]);
//	}
//	//// 预处理f[i]：以i结尾的单调上升子串的最大长度
//	//for (int i = 1; i <= n; i++)
//	//if (a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
//	//else f[i] = 1;
//
//	//// 预处理g[i]：以i开头的单调上升子串的最大长度
//	//for (int i = n; i; i--)
//	//if (a[i] < a[i + 1]) g[i] = g[i + 1] + 1;
//	//else g[i] = 1;
//
//	//int res = 0;
//	//// 枚举删除哪个数
//	//for (int i = 1; i <= n; i++)
//	//if (a[i - 1] >= a[i + 1]) res = max(res, max(f[i - 1], g[i + 1]));
//	//else res = max(res, f[i - 1] + g[i + 1]);
//
//	//printf("%d\n", res);
//	//system("pause");
//	//return 0;
//	cout << res << endl;
//	system("pause");
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//void dfs(vector<int> arr, int n, int cur)
//{
//	if (cur == n)
//	{
//		for (auto e : arr)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = cur; i <= n; i++)
//	{
//		arr.push_back(i);
//		dfs(arr, n, i + 1);
//		arr.pop_back();
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> arr;
//	dfs(arr, n, 0);
//	system("pause");
//	return 0;
//}