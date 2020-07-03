//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//#include <functional>
//using namespace std;
//
//
//const int  N = 510;
//int a[N];
//int n, m;
//int degree[N];
//bool visit[N];
//vector<int> v[N];
//
//int main()
//{
//	while (cin >> n >> m)
//	{
//
//		for (int i = 0; i < m; i++)
//		{
//			int n = 0;
//			int m = 0;
//			cin >> n >> m;
//			v[n].push_back(m);
//			degree[m]++;
//		}
//		priority_queue<int, vector<int>, greater<int>> q;
//		vector<int> res;
//		vector<int> tmp;
//		for (int i = 1; i <= n; i++)
//		{
//			if (degree[i] == 0)
//			{
//				q.push(i);
//				visit[i] = true;
//
//			}
//		}
//		/*
//		sort(tmp.begin(),tmp.end());
//		res = tmp;
//		tmp.clear();
//		*/
//		while (q.size())
//		{
//			int sz = q.size();
//			while (sz--)
//			{
//				auto tmp = q.top();
//				q.pop();
//				res.push_back(tmp);
//				for (int i = 0; i < v[tmp].size(); i++)
//				{
//					degree[v[tmp][i]]--;
//				}
//
//			}
//			for (int i = 1; i <= n; i++)
//			{
//				if (degree[i] == 0 && visit[i] != true)
//				{
//					q.push(i);
//					visit[i] = true;
//				}
//			}
//		}
//		for (auto e : res)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//		memset(v, 0, sizeof v);
//		memset(visit, false, sizeof visit);
//		memset(degree, false, sizeof degree);
//	}
//	system("pause");
//}