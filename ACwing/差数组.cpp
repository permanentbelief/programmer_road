#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
using namespace std;


//
//const int N = 100004;
//int a[N];
//int b[N];
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		a[i] = 1;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		b[n] = a[n] - a[n - 1];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int num = 0;
//		int l = 0;
//		int r = 0;
//		cin >> num;
//		if (num == 2)
//		{
//			cin >> l;
//			cout << a[l - 1] + b[l] << endl;
//		}
//		else if (num == 1)
//		{
//			cin >> l >> r;
//			b[l] ^= 1;
//			b[r + 1] ^= 1;
//		}
//	}
//	system("pause");
//}

#include <iostream>
using namespace std;

const int N = 10000005;


int a[N];


void merge(int a[], int left, int right)
{
	const int n = right - left + 1;
	int b[N];
	int mid = (left + right) / 2;

	int l = left;
	int r = mid + 1;
	int index = 0;
	while (l <= mid && r <= right)
	{
		if (a[l] < a[r])
		{
			b[index++] = a[l++];
		}
		else
			b[index++] = a[r++];
	}
	while (l <= mid)
		b[index++] = a[l++];
	while (r <= right)
		b[index++] = a[r++];

	for (int i = left; i <= right; i++)
	{
		a[i] = b[i - left];
	}
}
void MergeSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);
	merge(a, mid, right);

}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	MergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}