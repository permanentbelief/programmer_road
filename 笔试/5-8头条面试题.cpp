#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 3, 4, 1, 5, 6, 2, 7 };
	stack<int> s;
	s.push(0);
	vector<int> prev(nums.size());
	vector<int> nexts(nums.size());
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[s.top()] <= nums[i])
		{
			s.push(i);
		}
		else
		{
			prev[i] = -1;
		}
	}
	while (!s.empty())
	{
		int tmp = s.top();
		s.pop();
		if (!s.empty())
		{
			prev[s.top()] = s.top();
		}
	}
	// nextsÊý×é
	s.push(nums.size() - 1);
	nexts[nexts.size() - 1] = -1; //..
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (nums[i] >= nums[s.top()])
		{
			nexts[i] = nums[s.top];
		}
		else
		{
			s.pop();
			s.push(i);
		}
	}



}