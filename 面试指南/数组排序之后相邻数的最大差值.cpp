#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// Í°µÄË¼Ïë
int bucket(long num, long len, long min, long max)
{
	return ((num - min)*len / (max - min));
}
int maxGap(vector<int> nums)
{
	int len = nums.size();
	int max_ = INT_MIN;
	int min_ = INT_MAX;
	for (int i = 0; i < len; i++)
	{
		min_ = min(min_, nums[i]);
		max_ = max(max_, nums[i]);
	}
	if (min_ == max_)
		return 0;
	vector<bool> hasNum(len + 1, false);
	vector<int> maxs(len + 1);
	vector<int> mins(len + 1);
	int bid = 0;
	for (int i = 0; i < len; i++)
	{
		bid = bucket(nums[i],len,min_,max_);
		mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
		maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
		hasNum[bid] = true;
	}
	int res = 0;
	int	lastMax = 0;
	int i = 0;
	while (i <= len)
	{
		if (hasNum[i++])
		{
			lastMax = maxs[i - 1];
			break;
		}
	}
	for (; i <= len; i++)
	{
		if (hasNum[i])
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
		
	}
	return res;
}

int main()
{
	vector<int> arr = { 9, 3, 1, 10 };
	cout << maxGap(arr) << endl;
	system("pause");
}