/*
A �� B ͬʱ�ҶԷ��� A���Ҫ���Ļ����� K^10 ,�������һ����5�Σ���ô����2*5^k��

������ �϶̵Ķ��У�һ�����������У�һ�������ѵ�ʱ��Ҫ��һ��

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;

const int N = 6; //����6���ַ�

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
	queue<string> qa, qb;  //��������
	unordered_map<string, int> da, db;       // ÿһ��bfs�ľ���
	qa.push(A);
	qb.push(B);
	da[A] = db[B] = 0;

	int step = 0;
	int t = 0;
	while (qa.size() && qb.size()) // ���һ������Ϊ�գ�������������޽�
	{
		if (qa.size() < qb.size()) t = extend(qa, da, db, a, b);  //��չqa���� ����da,db, �仯���ǰ�a�仯Ϊb
		else t = extend(qb, db, da, b, a);   //A��B��չ��ʱ��ʮ����߱�Ϊ�ұߣ�B��A��չ��ʱ���ǰ��ұ߱�Ϊ���

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


