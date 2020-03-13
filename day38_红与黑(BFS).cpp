#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct node
{
	int x;
	int y;
};

int BFS(vector<vector<char>>& v, vector<vector<bool>>& visit, node& start)
{
	queue<node> q;
	q.push(start);
	int count = 0;
	int m = v.size();
	int n = v[0].size();

	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

	visit[start.x][start.y] = true;
	++count;

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();
		node next;
		for (int i = 0; i < 4; i++)
		{

			next.x = cur.x + pos[i][0];
			next.y = cur.y + pos[i][1];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y <n
				&& visit[next.x][next.y] == false && v[next.x][next.y] == '.')
			{
				q.push(next);
				visit[next.x][next.y] = true;
				++count;
			}
		}
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	while (cin >> m >> n)
	{
		vector<vector<char>> v(m, vector<char>(n, 0));
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		node start;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					start.x = i;
					start.y = j;
				}
			}
		}
		cout << BFS(v, visit, start) << endl;

	}
}