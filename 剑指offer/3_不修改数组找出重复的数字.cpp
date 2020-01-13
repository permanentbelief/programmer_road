#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countRange(vector<int>& arr, int start, int end)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= start && arr[i] <= end)
			count++;
	}
	return count;
}
 只是二分的思想 与二分查找题目无关，也就是不要求数组有序，因为用不到arr[] 取数组的值。
int GetDuplication(vector<int> arr)
{
	int right = arr.size() - 1;
	int left = 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count = countRange(arr, left, mid);
		if (left == right)
		{
			if (count > 1)
				return left;
			else
				break;
		}
		if (count > (mid - left + 1))
			right = mid;
	
		else
			left = mid + 1;
		
	}
	return -1;
}
int main()
{
	//cout << Unique({ 2, 3, 1, 0, 2, 5, 3 });
	cout << GetDuplication({ 2, 3, 5, 4, 3, 2, 6, 7 }) <<endl;
	system("pause");
}

