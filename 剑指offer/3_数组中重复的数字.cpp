#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int Unique(vector<int> nums)
{

	if (nums.empty() || nums.size() == 1)
	{
		return  -1;
	}
	sort(nums.begin(), nums.end());
	int prev = 0;
	int cur = 1;
	while (cur < nums.size())
	{
		if (nums[prev] == nums[cur])
			return nums[prev];
		prev++;
		cur++;
	}
}

// ÊéÉÏµÄ
bool duplicate(vector<int> number)
{
	if (number.empty())
		return false;
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] < 0 && number[i] > number.size() - 1)
			return false;
	}
	for (int i = 0; i < number.size(); i++)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
				return true;
			swap(number[i], number[number[i]]);
		}

	}
	return false;
}
int main()
{
	//cout << Unique({ 2, 3, 1, 0, 2, 5, 3 });
	cout << duplicate({ 2, 3, 1, 4, 1 });
	system("pause");
}