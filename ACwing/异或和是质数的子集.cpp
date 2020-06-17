#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//#include <iostream>
//using namespace std;
//
//
//#define MOD 10e9 + 7
//const int N = 5005;
//int a[N];
//
//
//bool check(int n)
//{
//	if (n < 2)
//		return false;
//	for (int i = 2; i <= n / 2; i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//vector<int> v;
//vector<vector<int>> vv;
//int k = 0; 
//int jk = 0;
//void dfs(int& count, int* a, int n, int cur, int sum)
//{
//
//	if (check(sum))
//		count++;
//
//	//k = 0;
//	
//	vv.push_back(v);
//	for (int i = cur; i < n; i++)
//	{
//		//v.push_back(i);
//		//jk += a[i];
//		dfs(count, a, n, i + 1, sum^a[i]);
//		//v.pop_back();
//		//jk -= a[i];
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int count = 0;
//	dfs(count, a, n, 0, 0);
//	printf("%d\n", count);
//	system("pause");
//}

//#include <iostream>
//using namespace std;
//const int M = 8192;
//const int MOD = 1e9 + 7;
//
//bool isPrime(int x){
//	for (int i = 2; i*i <= x; i++){//注意这里是有等于号的
//		if (x%i == 0)//能整除某个数说明不是质数
//			return false;
//	}
//	return true;//是质数
//}
//int f[2][M + 5];
//
//int  main()
//{
//	int n = 0;
//	int v = 0;
//	f[0][0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v;
//		for (int j = 0; j < M; j++)
//		{
//			f[i & 1][j] = f[(i - 1) & 1][j];
//
//			if ((j^v) < M)
//			{
//				f[i & 1][j] = (f[(i - 1) & 1][j] + f[(i - 1) & 1][j^v]) % MOD;
//			}
//		}
//	}
//
//	int res = 0;
//	for (int i = 2; i < M; i++)
//	{
//		if (isPrime(i))
//		{
//			res += f[n & 1][i];
//			res %= MOD;
//		}
//	}
//	cout << res << endl;
//}

#include <iostream>
#include <vector>
using namespace std;

const int N = 310;
int R, C;


int dp[N][N];

int maxlen = -1;

int addx[] = { 1, -1, 0, 0 };
int addy[] = { 0, 0, 1, -1 };

int Dfs(int x, int y, vector<vector<int>>& vv)
{
	if (dp[x][y] != 0)
		return dp[x][y];
	int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	for (int i = 0; i < 4; i++)
	{
		int nx = x + pos[i][0];
		int ny = y + pos[i][1];

		if (nx < 0 || nx >= vv.size() || ny < 0 || ny >= vv[0].size()
			|| vv[nx][ny] > vv[x][y])
			continue;

		dp[x][y] = max(Dfs(nx, ny, vv) + 1, dp[x][y]);
	}

	return dp[x][y];
}

//int main()
//{
//	cin >> R >> C;
//	vector<vector<int>> arr(R, vector<int>(C, 0));
//	for (int i = 0; i < R; i++){
//		for (int j = 0; j<C; j++){
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < R; i++){
//		for (int j = 0; j< C; j++){
//			int len = Dfs(i, j);
//			maxlen = max(maxlen, len, arr);
//		}
//	}
//
//	cout << maxlen + 1 << endl;
//
//	return 0;
//}

/*

698读电话号码    字符串模拟
696 哈默队长     double 二分
1109 等式
*/

//#include <iostream>
//
//#include <unordered_set>
//using namespace std;
//
//
//const int N = 100001;
//
//
//int a[N];
//int height[N];
//
//unordered_set<pair<int, int>> up;
//
//int main()
//{
//	int n, h, p, m;
//	cin >> n >> p >> h >> m;
//	height[1] = h;
//	for (int i = 0, a, b; i < m; i++)
//	{
//		cin >> a >> b;
//		if (a > b) swap(a, b);
//		if (!up.count({ a, b }))
//		{
//			up.insert({ a, b });
//			height[a + 1] -= 1;
//			height[b] += 1;
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		height[i] += height[i - 1];
//		cout << height[i] << endl;
//	}
//
//	return 0;
//}