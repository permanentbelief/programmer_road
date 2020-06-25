/*
A 和 B 同时找对方， A如果要扩的话就是 K^10 ,如果两边一起搜5次，那么就是2*5^k的

优先搜 较短的队列，一共有两个队列，一个队列搜的时候要搜一层

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;

const int N = 6; //至多6个字符

int n;
string A;
string B;
string a[N], b[N];


int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[N], string b[N])
{
	int d = da[q.front()];
	while (q.size() && da[q.front()] == d)
	{
		auto t = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t.size(); j++)
			{
				if (t.substr(j, a[i].size()) == a[i])
				{
					string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
					if (db.count(r)) return da[t] + db[r] + 1;
					if (da.count(r)) continue;
					da[r] = da[t] + 1;
					q.push(r);
				}
			}
		}
	}
	return  11;
}


int bfs()
{
	queue<string> qa, qb;  //两个队列
	unordered_map<string, int> da, db;       // 每一个bfs的距离
	qa.push(A);
	qb.push(B);
	da[A] = db[B] = 0;

	int step = 0;
	int t = 0;
	while (qa.size() && qb.size()) // 如果一个队列为空，则就是搜完了无解
	{
		if (qa.size() < qb.size()) t = extend(qa, da, db, a, b);  //扩展qa队列 距离da,db, 变化的是把a变化为b
		else t = extend(qb, db, da, b, a);   //A到B扩展的时候十八左边变为右边，B到A扩展的时候是把右边变为左边

		if (t <= 10) return t;
		if (++step == 10) return -1;
	}
	return -1;
}
int main()
{
	cin >> A >> B;
	while (cin >> a[n] >> b[n]) n++;
	int t = bfs();
	if (t == -1)
		puts("NO ANSWER!");
	else
		cout << t << endl;
}


