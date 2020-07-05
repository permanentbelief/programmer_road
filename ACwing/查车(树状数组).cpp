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
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//const int N = 5e5 + 20;
//
//const int K = 1e5 + 10;
//
//int n, m;
//
//int c[N];
//
//int lowbit(int x)
//{
//	return x&(-x);
//}
//void add(int a, int b)
//{
//
//	while (a <= n)
//	{
//		c[a] += b;
//		a += lowbit(a);
//	}
//
//}
//int qu(int x)
//{
//	int ans = 0;
//	while (x > 0)
//	{
//		ans += c[x];
//		x -= lowbit(x);
//	}
//	return ans;
//}
//
//int main()
//{
//	cin >> n >> m;
//	getchar();
//	for (int i = 0; i < m; i++)
//	{
//		char temp = getchar();
//		if (temp == 'A')
//		{
//			int k = 0;
//			cin >> k;
//			getchar();
//
//			cout << qu(k) << endl;
//		}
//		else if (temp == 'B')
//		{
//			int k, p;
//			cin >> k >> p;
//			getchar();
//			add(k, p);
//		}
//		else
//		{
//			int k, p;
//			cin >> k >> p;
//			getchar();
//			add(k, -p);
//		}
//	}
//	system("pause");
//}