#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <vector>
#include <set>
using namespace std;


// dfs
//void dfs(vector<vector<int>>& s, int target, vector<int>& arr, vector<int> v, int cur)
//{
//	if (target == 0)
//	{
//		s.push_back(v);
//		return;
//	}
//	for (int i = cur; i < arr.size(); i++)
//	{
//		if (target >= arr[i])
//		{
//
//			v.push_back(arr[i]);
//			dfs(s, target - arr[i], arr, v, i + 1);
//			v.pop_back();
//
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n >> m;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	vector<vector<int>> s;
//	vector<int> vv;
//	dfs(s, m, v, vv, 0);
//	cout << s.size() << endl;
//	system("pause");
//
//}

//状态表示:
//#include <iostream>
//
//#include <set>
//#include <vector>
//using namespace std;
//
//void dfs(set<vector<int>>& s, vector<int> v, int t, int target)
//{
//	if (t == 0)
//	{
//		sort(v.begin(), v.end());
//		s.insert(v);
//		return;
//	}
//	for (int i = 1; i < target; i++)
//	{
//		if (t >= i)
//		{
//			v.push_back(i);
//			dfs(s, v, t - i, target);
//			v.pop_back();
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	set<vector<int>> s;
//	vector<int> v;
//	dfs(s, v, n, n);
//	cout << s.size()%10000007 << endl;
//	system("pause");
//}



//using namespace std;
//
//const int C = 1010, M = 1e5 + 10, N = 105;
//
//int n, m;
//int a[N];
//int c[C];
//bool f[M];
//
//int main()
//{
//	while (scanf("%d%d", &n, &m), n || m)
//	{
//		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
//
//		memset(f, 0, sizeof f);
//		f[0] = 1;
//		int used[M];
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 0; j <= m; j++) used[j] = 0;
//
//			for (int j = a[i]; j <= m; j++)
//			if (!f[j] && f[j - a[i]] && used[j - a[i]]<c[i])
//				f[j] = 1, used[j] = used[j - a[i]] + 1;
//		}
//
//		int ans = 0;
//		for (int i = 1; i <= m; i++)
//		if (f[i]) ans++;
//		printf("%d\n", ans);
//	}
//
//	return 0;
//}


/*

背包问题 01
*/
#include <iostream>
using namespace std;

const  int N = 100;

int V[N] = { 0 };
int W[N] = { 0 };



void Order(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] % 2 == 1 && arr[j + 1] % 2 == 0)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	Order(arr);

	system("pause");
}