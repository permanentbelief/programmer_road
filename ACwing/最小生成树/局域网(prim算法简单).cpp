#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#include <iostream>
#include <cstring>
const int N = 110;

int dis[N];
int g[N][N];
int n, k;
bool st[N];
using namespace std;


int prim()
{
	memset(dis, 0x3f3f3f3f, sizeof dis);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dis[j] < dis[t]))
				t = j;
		}
		// if(t == -1) break;

		st[t] = true;
		if (i &&  dis[t] < 0x3f3f3f3f)  res += dis[t];    //  cout << res << endl;

		for (int j = 1; j <= n; j++)
		{
			dis[j] = min(dis[j], g[t][j]);
		}
	}

	return res;
}


int main()
{
	cin >> n >> k;

	int res = 0;
	int total = 0;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= k; i++)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
		total += c;
	}
	for (int i = 1; i <= n; ++i) g[i][i] = 0;

	cout << total - prim() << endl;

}
