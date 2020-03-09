#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int knapsack(int N, int  W, vector<int>& wt, vector<int>& val)
{
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= W; w++)
		{
			if (w - wt[i - 1] < 0)
				dp[i][w] = dp[i - 1][w];
			else
				dp[i][w] = max(dp[i - 1][w - wt[i - 1]]+ val[i - 1],
				dp[i - 1][w]);
		}
	}
	return dp[N][W];
}
class Solution {
public:
	int rob(vector<int> nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int max_1 = 0;
		vector<int> v(nums.size());
		v[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) // i == 2的时候肯定加上 v[0]了
		{
			max_1 = 0;
			for (int j = 0; j < i - 1; j++)
			{
				max_1 = max(max_1, nums[i] + v[j]);
			}
			v[i] = max_1;
		}
		max_1 = v[nums.size() - 2];
		int max2_ = 0;
		for (int i = 1; i < nums.size(); i++) // i从3开始 只加v[i];
		{
			max2_ = 0;
			for (int j = 1; j < i - 1; j++)
			{
				max2_ = max(max2_, nums[i] + v[j]);
			}
			v[i] = max2_;
		}
		max2_ = v[nums.size() - 1];

		return max(max_1, max2_);

	}
};
int main()
{
	//int N = 3;
	//int W = 4;
	//vector<int> wt = { 2, 1, 3 };
	//vector<int> val = { 4, 2, 3 };

	//cout << knapsack(N, W, wt, val) << endl;
	Solution s;
	cout << s.rob({ 2,3,2 }) << endl;
	system("pause");
}