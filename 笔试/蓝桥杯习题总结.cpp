#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define MOD 1e5


int n = 0;
const int MaxN = 1e5;
long long w[MaxN + 1]; //每一个点的权重
long long ww[MaxN + 1]; //每一个点作为根节点时能得到的最大权和

vector<int> g[MaxN + 1]; // 邻接表

/*以root为根，算出最大的权和*/

//void dfs(int root, int fa)
//{
//	ww[root] = w[root];
//	for (int i = 0; i < g[root].size(); i++)
//	{
//		int son = g[root][i];//其中的一个孩子
//		if (son != fa)
//		{
//			dfs(son, root);
//			if (ww[son] > 0)
//				ww[root] += ww[son];
//		}
//	}
//	if (ww[root] > ans)
//		ans = ww[root];
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%lld", &w[i]);
//	}
//	for (int j = 0; j < n - 1; j++)
//	{
//		int u = 0;
//		int v = 0;
//		scanf("%d %d", &u, &v);
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//
//	dfs(5, 0);
//	printf("%lld\n", ans);
//}



#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string pai[7];

int ans = 0;

//void f(int k, int cnt)
//{
//	if (cnt > 13 || k > 13)
//		return;
//	if (k == 13 && cnt == 13)
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		f(k + 1, cnt + i);
//	}
//}
//int main()
//{
//	f(0, 0);
//	cout << ans << endl;
//	system("pause");
//}




//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//
//int cmp(string a, string b) //有可能a 为"00"  b为"4"，所以要去0
//{
//	if (a.find_first_not_of('0') == string::npos)
//		a = "0";
//	else
//		 a.substr(a.find_first_not_of('0'));
//	if (b.find_first_not_of('0') == string::npos)
//		b = "0";
//	else
//		b.substr(b.find_first_not_of('0'));
//
//
//	if (a.size() > b.size())
//		return 1;
//	else if (a.size() < b.size())
//		return -1;
//	else  //长度相等
//	{
//		if (a < b)
//			return -1;
//		else if (a > b)
//			return 1;
//		else
//			return 0; //相等
//
//	}
//}
//
//string substract(string a, string b)
//{
//	// a大于b
//	// 1.翻转
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//
//	// 2.按位做减法
//	 
//	for (int i = 0; i < b.size(); i++)
//	{
//		if (a[i] >= b[i])
//		{
//			a[i] = ( a[i] - b[i] + '0');
//		}
//		else //要借位了
//		{
//			int k = 1;
//			while (a[i + k] == '0')
//			{
//				a[i + k] = '9';
//				k++;
//			}
//			//这里可以保证 i+k这一位上不是0
//			a[i + k] = a[i + k] - '1' + '0'; // a[i+k] - '1'是整数，整数还要变成字符
//
//			//    a[i] - '0'是整数    b[i] - '0'是整数
//			a[i] = a[i] - '0' + 10 - (b[i] - '0') + '0';
//		}
//	}
//	reverse(a.begin(), a.end()); //翻转过来
//
//	if (a.find_first_not_of('0') == string::npos) //从头到尾全是0，则直接返回0,
//		return "0";
//	return a.substr(a.find_first_not_of('0'));
//}
//
//string divide(string a, string b)  //只考虑a小于b的情况
//{
//	string ans = "0.";
//	//转化为减法
//
//	//因为a小于b，所以让a补0
//
//	for (int i = 0; i < 101; i++) // 101次
//	{
//		a.append("0");
//		int t = 0;
//		while (cmp(a, b) >= 0) // a >= b
//		{
//			a = substract(a, b); //不停地做减法操作
//			t++; // 记录了减法做多少次
//		}
//		ans.append(to_string(t));
//	}
//	return ans;
//}
//int main()
//{
//	string a = "100";
//	string b = "7";
//	cout << divide(a, b) << endl;
//	system("pause");
//}
//
//#define MOD  1000000007
//int data[50][50];
//int m, n, k = 0;
//long long ans1 = 0;
//long long cache[50][50][14][13];
//
//
//long long dfs2(int x, int y, int max, int cnt)
//{
//	//先查缓存
//	if (cache[x][y][max+1][cnt] != -1)
//		return cache[x][y][max+1][cnt];
//	long long ans = 0;
//	if (x == n || y == m || cnt > k)
//	{
//		return  0;
//	}
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1) //已经到达最后一个格子
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans++;
//			if (ans > MOD)
//				ans %= MOD;
//		}
//		return ans;
//	}
//	if (cur > max)// 可以取这个物品
//	{
//		ans += dfs2(x, y + 1, cur, cnt + 1);
//		ans += dfs2(x + 1, y, cur, cnt + 1);
//	}
//
//	//对于价值小的，或者价值大但是不取这个商品的情况下
//	ans += dfs2(x, y + 1, max, cnt);
//	ans += dfs2(x + 1, y, max, cnt);
//
//	//记录缓存
//	cache[x][y][max+1][cnt] = ans % MOD;
//	return ans%MOD;
//}
//void dfs(int x, int y, int max, int cnt)
//{
//	if (x == n || y == m || cnt > k)
//	{
//		return;
//	}
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1) //已经到达最后一个格子
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans1++;
//			if(ans1 > MOD)
//				ans1 %= MOD;
//		}
//	}
//	if (cur > max)// 可以取这个物品
//	{
//		dfs(x, y + 1, cur, cnt + 1);
//		dfs(x + 1, y, cur, cnt + 1);
//	}
//
//	//对于价值小的，或者价值大但是不取这个商品的情况下
//	dfs(x, y + 1, max, cnt);
//	dfs(x + 1, y, max, cnt);
//}
//int main()
//{
//	long long v[10][10][10][10];
//	memset(v, -1, sizeof(v));
//	system("pause");
//}