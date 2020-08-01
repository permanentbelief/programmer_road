#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;


// P5149会议座位  包含string类型的逆序对
//map<string, int> m;
//
//
//const int N = 1e5 + 5;
//string s;
//int n, a[N], b[N];
//long long ans = 0;
//
//void merge(int l, int r)
//{
//	if (l >= r) return;
//	int mid = (l + r) / 2;
//	merge(l, mid);
//	merge(mid + 1, r);
//	int i = l;
//	int j = mid + 1;
//	int k = l;
//	while (i <= mid && j <= r)
//	{
//		if (a[i] < a[j]) b[k++] = a[i++];
//		else b[k++] = a[j++], ans += mid - i + 1;
//	}
//	while (i <= mid) b[k++] = a[i++];
//	while (j <= r) b[k++] = a[j++];
//	for (int i = l; i <= r; i++) a[i] = b[i];
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> s;
//		m[s] = i;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> s;
//		a[m[s]] = i;
//	}
//	merge(1, n);
//	cout << ans << endl;
//	
//	system("pause");
//}

// P2922 secret Message G


//const int N = 5e5 + 1000;
//
//
//int n,m;
//const int M = 5e4 + 1000;
//
//int son[N][10];
//int sums[N];
//int cnt[N];
//int idx;
//int a[M];
//int size1 = 0;
//
//
//void insert()
//{
//	int p = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		int& s = son[p][a[i]];
//		if (s == -1) s = ++idx;
//		p = s;
//		sums[p]++;
//	}
//	cnt[p]++;
//}
//
//int query()
//{
//	int sum = 0;
//	int p = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		int s = son[p][a[i]];
//		if (s == -1) return sum;
//		p = s;
//		sum += cnt[p];
//	}
//	return sum + sums[p] - cnt[p];
//}
//int main()
//{
//	cin >> n >> m;
//	memset(son, -1, sizeof(son));
//	while (n--)
//	{
//		cin >> size1;
//		for (int i = 0; i < size1; i++)
//		{
//			cin >> a[i];
//		}
//		insert();
//	}
//	while (m--)
//	{
//		cin >> size1;
//		for (int i = 0; i < size1; i++)
//		{
//			cin >> a[i];
//		}
//		cout << query() << endl;
//	}
//}


#include <unordered_map>
//const int  N = 1e4;
//const int M = 1e3 + 300;
//int n, m;
//string str;
//vector<unordered_map<string, int>> v;
//int son[N][26];
//int idx = 0;
//int cnt[N];
//bool b[N][30];
//
//
//void insert(int x)
//{
//	int p = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		int& s = son[p][str[i] -'a'];
//		if (!s) s = ++idx;
//		p = s;
//	}
//	b[p][x] = 1;
//}
//
//void check()
//{
//	int sum = 0;
//	int p = 0;
//	int flag = 1;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		int s = son[p][str[i] - 'a'];
//		if (!s)
//		{
//			flag = 0;
//			break;
//		}
//		p = s;
//	}
//	if (flag)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if (b[p][i])
//			{
//				printf("%d ", i);
//			}
//		}
//	}
//	puts("");
//}
//int main()
//{
//	cin >> n;
//	getchar();
//	//v.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		int k = 0;
//		cin >> k;
//		for (int j = 1; j <= k; j++)
//		{
//			cin >> str;
//			insert(i);
//			
//		}
//
//	}
//
//	cin >> m;
//	while (m--)
//	{
//		cin >> str;
//		check();
//		//cout << endl;
//	}
//	system("pause");
//}


// 通配符匹配
//bool dpchar* s1, char* s2)
//{
//	int len1 = strlen(s1), len2 = strlen(s2);
//	f[0][0] = 1;
//	for (int i = 0; i < len1; i++)
//	{
//		if (s1[i] == '*')
//		{
//			if (i == 0)
//				f[1][0] = 1;
//			for (int j = 0; j < len2; j++)
//				f[i + 1][j + 1] |= f[i][j + 1] | f[i + 1][j];
//		}
//		else
//		for (int j = 0; j < len2; j++)
//		if (s1[i] == '?' || s1[i] == s2[j])
//			f[i + 1][j + 1] |= f[i][j];
//	}
//	if (!f[len1][len2])
//		return 1;
//	return 0;
//}






const int N = 1e5 + 1000;
int h[N], w[2 * N], e[N * 2], ne[2 * N], cnt;
int n;
int idx;
int son[N * 32][2];
int t[N];

void add(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[idx] = idx++;
}

void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int &c = son[p][x >> i & 1];
		if (!c) c = ++cnt;
		p = c;
	}
}

void dfs(int u, int father, int sum)
{
	t[u] = sum;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs(j, u, sum ^ w[i]);
		}
	}
}
int query(int n)
{
	int p = 0;
	int res1 = 0;
	
	for (int i = 30; ~i; i--)
	{
		int c = n >> i & 1;
		if (son[p][!c])
		{
			res1 += (1 << i);
			p = son[p][!c];
		}
		else
		{
			p = son[p][c];
		}
	}
	return res1;

}
int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	int tmp = n;
	while (--n)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	
	dfs(0, -1, 0);
	int res = 0;
	for (int i = 0; i < tmp; i++)
	{	
		insert(t[i]);
	}
	for (int i = 1; i <= tmp; i++)
	{
		res = max(res, query(t[i]));
	}
	cout << res << endl;
	system("pause");
}