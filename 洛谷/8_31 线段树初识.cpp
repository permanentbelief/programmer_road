#define _CRT_SECURE_NO_WARNINGS 1 



#include <iostream>
#include <algorithm>

#include <cstdio>

using namespace std;
//
//const int N = 1e5 + 5;
//
//int tree[N << 2];
//
//void bulidTree(int node, int lef, int rig)
//{
//	if (lef == rig)
//		scanf("%d", &tree[node]);
//	else
//	{
//		int leftNode = node << 1;
//		int rightNode = node << 1 | 1;
//		int mid = (lef + rig) >> 1;
//		bulidTree(leftNode, lef, mid);
//		bulidTree(rightNode, mid + 1, rig);
//		tree[node] = max(tree[leftNode], tree[rightNode]);
//	}
//}
//
//int queryTree(int node, int lef, int rig, int L, int R)
//{
//	if (L <= lef && rig <= R)
//		return tree[node];
//	int leftNode = node << 1;
//	int rightNode = node << 1 | 1;
//	int mid = (lef + rig) >> 1;
//	int maxv = -0x3f3f3f3f;
//	if (L <= mid)
//		maxv = max(maxv, queryTree(leftNode, lef, mid, L, R));
//	if (R > mid)
//		maxv = max(maxv, queryTree(rightNode, mid + 1, rig, L, R));
//	return maxv;
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	bulidTree(1, 1, n);
//
//	while (m--)
//	{
//		int l, r;
//		scanf("%d %d", &l, &r);
//		printf("%d\n", queryTree(1, 1, n, l, r));
//	}
//	system("pause");
//	return 0;
//}







using namespace std;

const int N = 1e5 + 1000;
typedef pair<int, int> PII;
PII a[N];
int score[N];
int last[N];
bool st[N];

int n, m, T;

int main()
{
	cin >> n >> m >> T;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a + 1, a + m + 1);
	// int i = 0;
	// int j = 0;
	for (int i = 1; i <= m;)
	{
		int j = i;
		while (j <= m && a[i] == a[j]) j++;

		
		int t = a[i].first;
		int s = a[i].second;
		int cnt = j - i;
		i = j;

		score[s] -= (t - last[s] - 1);
		if (score[s] < 0) score[s] = 0;
		if (score[s] <= 3) st[s] = false;

		score[s] += 2 * cnt;
		if (score[s] > 5)
		{
			st[s] = true;
		}
		last[s] = t;
	}
	for (int i = 1; i <= n; i++)
	{
		if (last[i] < T)
		{
			score[i] -= T - last[i];
			if (score[i] <= 3)
				st[i] = false;
		}

	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += st[i];
	}
	cout << res << endl;
	system("pause");
}





