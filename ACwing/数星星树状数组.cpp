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
//#include <cstdio>
//using namespace std;
//
//const int  M = 32010;
//
//int n;
//int tr[M], num[M];
//
//int lowbit(int x)
//{
//	return x & (-x);
//}
//
//void add(int x)
//{
//	for (int i = x; i <= M; i += lowbit(i)) tr[i] ++;
//}
//
//int query(int x)
//{
//	int res = 0;
//	for (int i = x; i; i -= lowbit(i)) res += tr[i];
//	return res;
//}
//
//int main()
//{
//	cin >> n;
//	int t = n;
//	while (t--)
//	{
//		int x, y;
//		scanf("%d%d", &x, &y);
//		x++;    //x可能是0，而树状数组起始是1
//		num[query(x)] ++; //级数是query(x)的星星数量加一
//		add(x);
//	}
//
//	for (int i = 0; i < n; i++) printf("%d\n", num[i]);
//	system("pause");
//	return 0;
//}


#include <iostream>


using namespace std;
const int N = 1e5 + 20;
int c[N];
int a[N];
int n, m;

int lowbit(int x)
{
	return x&(-x);
}
void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(x))
	{
		c[x] += y;
	}
}
int query(int x)
{
	int ans = 0;
	while (x >  0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(a[i],1);
	}

	while (m--)
	{
		getchar();
		char temp = getchar();
		if (temp == 'Q')
		{
			int a, b;
			cin >> a >> b;
			cout << query(b) - query(a - 1) << endl;
		}
		else
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(a, c);
			add(b + 1, -c);
		}
	}
	system("pause");
	return 0;


}