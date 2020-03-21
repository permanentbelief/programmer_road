#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// 数组累加和为定值的最长子数组长度。   O(N)
int getMaxLength(vector<int> arr, int aim)
{
	int L = 0;
	int R = 0;
	int sum = arr[0];
	int len = 0;
	while (R < arr.size())
	{
		if (sum == aim)
		{
			len = max(len, R - L + 1);
			sum -= arr[L--];
		}
		else if (sum < aim)
		{
			R++;
			if (R == arr.size())
				break;
			sum += arr[R]; 
		}
		else // sum < aim
		{
			sum -= arr[L++];
		}
	}
	return len;
}

//可正 可负数 可0 
int maxLength(vector<int>& arr, int aim)
{
	vector<int> sums(arr.size());
	vector<int> ends(arr.size());
	sums[arr.size() - 1] = arr[arr.size() - 1];
	ends[arr.size() - 1] = arr.size() - 1;

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		if (sums[i + 1] < 0)
		{
			sums[i] = arr[i] + sums[i + 1];
			ends[i] = ends[i + 1];
		}
		else
		{
			sums[i] = arr[i];
			ends[i] = i;
		}
	}

	int R = 0;  //扩到的右边界
	int sum = 0;
	int len = 0;
	for (int start = 0; start < arr.size(); start++)
	{
		while (R < arr.size() && sum + sums[R] <= aim)
		{
			sum += sums[R];
			R = ends[R] + 1;
		}
		sum -= R > start ? arr[start] : 0;
		len = max(len, R - start);
		R = max(R, start + 1);
	} 
	return len;
}