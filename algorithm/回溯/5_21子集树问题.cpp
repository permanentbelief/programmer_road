//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//#include <unordered_map>
//using namespace std;
//
//
//
//// 也就是求子集和最接近
//
//void dfs(vector<int>&v, int Sum , int&outs, int c , int cur)
//{
//	if (Sum > c) // 剪枝
//		return;
//	// cout << Sum << endl;
//	outs = c >= Sum ? min(outs, c - Sum) : outs;
//
//	for (int i = cur; i < v.size(); i++)
//	{
//		Sum += v[i];
//		dfs(v, Sum, outs, c, i + 1);
//		Sum -= v[i];
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int c = 0;
//	while (cin >> n >> c)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		int count = INT_MAX;
//		dfs(v, 0, count , c, 0);
//		//if (count == INT_MAX)
//			//cout << 0 << endl;
//		cout << c - count << endl;
//	}
//}