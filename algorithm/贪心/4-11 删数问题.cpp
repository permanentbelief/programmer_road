#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <map>


string removeKdigits(string nums, int k)
{
	vector<int> S;
	string results;
	for (int i = 0; i < nums.size(); i++) //从最高位循环扫描数字num
	{
		int number = nums[i] - '0';
		while (!S.empty() && S[S.size() - 1] > number && k > 0)
		{ 
			S.pop_back(); // 当栈不为空,栈顶的数number,仍可以删除
			k--;
		}
		if (number != 0 || S.size() != 0)
		{
			S.push_back(number);
		}
	}
	while (S.size() != 0 && k > 0) 
	{
		S.pop_back();
		k--;
	}
	for (int i = 0; i < S.size(); i++)
	{
		results += to_string(S[i]);
	}

	return results;
}
int main()
{
	int n = 0;
	int k = 0;
	while (cin >> n >> k)
	{
		cout << removeKdigits(to_string(n), k) << endl;
	}
}

