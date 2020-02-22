#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct Comby
//{
//	bool operator() (pair<int, int>&l, pair<int, int>&r)
//	{
//		if (l.first == r.first)
//		{
//			return l.second < r.second;
//		}
//		return l.first < r.first;
//	}
//};
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<pair<int, int>>vp(n);
//		int time = 0;
//		for (int i = 0; i < n; i++)
//		{
//			int k = 0;
//			int j = 0;
//			cin >> k >> j;
//			vp[i].first = k;
//			vp[i].second = j;
//		}
//		cin >> time;
//		int hour = 0;
//		int second = 0;
//		cin >> hour >> second;
//		if (second >= time)
//		{
//			second -= time;
//		}
//		else
//		{
//			second = 60 - (time - second);
//			hour -= 1;
//		}
//		sort(vp.begin(), vp.end(), Comby());
//		auto it = vp.rbegin();
//		for (; it != vp.rend(); it++)
//		{
//			if (hour > (*it).first ||((hour==second)&&second >= (*it).second))
//			{
//				cout << (*it).first << " " << (*it).second << endl;
//				break;
//			}
//		}
//	}
//}

#include <iostream>
#include <map>
#include <set>

using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	map<int, pair<int, int>, greater<int>> clock;

	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		pair<int, int> temps({ a, b });
		clock.insert({ a * 60 + b, temps});
	}

	int x = 0;
	cin >> x;

	int at = 0;
	int bt = 0;
	cin >> at;
	cin >> bt;
	int time = at * 60 + bt - x;
	for (auto i : clock)
	{
		if (time >= i.first)
		{
			cout << i.second.first << " " << i.second.second << endl;
			break;
		}
	}
	return 0;
}