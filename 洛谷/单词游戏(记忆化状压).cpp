#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// 单词 游戏   状压记忆化
using namespace std;

//const int N = 20;
//int n;
//
//int max_ = 0;
//bool vis[N];
//
//string st[18];
//vector<int> v[210];
//bool f[18];
//
//int dfs(int x)
//{
//	int ans = 0;
//	for (auto e : v[st[x][st[x].size() - 1]])
//	{
//		if (!f[e])
//		{
//			f[e] = 1;
//			ans = max(ans, dfs(e));
//			f[e] = 0;
//		}
//	}
//	return ans + st[x].size();
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> st[i];
//		v[st[i][0]].push_back(i);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = 1;
//		ans = max(dfs(i), ans);
//		f[i] = 0;
//	}
//	cout << ans << endl;
//	system("pause");
//	//cout << max_ << endl;
//
//
//}
//
//
//using namespace std;
//
//const int N = 20;
//
//
//void dfs(vector<string>& vs, int idx, string str, int& max_)
//{
//	if (idx == vs.size())
//	{
//		max_ = max((int)(str.size()), max_);
//		return;
//	}
//
//	for (int i = 0; i < vs.size(); i++)
//	{
//		if ((vis[i] == false && vs[i][0] == str.back()))
//		{
//			str += vs[i];
//			max_ = max(max_, (int)str.size());
//			vis[i] = true;
//			dfs(vs, idx + 1, str, max_);
//			vis[i] = false;
//			str.erase(str.size() - vs[i].size());
//		}
//
//	}
//}
//
//
//
//int main()
//{
//	cin >> n;
//	vs.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vs[i];
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		vis[i] = true;
//		int max_ = 0;
//		dfs(vs, 0, vs[i], max_);
//		ans = max(ans, max_);
//		vis[i] = false;
//	}
//	cout << ans << endl;
//	system("pause");
//}


string st[18];
string V[18];
int F[18][70000];
int n = 0;
int dfs(int now, int S)
{
	if (F[now][S] != 0)
		return F[now][S];
	F[now][S] = 0;
	for (int i = 0; i != n; i++)
	{
		if ((!(S & (1 << i))) && V[i][0] == V[now].back())
		{
			F[now][S] = max(F[now][S], dfs(i, (S | (1 << i))));
		}
	}
	return F[now][S] += V[now].size();
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> V[i];
	}
	int ans = 0;
	for (int i = 0; i != n; i++)
	{
		ans = max(ans, dfs(i, (1 << i)));
	}
	cout << ans << endl;
	system("pause");
}



