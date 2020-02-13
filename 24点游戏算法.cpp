#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void Check24(const vector<int>& nums, int index, double result, bool &isSuccess)
{
	if (index == 4)
	{
		if (abs(result - 24) < 1e-6)
			isSuccess = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:Check24(nums, index + 1, result + nums[index], isSuccess);
			break;
		case 1:Check24(nums, index + 1, result - nums[index], isSuccess);
			break;
		case 2:Check24(nums, index + 1, result * nums[index], isSuccess);
			break;
		case 3:Check24(nums, index + 1, result / nums[index], isSuccess);
			break;
		}
	}
}

int main()
{
	vector<int> nums(4, 0);
	while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3])
	{
		sort(nums.begin(), nums.end());
		bool isSuccess = false;
		do
		{
			Check24(nums, 0, 0, isSuccess);
			if (isSuccess)
				break;
		} while (next_permutation(nums.begin(), nums.end()));
		if (isSuccess)
			cout << "true" << endl;
		else
			cout << "false" << endl;

	}
	system("pause");

}
