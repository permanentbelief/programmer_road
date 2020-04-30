#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int maxLengthAwesome(vector<int>& arr, int aim)
{
	if (arr.empty())
		return 0;
	vector<int> sums(arr.size());
	vector<int> ends(arr.size());

	// sums 和 ends数组的生成
	sums[arr.size() - 1] = arr[arr.size() - 1];
	ends[arr.size() - 1] = arr.size() - 1;
	for (int i = arr.size() - 2; i >= 0; i--)
	{
		if (sums[i + 1] < 0)
		{
			sums[i] = arr[i] + sums[i + 1];//如果sums[i+1]都是负数，那么sum[i]肯定能更小
			ends[i] = ends[i + 1]; //此时的ends[i]就是i+1位置能向右扩的最大距离
		}
		else
		{
			sums[i] = arr[i];
			ends[i] = i;
		}
	}

	//找最大值
	int R = 0;  // 扩到的右边界[0,R-1]R
	int sum = 0;  // 窗口内从start到end的累加和
	int len = 0; //全局最大值
	for (int start = 0; start < arr.size(); start++) // 扩不出去，就向后扩
	{
		while (R < arr.size() && sum + sums[R] <= aim)
		{
			sum += sums[R];
			R = ends[R] + 1;
		}
		//R > start 说明R在start的右边，此时已经>aim
		//所以要减去窗口左边的值，表示最左边的值出窗口了

		//R <= start. 窗口内就没有值
		sum -= R > start ? arr[start] : 0;
		len = max(len, R - start);
		R = max(R, start + 1);
	}
	return len;

}
//int main()
//{
//	
//	system("pause");
//}