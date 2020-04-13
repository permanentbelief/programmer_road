#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


/*
蚂蚁森林之王
最长距离
*/

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n);
		map<int, int> mymap;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 0)
			{
				nums[i]++;
			}
			else
			{
				if ( v[i] - 1 < i)
					nums[v[i]-1]++;
					
				nums[i]++;
			}

		}
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << endl;
		}
		
		
	}
}
