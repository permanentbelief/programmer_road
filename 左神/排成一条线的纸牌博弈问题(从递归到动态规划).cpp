#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int second(vector<int>& arr, int i, int j);
int first(vector<int>& arr, int i, int j)
{
	if (i == j) //只有一张的情况下，先拿的就拿走
		return arr[i];
	return max(arr[i] + second(arr, i + 1, j), arr[j] + second(arr, i, j - 1));
}
int second(vector<int>& arr, int i, int j)
{
	if (i == j)
		return 0;
	return min(first(arr, i + 1, j), first(arr, i, j - 1));
}
int Win1(vector<int>& arr)
{
	if (arr.empty())
		return 0;
	return max(first(arr, 0, arr.size() - 1), second(arr, 0, arr.size() - 1));

}

int Win2(vector<int> arr)
{
	int n = arr.size();
	if (arr.empty())
		return 0;
	vector<vector<int>> f(n, vector<int>(n, 0));
	vector<vector<int>> s(n, vector<int>(n, 0));
	for (int i = n - 1; i >= 0; i--)
	{
		f[i][i] = i;
		for (int j = i + 1; j < n; j++)
		{
			f[i][j] = max(arr[j] + s[i][j - 1], arr[i] + s[i + 1][j]);
			s[i][j] = min(f[i + 1][j], f[i][j - 1]);
		}
	}
	return max(f[0][n - 1], s[0][n - 1]);
}


int main()
{
	vector<int> arr = { 1, 2, 3, 7 };
	cout << Win1(arr) << endl;
	cout << Win2(arr) << endl;

	system("pause");
}

int main()
{
	
	system("pause");
}