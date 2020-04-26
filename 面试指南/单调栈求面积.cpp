#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



int maxRecFromBottom(vector<int> height)
{
	if (height.empty())
		return 0;
	stack<int> s;
	int maxArea = 0;
	for (int i = 0; i < height.size(); i++)
	{
		while (!s.empty() && height[i] <= height[s.top()])
		{
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (i - k - 1)*height[j];
			maxArea = max(curArea, maxArea);
		}
		s.push(i);
	}
	while (!s.empty())
	{
		int j = s.top();
		s.pop();
		int k = s.empty() ? -1 : s.top();
		int curArea = (height.size() - k - 1)* height[j];
		maxArea = max(maxArea, curArea);
	}
	return  maxArea;
}
int main()
{
	vector<int> v = { 4, 3, 2, 6, 7 };
	cout << maxRecFromBottom(v) << endl;
	system("pause");
}
