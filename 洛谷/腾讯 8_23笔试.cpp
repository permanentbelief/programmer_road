#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;




// 第二题  求第k(k < 5)的子序列

/*
#include <set>
string str;
int n, k;
int main()
{
	cin >> str;
	cin >> k;
	n = str.size();
	set<string> ss;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k && (i + j) <= n; j++)
		{
			ss.insert(str.substr(i, j));
		}
	}

	for (auto e: ss)
	{
		cout << e << endl;
	}

	system("pause");
}
*/

// 延伸题 不重复子集
//void dfs(vector<int>& a, vector<vector<int>>& ans, vector<int>& path, vector<int>& vis, int beg)
//{
//	ans.push_back(path);
//	for (int i = beg; i < a.size(); i++)
//	{
//		if (i > 0 && a[i] == a[i - 1] && !vis[i - 1])
//		{
//			continue;
//		}
//		path.push_back(a[i]);
//		vis[i] = 1;
//		dfs(a, ans, path, vis, i + 1);
//		vis[i] = 0;
//		path.pop_back();
//
//	}
//}
//int main()
//{
//	vector<int> nums = { 1, 5, 2, 3, 2 };
//	vector<vector<int>> ans;
//	vector<int> path;
//	vector<int> vis(nums.size(), 0);
//	sort(nums.begin(), nums.end());
//
//	dfs(nums, ans, path, vis, 0);
//	for (auto e : ans)
//	{
//		for (auto ee : e)
//		{
//			cout << ee << " ";
//		}
//		cout << endl;
//	}
//}


//第三题
// 找到小于N的最大的999然后拆分即可

//int n = 0;
//void solve()
//{
//	cin >> n;
//	int x = n;
//	int d = 0;
//	int ans = 0;
//	while (x >= 10) // 101   10 
//					// 99 1 
//	{
//		d *= 10;
//		d += 9;
//		x /= 10;
//		ans += 9;
//	}
//
//	int y = n - d;
//	while (y)
//	{
//		ans += y % 10;
//		y /= 10;
//	}
//	cout << ans << endl;
//}
//int main()
//{
//	
//	solve();
//	system("pause");
//
//}




//第四题

int n;
int arr[5001];

int dfs(int l, int r){
	if (l == r){
		if (arr[l] == 0) return 0;
		else return 1;
	}

	int ans = r - l + 1;
	int minl = INT_MAX;
	for (int i = l; i <= r; i++){
		minl = min(minl, arr[i]);
	}
	int ans1 = minl;
	int curl = -1;
	for (int i = l; i <= r; i++){
		arr[i] -= minl;
		if (arr[i] > 0){
			if (i == 0 || arr[i - 1] == 0){
				curl = i;
			}
			if (i == r){
				ans1 += dfs(curl, i);
			}
		}
		else{
			if (i>0 && arr[i - 1] > 0){
				ans1 += dfs(curl, i - 1);
			}
		}
	}
	return min(ans, ans1);
}

void solve() {
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> arr[i];
	}
	cout << dfs(0, n - 1) << endl;
	
}
int main()
{
	solve();
	system("pause");
}


//using namespace std;
//typedef long long ll;
//const ll N = 5000 + 10, inf = 0x3f3f3f3f;
//ll n, h[N], mi;
//ll solve(ll l, ll r, ll hf) {
//	ll mi = inf, cost = 0;
//	for (ll i = l; i <= r; ++i)mi = min(mi, h[i]);
//	for (ll i = l, j; i <= r; ++i) {
//		if (h[i] == mi)continue;
//		for (j = i + 1; j <= r&&h[j]>mi; ++j);
//		cost += solve(i, j - 1, mi);
//		i = j;
//	}
//	return min(cost + (mi - hf), r - l + 1);
//}
//int main() {
//	//FRER();
//	scanf("%lld", &n);
//	for (ll i = 1; i <= n; ++i)scanf("%lld", &h[i]);
//	printf("%lld\n", solve(1, n, 0));
//	system("pause");
//	return 0;
//}





// 腾讯第5题 

//using namespace std;
//
//string str;
//int Q;
//
//const int N = 450;
//bool f[N][N];
//int dp[N][N];
//int nn;
//void init()
//{
//
//	for (int i = nn - 1; i >= 0; i--)
//	{
//	//	f[i][i] = true;
//		for (int j = i; j < nn; j++)
//		{
//			if (str[i] == str[j] && ((j - i < 2) || f[i + 1][j - 1]) )
//			{
//				f[i][j] = true;
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> str;
//
//	nn = str.size();
//	init();
//
//
//	for (int i = 0; i <= nn - 1; i++)
//	{
//		for (int j = 0; j <= nn - 1; j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	memset(dp, 0x3f, sizeof dp);
//	for (int l = 0; l < nn; l++)
//	{
//		for (int i = 0; i + l < nn; i++)
//		{
//			int j = i + l;
//			if (f[i][j]) dp[i][j] = 1;
//			else
//			{
//				for (int k = i + 1; k <= j; k++)
//				{
//					dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
//				}
//			}
//		}
//	}
//	cout << endl;
//	cout << endl;
//	for (int i = 0; i <= nn - 1; i++)
//	{
//		for (int j = 0; j <= nn - 1; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	int q = 0;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << dp[a - 1][b - 1] << endl;
//	}
//	system("pause");
//
//}
//





// 腾讯T5 区间dp 我写的

/*
string str;
int Q;

const int N = 450;
bool f[N][N];
int dp[N][N];
int nn;
void init()
{

	for (int i = nn - 1; i >= 0; i--)
	{
		// f[i][i] = true;
		for (int j = i; j < nn; j++)
		{
			if (str[i] == str[j] && ((j - i < 2) || f[i + 1][j - 1]))
			{
				f[i][j] = true;
			}
		}
	}
}
int main()
{
	cin >> str;

	nn = str.size();
	init();


	for (int i = 0; i <= nn - 1; i++)
	{
		for (int j = 0; j <= nn - 1; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	memset(dp, 0x3f, sizeof dp);



	str = ' ' + str;

	for (int i = 1; i <= nn; i++)
	{
		dp[i][i] = 1;
	}
	for (int l = 2; l <= nn; l++)
	{
		for (int i = 1; i + l - 1 <= nn; i++)
		{
				int j = i + l - 1;
				for (int k = i; k + 1 <= j; k++)
				{
					dp[i][j] = min(dp[i][j],  dp[i][k] + dp[k + 1][j]);
				}
			
		}
	}
	for (int i = 1; i <= nn; i++)
	{
		for (int j = 1; j <= nn; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[a ][b ] << endl;
	}

}
*/




