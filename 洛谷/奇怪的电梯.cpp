#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;
	
//
////方法一 拓扑排序
//using namespace std;//标准名称函数库开启 
//
//const int MAXN = 5000 + 10;//定义常量大小 
//const long long mod = 80112002;//定义最终答案mod的值 
//int in[MAXN];
//int out[MAXN];
//vector<int> dp[MAXN];
//int nums[MAXN];
//int n, m, a, b;
//
//
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		in[a]++;
//		out[b]--;
//		dp[b].push_back(a);
//	}
//	queue<int> q;
//	for (int i = 1; i <= n; i++)
//	{
//		if (in[i] == 0)
//		{
//			nums[i] = 1;
//			q.push(i);
//		}
//	}
//	while (q.size())
//	{
//		int tot = q.front();
//		q.pop();
//		for (int i = 0; i < dp[tot].size(); i++)
//		{
//			int next = dp[tot][i];
//			in[next]--;
//			nums[next] = (nums[next] + nums[tot]) % mod;
//			if (in[next] == 0) q.push(dp[tot][i]);
//		}
//	}
//	
//	int outs = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (out[i] == 0)
//		{
//			outs = (outs + nums[i]) % mod;
//		}
//	}
//	cout << outs << endl;
//	system("pause");
//}

// 记忆化dfs
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		cin >> a >> b;
//		in[a]++;
//		out[b]--;
//		dp[b].push_back(a);
//	}
//	queue<int> q;
//	for (int i = 1; i <= n; i++)
//	{
//		if (in[i] == 0)
//		{
//			nums[i] = 1;
//			q.push(i);
//		}
//	}
//	while (q.size())
//	{
//		int tot = q.front();
//		q.pop();
//		for (int i = 0; i < dp[tot].size(); i++)
//		{
//			int next = dp[tot][i];
//			in[next]--;
//			nums[next] = (nums[next] + nums[tot]) % mod;
//			if (in[next] == 0) q.push(dp[tot][i]);
//		}
//	}
//	
//	int outs = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (out[i] == 0)
//		{
//			outs = (outs + nums[i]) % mod;
//		}
//	}
//	cout << outs << endl;
//	system("pause");
//}






//const int N = 210;
//int n, start, send;
//int a[N];
//int min_ = INT_MAX;
//int ans = 0;
//
//void dfs(int now, int sum) // u是当前是第几层, i是当前层数可以到达的区间, count是次数
//{
//	
//	if (now == send) min_ = min(min_, sum);
//	if (sum > min_) return;
//
//	//vis[now] = 1;
//	if (now + a[now] <= n) dfs(now + a[now], sum + 1);
//	if (now - a[now] >= 1) dfs(now - a[now], sum + 1);
//
//	
//}
//
//int main()
//{
//	cin >> n >> start >> send;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	dfs(start, 0);
//	
//	cout << min_ << endl;
//	system("pause");
//}


//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <climits>
//#include <map>
//vector<string> splits(string str)
//{
//	vector<string> vs;
//	int start = 1;
//	string res;
//	bool flag = false;
//	while (1)
//	{
//		int k = str.find(",");
//		if (k == -1)
//		{
//			if (flag == false)
//				vs.push_back(str.substr(1, str.size() - 2));
//			else
//			{
//				vs.push_back(str.substr(0, str.size() - 1));
//			}
//			break;
//		}
//		flag = true;
//		vs.push_back(str.substr(start, k - 1));
//		str = str.substr(k + 1);
//		start = k;
//	}
//	return vs;
//}
//int main()
//{
//	//int n = 0;
//	//cin >> n;
//	//string str;
//	//getchar();
//	//vector<string> vs;
//	//for (int i = 1; i <= n; i++)
//	//{
//	//	getline(cin, str);
//	//	int index = 0;
//	//	for (int k = 0; k < str.size(); k++)
//	//	{
//	//		if (str[k] == '(')
//	//		{
//	//			index = k;
//	//			break;
//	//		}
//	//	}
//	//	string src = str.substr(0, index);
//	//	vs = splits(str.substr(index));
//	//	for (auto e : vs)
//	//	{
//	//		cout << e << endl;
//	//	}
//	//	cout << endl;
//	//}
//
//	map<string, int> mymap;
//	string res = "1";
//	string res1 = "2";
//	mymap[res1] = 0;
//	mymap[res] = 1;
//	system("pause");
//}

