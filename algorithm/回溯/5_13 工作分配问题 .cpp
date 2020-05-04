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
//
////  方法一：
//void dfs(vector<vector<int>>& vv,vector<int>& v, int& maxSum, int cur)
//{
//	if (cur == v.size())
//	{
//		int tempSum = 0;
//		for (int i = 0; i < v.size(); i++)
//		{
//			tempSum += vv[i][v[i]];
//		}
//		maxSum = min(maxSum, tempSum);
//		return;
//	}
//	for (int i = cur; i < v.size(); i++)
//	{
//		swap(v[i],v[cur]);
//		dfs(vv,v,maxSum,cur+1);
//		swap(v[i],v[cur]);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<vector<int>> vv(n, vector<int>(n)); 
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> vv[i][j];
//			}
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			v[i] = i;
//		}
//		int sum = INT_MAX;
//		dfs(vv,v,sum,0);
//		cout << sum << endl;
//	}
//	system("pause");
//}
///*
//3
//10 2 3
//2 3 4
//3 4 5
//*/
//
//// 方法二
//
//
////void dfs(vector<vector<int>>& nums, vector<bool>& used, vector<int>& pre
////	, vector<int>&cur, int curProfit, int &preProfit, int n, int pos)
////{
////	if (pos == n) // pos == n说明 n行全部都已经用完
////	{
////		if(curProfit > preProfit)
////		{
////			preProfit = curProfit;
////			pre = cur; // 最优解的数组  
////		}
////		return;
////	}
////	for (int i = 0; i < n; i++)
////	{
////		if (used[i] == false) // 标记第i列，下一次i列就不能再选择了
////		{
////			cur[pos] = i; // 标记每一个pos对应的列数i
////			curProfit += nums[pos][i];
////			used[i] = true;
////			dfs(nums,used,pre,cur, curProfit, preProfit, n , pos+1);
////			curProfit -= nums[pos][i];
////			used[i] = false;
////		}
////	}
////}
////int main()
////{
////	int n = 0;
////	while (cin >> n)
////	{
////		vector<vector<int>> vv(n, vector<int>(n));
////		for (int i = 0; i < n; i++)
////		{
////			for (int j = 0; j < n; j++)
////			{
////				cin >> vv[i][j];
////			}
////		}
////
////		vector<int> pre(n); // 记录最优解的每个值所在的列数
////		vector<int>cur()
////	}
////}