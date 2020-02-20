#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			int first = 0;
			int second = 0;
			cin >> first >> second;
			mp[first] = second;
		}
		vector<int>v(m);
		for (int i = 0; i < m; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < m; i++)
		{
			for (auto it = mp.rbegin(); it != mp.rend(); it++)
			{
				if (v[i] >= it->first)
				{
					cout << it->second << endl;
					break;
				}
			}
		}

	}
}

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct ByValue
{
	bool operator() (const pair<int, int>& l, const pair<int, int>& r)
	{
		if (l.second == r.second)
		{
			return l.first < r.first; //当second 一定时  < 是排升序   > 降序
		}
		return l.second < r.second; //  < 建大堆 降序
	}
};

int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		multimap<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			int first = 0;
			int second = 0;
			cin >> first >> second;
			mp.insert(make_pair(first, second));
		}
		vector<int>v(m);
		for (int i = 0; i < m; i++)
		{
			cin >> v[i];
		}
		priority_queue<pair<int,int>, vector<pair<int, int>>, ByValue> pq;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			pq.push(make_pair(it->first, it->second));
		}
		for (int i = 0; i < m; i++)
		{
			priority_queue<pair<int, int>, vector<pair<int, int>>, ByValue> ppq(pq);
			int n = ppq.size();
			for (int j = 0; j < n; j++)
			{
				if (v[i] >= ppq.top().first)
				{
					cout << ppq.top().second << endl;
					break;
				}
				else
				{
					ppq.pop();
				}
			}
		}
		/*int n = pq.size();
		for (int i = 0; i < n; i++)
		{
			cout << pq.top().first << ":" << pq.top().second<< endl;
			pq.pop();
		}
*/
		/*for (int i = 0; i < m; i++)
		{
			for (auto it = mp.rbegin(); it != mp.rend(); it++)
			{
				if (v[i] >= it->first)
				{
					cout << it->second << endl;
					break;
				}
			}
		}*/

	}
}