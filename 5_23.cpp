#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int quickSort1(vector<int>&arr, int left, int right)
{
	int key = arr[right];
	int k_index = right;
	while (left < right)
	{

		while (left < right && arr[left] <= key)
		{
			left++;
		}
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		swap(arr[left],arr[right]);
	}
	swap(arr[k_index], arr[left]);
	return left;
}
int quickSort(vector<int>&arr, int left, int right)
{
	int hole = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] <= hole)
		{
			left++;
		}
		arr[right] = arr[left];
		while (left < right && arr[right] >= hole)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[left] = hole;
	return left;

}
void QuickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = quickSort(arr,left,right);
	QuickSort(arr,left, mid - 1);
	QuickSort(arr,mid + 1, right);
}

void AdjustDown(vector<int>& arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
		{
			child++;
		}
		if (arr[child] <= arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void heapSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(arr[0],arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}


void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (arr[j - 1] >= arr[j])
			{
				swap(arr[j], arr[j - 1]);
			}
			else
				break;
		}
	}
}

void InsertSort1(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;
			arr[end + 1] = tmp;
		}
	}
}
void ShellSort(vector<int>& arr)
{
	int gap = arr.size() - 1;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < arr.size(); i++)
		{
			int end = i;
			while (end >= gap)
			{
				if (arr[end] < arr[end - gap])
				{
					swap(arr[end],arr[end-gap]);
				}
				else
				{
					break;
				}
				end -= gap;
			}
		}
	}
}
void Merge(vector<int>& v, int left, int mid ,int right)
{
	int l_low = left;
	int l_high = mid;
	int r_low = mid + 1;
	int r_high = right;
	int k = 0;
	vector<int> tmp(right - left + 1);
	while (l_low <= l_high && r_low <= r_high)
	{
		if (v[l_low] <= v[r_low])
		{
			tmp[k++] = v[l_low];
			l_low++;
		}
		else
		{
			tmp[k++] = v[r_low];
			r_low++;
		}
	}
	while (l_low <= l_high)
	{
		tmp[k++] = v[l_low];
		l_low++;
	}
	while (r_low <= r_high)
	{
		tmp[k++] = v[r_low];
		r_low++;
	}
	for (int i = 0; i < k; i++)
	{
		v[left + i] = tmp[i];
	}
}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);

	//
	Merge(arr, left, mid, right);
}
#include <ctime>
int main()
{
	srand(time(NULL));
	vector<int> arr(10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 30 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
	//QuickSort(arr, 0, 9);
	MergeSort(arr,0,9);
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
}