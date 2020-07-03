#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//int n = 0;
//int f[N];
//int cnt[N];
//#include <unordered_set>
//int find(int x)
//{
//	if (x == f[x])
//		return x;
//	return f[x] = find(f[x]);
//}
//void merge(int x, int y)
//{
//	if (find(x) == find(y))
//		return;
//	int a = find(x);
//	int b = find(y);
//	if (cnt[a] > cnt[b])
//	{
//		f[a] = b;
//		cnt[b] += cnt[a];
//	}
//	else
//	{
//		f[b] = a;
//		cnt[a] += cnt[b];
//	}
//}
//int main()
//{
//	cin >> n;
//	int max_cnt = 0;
//	int max_ = 0;
//	unordered_set<int> s;
//	int res = 0;
//	for (int i = 0; i < N; i++)
//	{
//		f[i] = i;
//		cnt[i] = 1;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int c;
//		cin >> c;
//		int d = 0; 
//		max_ = max(max_, c);
//		s.insert(c);
//		while (getchar() != '\n')
//		{
//			cin >> d;
//			max_ = max(max_, d);
//			s.insert(d);
//			merge(c, d );
//			
//		}
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		if (s.count(i))
//		{
//			max_cnt = max(max_cnt, cnt[i]);
//			if (f[i] == i)
//				res++;
//		}
//
//	}
//	cout << res << endl;
//	cout << max_cnt << endl;
//	system("pause");
//}



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



using namespace std;

const int M = 100003;
vector<int> E[M];
int indegree[M];

int main(){
	int n, m, u, v;
	cin >> n >> m;
	int r[20];
	for (int i = 0; i<m; i++){
		cin >> u >> v;
		E[v].push_back(u);
		indegree[u]++;
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; i++)
	if (!indegree[i])
		q.push(i);
	int k = n;
	while (!q.empty()){
		int p = q.top();
		q.pop();
		r[p] = k--;
		for (int i = 0; i<E[p].size(); i++){
			v = E[p][i];
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}
	for (int i = 1; i <= n; i++){
		if (i == n)
			cout << r[i] << endl;
		else
			cout << r[i] << " ";
	}
	return 0;
}