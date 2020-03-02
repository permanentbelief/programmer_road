#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int process1(vector<int>& arr, int index, int target)
{
	int res = 0;
	if (index == arr.size()) //递归层数 和 方越界
	{
		res = target == 0 ? 1 : 0;
	}
	else
	{
		for (int i = 0; arr[index] * i <= target; i++)
		{
			res += process1(arr, index + 1, target - arr[index] * i);
		}
	}
	return res;
}
int coins(vector<int> arr, int target)
{
	if (arr.size() == 0 || target < 0)
		return  0;
	return process1(arr, 0, target);
}
int main()
{
	vector<int> v = { 5,10 };
	int target = 10;
	cout << coins(v, target) << endl;
	system("pause");
}