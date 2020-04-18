#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void backTrack(vector<vector<double>>& num,vector<bool>&used, vector<int>& pre, vector<int>& cur,double curProfit, double&preProfit, int n, int pos)
{
	if (pos == n)
	{
		if (curProfit > preProfit)
		{
			preProfit = curProfit;
			pre = cur; //数组赋值,将这个最优解的数组赋值给pre
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			cur[pos] = i;
			curProfit += num[pos][i];
			used[i] = true;
			backTrack(num,used,pre,cur, curProfit, preProfit, n, pos + 1);
			curProfit -= num[pos][i];
			used[i] = false;
		}
	}
}
//int main()
//{
//	int n;
//    while (cin >> n)
//	{
//		vector<vector<double>> vvd(n, vector<double>(n));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> vvd[i][j];
//			}
//		}
//		vector<int> pre(n);
//		vector<int> cur(n);
//		vector<bool> used(n);
//		double preProfit = INT_MIN;
//		double curProfit = 0.0;
//		backTrack(vvd, used, pre, cur, curProfit, preProfit, n, 0);
//
//		cout << preProfit << endl;
//		for (int i = 0; i < pre.size(); i++)
//		{
//			cout << i + 1 << " " << pre[i] + 1 << endl;
//		}
//	}
//}