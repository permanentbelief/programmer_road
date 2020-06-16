//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <functional>
//using namespace std;
//
//
//
//typedef pair<int, int> PII;
//
//const int N = 100010;
////
////int h[N];
////int e[N];
////int ne[N];
////int idx = 0;
////int w[N];
////bool st[N];
////int dist[N];
////
////int n = 0;
////int m = 0;
////void add(int x, int y, int c)
////{
////	w[idx] = c;
////	e[idx] = y;
////	ne[idx] = h[x];
////	h[x] = idx++;
////}
////
////int dijkstra()
////{
////	memset(dist, 0x3f, sizeof(dist));
////
////	dist[0] = 1;
////	priority_queue<PII, vector<PII>, greater<PII>> heap;
////
////	heap.push({ 0, 1 });
////	while (heap.size())
////	{
////		PII k = heap.top();
////		heap.pop();
////
////		int ver = k.second;
////		int distance = k.first;
////
////		if (st[ver])
////			continue;
////		st[ver] = true;
////
////		for (int i = h[ver]; i != -1; i = ne[i])
////		{
////			int j = e[i];
////			if (dist[j] > distance + w[i])
////			{
////				dist[j] = distance + w[i];
////				heap.push({ dist[j], j });
////			}
////		}
////	}
////	if (dist[n] == 0x3f3f3f3f)
////		return -1;
////	else
////		return dist[n];
////}
////int main()
////{
////	memset(h, -1, sizeof(h));
////	scanf("%d%d", &n, &m);
////
////	while (m--)
////	{
////		int x, y, c;
////		scanf("%d%d%d", &x, &y, &c);
////		add(x, y, c);
////	}
////
////	cout << dijkstra() << endl;
////	system("pause");
////	return 0;
////}
//
//vector<vector<pair<int, int>>> gra;
//int dist[N];
//int st[N];
//int n = 0;
//int m = 0;
//
//int solve()
//{
//	memset(dist, 0x3f, sizeof(dist));
//	dist[1] = 0;
//
//	//这里是距离在前，节点号在后
//
//	priority_queue<PII, vector<PII>, greater<PII>> heap;
//
//	heap.push({ 0, 1 });
//
//	while (!heap.empty())
//	{
//		auto t = heap.top();
//		heap.pop();
//
//
//		int node = t.second;
//		int distance = t.first;
//
//		if (st[node])
//			continue;
//		st[node] = true;
//
//		for (int i = 0; i < gra[node].size(); i++)
//		{
//			int newnode = gra[node][i].first;
//			int len = gra[node][i].second;
//			if (dist[newnode] > dist[node] + len)
//			{
//				dist[newnode] = dist[node] + len;
//				heap.push({ dist[newnode], newnode });
//			}
//		}
//	}
//
//	if (dist[n] == 0x3f3f3f3f)
//		return -1;
//	return dist[n];
//}
//int main()
//{
//	//cin >> n >> m;
//	scanf("%d %d", &n, &m);
//	gra.resize(n + 1);
//
//	for (int i = 0; i < m; i++) {
//		int a, b, c;
//		//cin >> a >> b >> c;
//		scanf("%d %d %d", &a, &b, &c);
//		//这里是 目的节点号在前 边长在后
//		gra[a].push_back({ b, c });
//	}
//
//	printf("%d\n", solve());
//	system("pause");
//	return 0;
//}
//
