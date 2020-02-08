#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void LeftUnique(vector<int>& arr)
{
	int u = 0;
	int i = 1;
	while (i != arr.size())
	{
		if (arr[i] != arr[u])
		{
			swap(arr[++u],arr[i]); 
		}
		i++;
	}
}

void sort(vector<int>& arr)
{
	int mid = 0;
	int left = -1;
	int right = arr.size();
	while (mid < right)
	//{
		if (arr[mid] == 0)
		{
			swap(arr[++left], arr[mid++]);
		}
		else if (arr[mid] == 2)
		{
			swap(arr[--right], arr[mid]);
		}
		else
			mid++;
	}
}
int main()
{
	vector<int> arr = { 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9 };
	LeftUnique(arr);
	vector<int> arr1 = { 1, 2, 0, 2, 1, 0 };
	sort(arr1);
	for (auto e : arr1)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
}