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
////  ����һ��
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
//// ������
//
//
////void dfs(vector<vector<int>>& nums, vector<bool>& used, vector<int>& pre
////	, vector<int>&cur, int curProfit, int &preProfit, int n, int pos)
////{
////	if (pos == n) // pos == n˵�� n��ȫ�����Ѿ�����
////	{
////		if(curProfit > preProfit)
////		{
////			preProfit = curProfit;
////			pre = cur; // ���Ž������  
////		}
////		return;
////	}
////	for (int i = 0; i < n; i++)
////	{
////		if (used[i] == false) // ��ǵ�i�У���һ��i�оͲ�����ѡ����
////		{
////			cur[pos] = i; // ���ÿһ��pos��Ӧ������i
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
////		vector<int> pre(n); // ��¼���Ž��ÿ��ֵ���ڵ�����
////		vector<int>cur()
////	}
////}