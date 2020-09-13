#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 10000;

int h[N], e[2 * N], ne[2 * N], w[2 * N];
int idx;

int dis[N];
bool st[N];
int _ss;
int _end;

typedef pair<int, int> PII;
void add(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}


int dijkstra()  // dijkstra °å×Ó
{
	memset(dis, 0x3f, sizeof dis);
	dis[_ss] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({ 0, 1 });

	while (q.size())
	{
		auto t = q.top();
		q.pop();

		int ver = t.second;
		int distance = t.first;
		if (st[ver]) continue;

		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dis[j] > distance + w[i])
			{
				dis[j] = distance + w[i];
				q.push({ dis[j], j });
			}
		}
	}

	return dis[_end];
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	string start_time;
	cin >> _ss >> _end;
	cin >> start_time;

	int k = dijkstra();
	//cout << k << endl;

	int d = start_time.find('/');
	string month = start_time.substr(0, d);
	string day = start_time.substr(d + 1);

	int time = stoi(day) + k;

	int next = 0;

	if (time >= 24)
	{
		next = time / 24;
	}
	int months = 0;

	time %= 24;
	int monthss[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int point = month.find('.');

	string m = month.substr(0, point);
	int mm = stoi(m);
	string ddd = month.substr(point + 1);
	int dd = stoi(ddd);

	dd += next;
	if (dd > monthss[mm])
	{
		mm++;
		dd = 1;
	}
	cout << mm << "." << dd << "/" << time << endl;

}