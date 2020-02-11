

#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int missNum(vector<int> arr)
{
	int l = 0;
	int r = arr.size();
	while (l < r)
	{
		if (arr[l] == l + 1)
			l++;
		else if (arr[l] <= l || arr[l] > r || arr[arr[l] - 1] == arr[l])
		{
			arr[l] = arr[--r];
		}
		else
		{
			swap(arr[l], arr[arr[l] - 1]);
		}
	}
	return l + 1;
}
int main()
{
	vector<int> arr = { 1,2,3, 4, 5, 7, 9, 10 };
	cout << missNum(arr) << endl;
	system("pause");
}