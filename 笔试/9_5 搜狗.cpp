#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

using namespace std;
// nums数组  数组长度 你自己用maxlen来表是就可以了， 我这里直接 nums.size()了啊
int main()
{
	vector<int> nums = { -1, 4, 5, 2, 7, 3 };
	vector<pair<double, double>> vp(nums.size() / 2);
	int idx = 0;
	for (int i = 0; i < nums.size(); i += 2)
	{
		vp[idx++] = { nums[i] - 1.0* nums[i + 1] / 2, nums[i] + 1.0*nums[i + 1] / 2 };
	}
	//cout << vp.size() << endl;
	sort(vp.begin(), vp.end()); // 就是按照左边界比， 不用重载 <


	for (int i = 0; i < vp.size(); i++)
	{
		cout << vp[i].first << " " << vp[i].second << endl;
	}
	if (vp.size() == 1)
	{
		// cout << 2 << endl;
		return 2;
	}
	int max_ = vp[0].second;
	int t = 2; // 接口参数中的t
	int sums = 0;

	for (int i = 1; i < vp.size(); i++)
	{
		if (vp[i].first - vp[i - 1].second > t)
		{
			sums += 2;
		}
		else if (vp[i].first - vp[i - 1].second == t)
		{
			sums += 1;
		}
	}
	cout << sums + 2 << endl;

	system("pause");
}