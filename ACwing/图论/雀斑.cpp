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
//typedef pair<double, double> PII;
//
//const int N = 101;
//int f[N];
//int find(int x)
//{
//	if (x == f[x])
//		return x;
//	return f[x] = find(f[x]);
//}
//
//typedef struct Edge
//{
//	int a, b;
//	double distance;
//}Edge;
//
//typedef struct Point
//{
//	double x, y;
//}Point;
//
//int cmp(Edge& a, Edge& b)
//{
//	return a.distance < b.distance;
//}
//
//double Get(Point& a, Point& b)
//{
//	return sqrt(pow(b.y - a.y, 2) + pow(b.x - a.x, 2));
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		Point p[N];
//		Edge e[(N - 1)*N / 2];
//		int i = 0;
//		for (i = 1; i <= n; i++)
//		{
//			cin >> p[i].x >> p[i].y;
//		}
//		int size = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = i + 1; j <= n; j++)
//			{
//				e[size].a = i;
//				e[size].b = j;
//				e[size++].distance = Get(p[i], p[j]);
//			}
//		}
//		sort(e, e + size, cmp);
//		for (int i = 1; i <= n; i++)
//		{
//			f[i] = i;
//		}
//		int a, b;
//		double d = 0.0;
//		for (int i = 0; i < size; i++)
//		{
//			a = find(e[i].a);
//			b = find(e[i].b);
//			if (a != b)
//			{
//				f[a] = b;
//				d += e[i].distance;
//			}
//		}
//		printf("%.2lf\n",d);
//	}
//	system("pause");
//}