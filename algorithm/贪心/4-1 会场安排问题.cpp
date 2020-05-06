#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[10005], b[10005];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int k = 0, j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[j]) k++;
		else j++;
	}
	cout << k << endl;
	system("pause");
	return 0;
}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<pair<int, int>> vp(n);
//		int a = 0;
//		int b = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a;
//			cin >> b;
//			vp[i] = make_pair(a, b);
//
//		}
//		sort(vp.begin(), vp.end(), [](pair<int, int>& p1, pair<int, int>& p2)
//		{
//			if (p1.second == p2.second)
//				return p1.first > p2.first;
//			return p1.second < p2.second;
//		});
//
//		int ret = 1;
//		for (int i = 0; i < n - 1; i++)
//		{
//			if (vp[i + 1].first >= vp[i].second)
//			{
//				ret++;
//			}
//		}
//		cout << ret << endl;
//	}
//	system("pause");
//}
/*
5
1 23
12 28
25 35
27 80
36 50
*/