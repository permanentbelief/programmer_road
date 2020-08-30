#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



using namespace std;
const int N = 1e3 + 500;

queue<int> q;
int d[N], mp[N][N];
int n, m;


void bfs()
{
	memset(d, -1, sizeof d);
	d[1] = 0;
	q.push(1);
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (mp[t][i] && d[i] < d[t] + mp[t][i])
			{
				// cout << d[i] << " " << endl;

				d[i] = d[t] + mp[t][i];
				q.push(i);
			}
		}
	}


}
int main()
{
	cin >> n >> m;
	int a, b, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> v;
		mp[a][b] = max(mp[a][b], v);
	}
	bfs();
	cout << d[n] << endl;
	system("pause");
}

/*


*/