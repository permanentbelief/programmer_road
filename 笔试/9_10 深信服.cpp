#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x)
//		:val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//};
//class Solution {
//public:
//	TreeNode* dfs(string& S, int position, int d) // position 当前遍历到的位置 , d是深度
//	{
//		if (position == S.size())
//		{
//			return nullptr;
//		}
//		int cnt = 0;
//		int depth = 0;
//		int tmp = position;
//		while (tmp < S.size() && S[tmp] == '-')
//		{
//			tmp++;
//			depth++;
//		}
//
//		if (depth == d)
//		{
//			int vals = 0;
//			while (tmp < S.size() && S[tmp] != '-')
//			{
//				vals = vals * 10 + (S[tmp] - '0');
//				tmp++;
//			}
//			position = tmp;
//			TreeNode* root = new TreeNode(vals);
//			root->left = dfs(S, position, depth + 1);
//			root->right = dfs(S, position, depth + 1);
//			return root;
//		}
//		return nullptr;
//
//	}
//	TreeNode* recoverFromPreorder(string S) {
//		int position = 0;
//		return dfs(S, position, 0);
//	}
//};
//
//int main()
//{
//
//	string s = "1-2--3--4-5--6--7";
//	Solution ss;
//	ss.recoverFromPreorder(s);
//
//
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(5);
//	root->left->left = new TreeNode(3);
//	root->left->right = new TreeNode(4);
//
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(7);
//}


//class Solution {
//public:
//	vector<vector<string>> vvs;
//
//	bool check(int col, int row, vector<int>& pre)
//	{
//		for (int i = 0; i < pre.size(); i++)
//		{
//			if (col == pre[i] || col + pre[i] == row + i ||
//				row - i == col - pre[i])
//				return false;
//		}
//		return true;
//	}
//	void dfs(int n, int u, vector<int>& pre)
//	{
//		if (u == n)
//		{
//			vector<string> vs(n, string(n, '.'));
//			for (int i = 0; i < n; i++)
//			{
//				vs[i][pre[i]] = 'Q';
//			}
//			vvs.push_back(vs);
//			// 0 . 0 0
//			// 0 0 0 .
//			// 0 0 . 0
//			// . 0 0 0
//			return;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (check(i, u, pre)) // i是列 u是行  
//			{
//				pre.push_back(i);
//				dfs(n, u + 1, pre);
//				pre.pop_back();
//			}
//		}
//	}
//	vector<vector<string>> solveNQueens(int n) {
//		vector<int> pre;
//		dfs(n, 0, pre);
//		return vvs;
//	}
//};

//void kuai1(vector<int>& arr)
//{
//	int l = 0;
//	int r = arr.size() - 1;
//	int index = 0;
//	int key = arr[l];
//	while (l < r)
//	{
//
//		while (l < r && arr[r] >= key)
//			r--;
//		while (l < r && arr[l] <= key)
//			l++;
//		swap(arr[l], arr[r]);
//	}
//	swap(arr[l], arr[0]);
//}
//
//
//void kuai2(vector<int>& li, int low, int high)
//{
//	int tmp = li[low];
//	while (low < high){
//		while (low < high && tmp <= li[high]) high--;
//		li[low] = li[high];
//		while (low < high && tmp >= li[low]) low++;
//		li[high] = li[low];
//	}
//	li[high] = tmp;
//}
//int main()
//{
//
//	vector<int> arr1 = { 25, 40, 15, 3, 40 };
//	vector<int> arr2 = { 25, 40, 15, 3, 40 };
//	kuai1(arr1);
//	for (auto e : arr1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	kuai2(arr2,0,sizeof(arr2)/sizeof(arr2[0]) - 1);
//	for (auto e : arr2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//	// Solution s;
//	// s.solveNQueens(4);
//}



//
//using namespace std;
//typedef long long LL;
//const int maxn = 1e5 + 100;
//int T, n, m;
//int  A[maxn];
//int sx, sy;
//int ex, ey;
//int vis[11][11];
//int dr[][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
//int res;
//void dfs(int x, int y, int cnt)
//{
//	if (x == ex&&y == ey)
//	{
//		if (cnt == n*m - 1)
//			res++;
//		return;
//	}
//	for (int i = 0; i<4; i++)
//	{
//		int xx = x + dr[i][0];
//		int yy = y + dr[i][1];
//		if (!(xx >= 0 && xx<n&&yy >= 0 && yy<m)) continue;
//		if (vis[xx][yy]) continue;
//		vis[xx][yy] = 1;
//		dfs(xx, yy, cnt + 1);
//		vis[xx][yy] = 0;
//	}
//}
//
//int main()
//{
//	while (cin >> n >> m)
//	{
//		cin >> sx >> sy;
//		cin >> ex >> ey;
//		res = 0;
//		memset(vis, 0, sizeof(vis));
//		vis[sx][sy] = 1;
//		dfs(sx, sy, 0);
//		cout << res << endl;
//	}
//}



const int N = 15;

int f[N][N];


int x, y;
int p_x, p_y;
int i_x, i_y;
int cnt = 0;

void dfs(vector<vector<bool>>& books, int i, int j, int count)
{
	//cout << x << " " << y << endl;
	if (i == p_x && j == p_y)
	{
		if (count == x * y - 1)
			cnt++;

	
		return;
	}
	books[i][j] = 1;
	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	
	for (int k = 0; k < 4; k++)
	{
		int nx = i + pos[k][0];
		int ny = j + pos[k][1];
		if (nx < 0 || ny < 0 || nx >= x || ny >= y || books[nx][ny] == true)
			continue;
		//books[nx][ny] = true;
		dfs(books, nx, ny, count + 1);
		//books[nx][ny] = false;

	}
	books[i][j] = 0;
}
int main()
{
	cin >> x >> y;
	cin >> i_x >> i_y;
	cin >> p_x >> p_y;
	//cout << p_x << " " << p_y << endl;

	int count = 0;
	vector<vector<bool>> books(x, vector<bool>(y, false));
	// books[i_x][i_y] = 1;
	dfs(books, i_x, i_y, count);

	cout << cnt << endl;
	system("pause");
}