//const int N = 257;
//#define inf = 0x3f3f3f3f;
//using namespace std;
//int n;
//
//int G[N][N], depth[N], f[N];
//char tmp[N];
//char rb[N + 1];
//
//
//int find(int x)
//{
//	if (x == f[x])
//		return x;
//	return f[x] = find(f[x]);
//}
//
//void dfs(int x)
//{
//	for (int i = 0; i < N; i++)
//	{
//		if (G[x][i])
//		{
//			G[x][i] = G[i][x] = 0; dfs(i);
//		}
//	}
//	rb[n--] = x;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < N; i++)
//	{
//		f[i] = i;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s", tmp);
//		G[tmp[0]][tmp[1]] = G[tmp[1]] [tmp[0]] = 1;
//		int x = find(tmp[0]);
//		int y = find(tmp[1]);
//		f[x] = y;
//		depth[tmp[0]]++;
//		depth[tmp[1]]++;
//	}
//	int ans = 0;
//	for (int i = 1; i < N; i++)
//	{
//		if (f[i] == i && depth[i])
//			ans++;
//	}
//	if (ans != 1)
//	{
//		puts("No Solution");
//		return 0;
//
//	}
//	int cnt = 0;
//	int hen = 0;
//	for (int i = 1; i < N; i++)
//	{
//		if (depth[i] & 1)
//		{
//			cnt++;
//			if (!hen)
//			{
//				hen = i;
//			}
//		}
//			
//	}
//	if (!hen)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (depth[i])
//			{
//				hen = i;
//				break;
//			}
//		}
//	}
//	if (cnt && cnt != 2)
//	{
//		puts("No Solution");
//		return  0;
//	}
//	dfs(hen);
//	puts(rb);
//	//cout << (char)(88) << endl;
//	system("pause");
//	return 0;
//	
//}



//const int N = 110;//定义常量大小 
//
//int f[N][N];
//int n, m;
//int mp[N][N];
//vector<int> dp[N];
//bool vis[N];
//int max_ = 0;
//int ans = INT_MAX;
//int sum = 0;
//
//void dfs(int x, int y , int sum , bool flag)
//{
//	if (x < 1 || x > m || y < 1 || y > m)
//		return;
//	if (sum >= f[x][y])
//		return;
//	f[x][y] = sum;
//	if (x == m && y == m)
//	{
//		if (sum < ans)
//			ans = sum;
//		return;
//	}
//	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + pos[i][0];
//		int ny = y + pos[i][1];
//		if (nx  < 1 || nx > m || ny < 1 || ny > m)
//			continue;
//		if (mp[nx][ny])
//		{
//			if (mp[x][y] == mp[nx][ny])
//			{
//				dfs(nx, ny, sum, false);
//			}
//			else
//			{
//				dfs(nx, ny, sum + 1, false);
//			}
//		}
//		else 
//		{
//			if (flag == false)
//			{
//				mp[nx][ny] = mp[x][y];
//				dfs(nx, ny, sum + 2, true);
//				mp[x][y] = 0;
//			}
//
//		}
//
//	}
//}
//
//int main()
//{
//	cin >> m >> n;
//	memset(f, 0x7f, sizeof f);
//	for (int i = 1; i <= n; i++)
//	{
//		int x, y, c;
//		cin >> x >> y >> c;
//		mp[x][y] = c + 1;
//	}
//	dfs(1, 1, 0, false);
//	if (ans == INT_MAX) cout << -1 << endl;
//	else
//		cout << ans << endl;
//	system("pause");
//	
//}